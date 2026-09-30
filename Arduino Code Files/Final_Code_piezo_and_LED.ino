int red_delay = 100;
int LED_switch = 700;
int x_times = 8;

void setup() {
  // put your setup code here, to run once:
  // set pin 13 to input into arduino and 12 to output
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read pin 13
  int input = digitalRead(13);
  // if pin 13 is high then output high for x seconds
  hit(input);
}

void hit(int input){
  	if (input == HIGH){
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      flash();
      delay(LED_switch);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    // else output low
   }else{
     digitalWrite(10, LOW);
     digitalWrite(11, HIGH);
   }
}

void flash(){
    for(int i = 0; i <= x_times; i++){
      digitalWrite(10, LOW);
      delay(red_delay);
      digitalWrite(10, HIGH);
      delay(red_delay);
    }
}