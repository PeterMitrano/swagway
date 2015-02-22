#include <Servo.h>

int pin = 3;
Servo motor;

void setup() {
  motor.attach(pin,1000,2000);
}

void loop() {
  motor.write(90); //full forward
  delay(1000);  
  motor.write(45); //stop
  delay(1000);
  motor.write(0); //full back
  delay(1000);
  motor.write(45); //stop
  delay(1000);
}




