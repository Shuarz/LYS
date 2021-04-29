#define LED 9
#define BOTON 3

int estadoBoton;
int estadoAnteriorBoton=0;
int contador=0;

void setup()
{
  	Serial.begin(9600);
	pinMode(LED, OUTPUT);
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
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);	
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          
      }
      if(contador==2)
      {
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);	
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          
      }
      
      
      if(contador==3)
      {
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);	
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
      }
      
      if(contador==4)
      {
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);	
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,HIGH);
          Serial.println("Rojo");
          delay(250);
          digitalWrite(LED,LOW);
          Serial.println("Rojo");
      }
      
    }
    estadoAnteriorBoton=estadoBoton;  
  }
  if(contador==4)
  {
  	contador=0; 
  }
  delay(50);
}
 