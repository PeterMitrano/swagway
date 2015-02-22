#include <Servo.h>

int potPin = 15;
int rightMotorPin = 3;
int leftMotorPin = 5;

Servo rightMotor;
Servo leftMotor;

void setup(){
  pinMode(potPin,INPUT);
  Serial.begin(9600);
  rightMotor.attach(rightMotorPin);
  leftMotor.attach(leftMotorPin);  
}

void loop(){
  int i;
  for (i=90;i<180;i++){
    rightMotor.write(i);
    leftMotor.write(180-i);
    delay(40);
  }

  for (i=180;i>0;i--){
    rightMotor.write(i);
    leftMotor.write(180-i);
    delay(40);
  }

  for (i=0;i<90;i++){
    rightMotor.write(i);
    leftMotor.write(180-i);
    delay(40);
  }


}



