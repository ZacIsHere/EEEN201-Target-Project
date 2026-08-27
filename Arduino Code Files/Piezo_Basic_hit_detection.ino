void setup() {
  // put your setup code here, to run once:
  // set pin 13 to input into arduino and 12 to output
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read pin 13
  int input = digitalRead(13);
  // if pin 13 is high then output high for x seconds
  if (input == HIGH){
    digitalWrite(12, HIGH);
    delay(3000);
    // else output low
  }else{
    digitalWrite(12, LOW);
  }
}

