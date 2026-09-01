void setup() {
  // put your setup code here, to run once:
  // set pin 13 to input into arduino and 12 to output
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read pin 13
  int input = analogRead(A0);
  // if pin 13 is high then output high for x seconds
  if (input > 10){
    digitalWrite(12, HIGH);
    delay(3000);
    // else output low
  }else{
    digitalWrite(12, LOW);
  }
}