#include <Servo.h>
#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <Wire.h>

//float time;
//float kP=0,kI=0,kD=0;
//float derivitive, intergral, output;

//int leftDrivePin=3,rightDrivePin=4;
//Servo leftDrive,rightDrive;

float angles[3];
FreeSixIMU sixDOF = FreeSixIMU();

void setup() { 
//  leftDrive.attach(leftDrivePin); //0-90
//  rightDrive.attach(rightDrivePin); //90-0
  Serial.begin(9600);
  Wire.begin();
  delay(5);
  sixDOF.init();
  delay(5);
}

void loop() { 
//  float dt = millis()-time;

  sixDOF.getEuler(angles);
  Serial.println(angles[1]);
  delay(80);
//  derivitive = (angles[1]-angle)/dt;
//  float angle = angles[1];
  
//  integral += dt*angle;
//  output = angle*kP+integral*kI+derivitive*kD;
//  drive(output);
//  time=millis();
}

//void drive(float output){
//  leftDrive.write(output);
//  rightDrive.write(output);
//}

