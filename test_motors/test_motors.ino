int potPin = 15;


void setup(){
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop(){
  
  int potVal = analogRead(A0);
  Serial.println(potVal);
  delay(100);
  
  
}
