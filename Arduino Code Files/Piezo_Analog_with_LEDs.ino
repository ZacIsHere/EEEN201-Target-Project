void setup() {
  // put your setup code here, to run once:
  // set pin 13 to input into arduino and 12 to output
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(12, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read pin 13
  int input = analogRead(A0);
  hit(input);
  // if pin 13 is high then output high for x seconds
  
}

void hit(int input){
  	if (input >= 1000){
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
     delay(500);
     digitalWrite(10, LOW);
     digitalWrite(11, HIGH);
    // else output low
   }else{
     digitalWrite(10, LOW);
     digitalWrite(11, HIGH);
  }
}