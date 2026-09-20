int Pin1 = 9;
int Pin2 = 10;
int Pin3 = 11;
int Pin4 = 12;

int _step = 0;
boolean dir = false;

// Stepper direction timing
unsigned long lastFlip = 0;
const unsigned long flipInterval = 2200;

// LED timing
unsigned long lastLED = 0;
const unsigned long ledInterval = 200;

int ledCount = 0;
boolean ledState = false;
boolean ledsRunning = true;


void setup() {

  // LEDs
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);

  // Stepper
  pinMode(13, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);

  // Turn stepper ON
  digitalWrite(13, HIGH);

  // LEDs initially OFF
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
}


void loop() {

  // =================================
  // STEPPER MOTOR
  // =================================

  if (millis() - lastFlip >= flipInterval) {
    dir = !dir;
    lastFlip = millis();
  }

  switch (_step) {

    case 0:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, HIGH);
      break;

    case 1:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, HIGH);
      break;

    case 2:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, LOW);
      break;

    case 3:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, LOW);
      break;

    case 4:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      break;

    case 5:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      break;

    case 6:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      break;

    case 7:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, HIGH);
      break;
  }

  // Move to next step
  if (dir) {
    _step++;
  } else {
    _step--;
  }

  if (_step > 7) {
    _step = 0;
  }

  if (_step < 0) {
    _step = 7;
  }


  // =================================
  // LEDS
  // =================================

  if (ledsRunning && millis() - lastLED >= ledInterval) {

    lastLED = millis();

    if (ledState == false) {

      // Pin 7 ON
      digitalWrite(7, HIGH);
      digitalWrite(5, LOW);

      ledState = true;

    } else {

      // Pin 7 OFF, Pin 5 ON
      digitalWrite(7, LOW);
      digitalWrite(5, HIGH);

      ledState = false;

      ledCount++;

      // Stop LEDs after 10 cycles
      if (ledCount >= 10) {

        ledsRunning = false;

        digitalWrite(7, LOW);
        digitalWrite(5, LOW);
      }
    }
  }

  delay(1);
}
