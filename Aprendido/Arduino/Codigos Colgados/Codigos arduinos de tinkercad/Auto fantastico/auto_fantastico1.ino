int LEDS[]={5,4,3,2,1};


void setup()
{
  for(int i=0; i<5; i++)
  {
    pinMode(LEDS[i],OUTPUT);
  }
}
void loop()
{
  for(int i=0; i<5; i++)
  {
  digitalWrite(LEDS[i], HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(LEDS[i], LOW);
  delay(100);
  }
  
  for(int i=3; i>0; i--)
  {
  digitalWrite(LEDS[i], HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(LEDS[i], LOW);
  delay(100);
  }
  
}