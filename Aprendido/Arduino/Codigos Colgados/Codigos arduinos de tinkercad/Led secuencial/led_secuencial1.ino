#define LEDR 11
#define LEDA 12
#define LEDV 13
#define BOTON 4

int estadoBoton;
int estadoAnteriorBoton=0;
int contador=0;

void setup()
{
  	Serial.begin(9600);
	pinMode(LEDR, OUTPUT);
 	pinMode(LEDA, OUTPUT);
	pinMode(LEDV, OUTPUT);
  	pinMode(BOTON, INPUT);
}

void loop()
{
  estadoBoton=digitalRead(BOTON);
  
  if(estadoBoton != estadoAnteriorBoton)
  {
    if(estadoBoton==HIGH)
    {
      contador++;
      if(contador==1)
      {
          digitalWrite(LEDV,LOW);
          digitalWrite(LEDR,HIGH);
          Serial.println("Rojo");
      }
      if(contador==2)
      {
          digitalWrite(LEDR,LOW);
          digitalWrite(LEDA,HIGH);
          Serial.println("Amarillo");
      }
      if(contador==3)
      {
          digitalWrite(LEDA,LOW);
          digitalWrite(LEDV,HIGH);
          Serial.println("Verde");
      }
    }
    estadoAnteriorBoton=estadoBoton;  
  }
  if(contador==3)
  {
  	contador=0; 
  }
}