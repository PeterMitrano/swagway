#include <Servo.h>
#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <Wire.h>

float time;
float kP=0.033,kI=0,kD=0;
float derivitive;
float integral;
float output;
float angle;

int leftDrivePin=3;
int rightDrivePin=5;
Servo leftDrive,rightDrive;

int potPin = 15;

float angles[3];
FreeSixIMU sixDOF = FreeSixIMU();

void setup() { 
  pinMode(potPin,INPUT);
  leftDrive.attach(leftDrivePin); //0-90
  rightDrive.attach(rightDrivePin); //90-0
  Serial.begin(9600);
  Wire.begin();
  delay(5);
  sixDOF.init();
  delay(10);
}

void loop() { 
  float dt = millis()-time;

  int potVal = analogRead(potPin);
  Serial.print("turn = ");
  Serial.print(potVal);

  sixDOF.getEuler(angles);

  derivitive = (angles[1]-angle)/dt;
  angle = angles[1];

  integral += dt*angle;
  output = angle*kP + integral*kI + derivitive*kD;

  if (abs(output)<0.1){
    output = 0;
  }

  if (output<-1){
    output = -1;
  }

  if (output>1){
    output = 1;
  }

  drive(output);
  time=millis();
  delay(100);
}

void drive(float output){
  float r = (output  + 1) * 60;
  float l =   180 - r;
  Serial.print("    output ");
  Serial.print(l);
  Serial.print(" , ");
  Serial.println(r);
  leftDrive.write(l);
  rightDrive.write(r);
}





