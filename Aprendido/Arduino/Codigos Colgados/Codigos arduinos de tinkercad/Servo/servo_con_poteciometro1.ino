#include <Servo.h>

Servo servo1;

void setup()
{
  servo1.attach(3, 490, 2500); //microsegundo
  
  Serial.begin(9600);
    
}

void loop()
{
  
  float grados;
  float entrada;
  
  entrada = analogRead(A0);
  grados = map (entrada, 0, 1023, 0, 180);
  servo1.write(grados);
  
  Serial.println(grados);
  
  delay(550);
  
}