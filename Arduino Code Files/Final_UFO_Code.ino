#include <AccelStepper.h>
#include <Servo.h>

// ---------- LED timing ----------
const unsigned long red_delay = 50;             // ms per half-cycle -> 10 flashes per second

// ---------- Stepper settings (half-step: 4096 steps/rev) ----------
const long SWEEP = 512;                         // 45 degrees in half-steps
AccelStepper stepper(AccelStepper::HALF4WIRE, 5, 7, 6, 8);   // IN1, IN3, IN2, IN4
int stage = 0;                                  // 0 idle, 1 -> +45, 2 -> -45, 3 -> center

// ---------- Servo settings ----------
const int SERVO_PIN   = 3;
const int SERVO_VALUE = 120;
Servo servo;

// ---------- LED state machine ----------x`
enum LedState { IDLE, FLASHING };
LedState ledState = IDLE;
unsigned long ledTimer = 0;

void setup() {
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  stepper.setMaxSpeed(900);                     // half-steps/s (about 13 RPM)
  stepper.setAcceleration(1500);                // half-steps/s^2
  stepper.setCurrentPosition(0);                // current position = center

  servo.attach(SERVO_PIN);
  servo.write(SERVO_VALUE);
}

void loop() {
  updateLeds(digitalRead(13));
  updateStepper();
}

void updateStepper() {
  if (stage == 0) return;

  stepper.run();

  if (stepper.distanceToGo() == 0) {
    if (stage == 1)      { stage = 2; stepper.moveTo(-SWEEP); }
    else if (stage == 2) { stage = 3; stepper.moveTo(0); }
    else                 { stage = 0; stepper.disableOutputs(); }
  }
}

void updateLeds(int input) {
  unsigned long now = millis();

  switch (ledState) {
    case IDLE:
      if (input == HIGH) {
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        ledTimer = now;
        ledState = FLASHING;
        stage = 1;                              // start the sweep
        stepper.moveTo(SWEEP);
      }
      break;

    case FLASHING:
      // flash for as long as the motor is moving
      if (now - ledTimer >= red_delay) {
        ledTimer = now;
        digitalWrite(10, !digitalRead(10));
      }
      if (stage == 0) {                         // motor finished, reset LEDs
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        ledState = IDLE;
      }
      break;
  }
}