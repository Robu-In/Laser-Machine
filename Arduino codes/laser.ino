#include <ESP32Servo.h>//intall this library if you are using ESP 32 
const int pinLaser = 2; // output signal pin of laser module/laser pointer
Servo servo1;
Servo servo2;
int joyX = A0;//Joystick module VRx pin ->Arduino A0
int joyY = A1;  //Joystick module VRy pin ->Arduino A1
  
int servoVal;
  
void setup() 
{ 
  pinMode(pinLaser, OUTPUT);
  digitalWrite(pinLaser, HIGH); // emit red laser
  servo1.setPeriodHertz(50); // standard 50 Hz servo
  servo1.attach(5, 500, 2500); // D5 for servo1

  servo2.setPeriodHertz(50);
  servo2.attach(3, 700, 2500); // D3 for servo2
}
  
void loop()
{
  
  servoVal = analogRead(joyX);
  servoVal = map(servoVal, 0, 4095, 0, 180);
  servo1.write(servoVal);

  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 4095, 0, 180);
  servo2.write(servoVal);
  delay(15);  
}

