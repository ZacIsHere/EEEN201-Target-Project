void setup() {
  // put your setup code here, to run once:
  // set pin 13 to input into arduino and 12 to output
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read pin 13
  int input = analogRead(A0);
  hit(input);
}

void hit(int input){
  	if (input >= 1000){
      int time = 0;
      float interval = 2.55;
      float green = (float)255;
      float red = (float)0;
      while(time < 100){
        
        analogWrite(11, red);
        analogWrite(10, green);
        green -= interval;
        red += interval;
        time += 1;
        delay(20);
      }
     /* analogWrite(11, 1000);
      analogWrite(10, 0);
     delay(1000);
     analogWrite(11, 0);
     analogWrite(10, 1000);
   }else{
     analogWrite(11, 0);
     analogWrite(10, 1000);*/
  }
}