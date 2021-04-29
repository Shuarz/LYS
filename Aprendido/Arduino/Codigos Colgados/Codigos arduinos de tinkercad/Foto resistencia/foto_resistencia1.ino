int LDR = A0;
int led = 3;
int entrada;



void setup()
{
  pinMode(led, OUTPUT);
 
}

void loop()
{
  entrada = analogRead(LDR);
  
  if(entrada < 500)
  {
    digitalWrite(led, HIGH);
  }
  else if(entrada > 450)
  {
    digitalWrite(led, LOW);
  }
  
 
  delay(500); // Wait for 1000 millisecond(s)
}