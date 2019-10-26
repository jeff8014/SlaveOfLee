#include<Servo.h> 

Servo sg90;               //servo instance
const int PIN_SERVO = 12;
const int PIN_DC_A = 10;
const int PIN_DC_B = 11;
const int PIN_LED = 9;
const int CW = 0;         //Clock Wise
const int CCW = 1;        //Counter Clock Wise
 
void setup() 
{ 
  /* initiate servo motor */
  sg90.attach(PIN_SERVO);   

  /* initiate DC motor */
  pinMode(PIN_DC_A, OUTPUT); 
  pinMode(PIN_DC_B, OUTPUT);
} 
 
void turnDCMotor(int second, int direction) {
  if (direction == CW) {  
    digitalWrite(PIN_DC_A, LOW);
    digitalWrite(PIN_DC_B, HIGH);
    delay(second * 1000);
  }
  else {    //CCW
    digitalWrite(PIN_DC_A, HIGH);
    digitalWrite(PIN_DC_B, LOW);
    delay(second * 1000);
  }

  /*stop motor */
  digitalWrite(PIN_DC_A, LOW);
  digitalWrite(PIN_DC_B, LOW);
  delay(100);
}
void turnServoMotor(int pos) {
  static int prev_pos = 0;  //prev motor position
  int servo_pos = 0;    //position(degree) of servo motor
  if (prev_pos < pos) {
    for(servo_pos = prev_pos; servo_pos < pos; servo_pos++) { 
      sg90.write(servo_pos);
      delay(15); 
    } 
  }
  else {
    for(servo_pos = prev_pos; servo_pos>=pos; servo_pos--) { 
      sg90.write(servo_pos); 
      delay(15); 
    } 
  }
  prev_pos = pos;
  
}
void turnLED(int second) {
  digitalWrite(PIN_LED, HIGH);
  delay(second * 1000);
  digitalWrite(PIN_LED, LOW);
  delay(20);
}
void loop() 
{ 
  
}