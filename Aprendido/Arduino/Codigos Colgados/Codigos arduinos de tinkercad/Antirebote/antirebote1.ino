#define LED 10
#define BOTON 3

int estadoBoton;
int estadoLed = 0;
int estadoAnteriorBoton = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT);
}

void loop()
{
  estadoBoton = digitalRead(BOTON);
  
  if(estadoBoton != estadoAnteriorBoton)
  {
  	if(estadoBoton == HIGH)
  	{
  		estadoLed = 1 - estadoLed; // o estadoLed = !estadoLed;
    	digitalWrite(LED, estadoLed);
  		delay(250);
  	}
    
    estadoAnteriorBoton=estadoBoton;
  } 
}