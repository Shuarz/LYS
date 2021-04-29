#include <Servo.h>

Servo servo1;

void setup()
{
  servo1.attach(3, 490, 2500); //microsegundo
  
  Serial.begin(9600);
    
}

void loop()
{
  
  for(int grados=0; grados<0; grados += 45)
  {
    servo1.write(grados);
    Serial.println(grados);  
    delay(1500);
  
  }  
  
   for(int grados=180; grados>=0; grados -= 30)
  {
    servo1.write(grados);
    Serial.println(grados);  
    delay(1500);
  
  }
    
 
  
  
}