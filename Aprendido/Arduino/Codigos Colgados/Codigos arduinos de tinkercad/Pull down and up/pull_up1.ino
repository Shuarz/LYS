#define LED 9
#define BOTON 4

int estadoBoton;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT);
}

void loop()
{
  estadoBoton=digitalRead(BOTON);
  
  if(estadoBoton == LOW)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
  	digitalWrite(LED, LOW);
  }
}
  
 /* 
  digitalWrite(9, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(9, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalread*/