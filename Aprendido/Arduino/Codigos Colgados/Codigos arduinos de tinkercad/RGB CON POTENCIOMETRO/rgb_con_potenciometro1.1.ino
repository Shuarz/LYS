int ledRojo = 3;
int ledAzul = 5;
int ledVerde = 6;

float entradaRoja;
float entradaAzul;
float entradaVerde;

float salidaRoja;
float salidaAzul;
float salidaVerde;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(ledVerde, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  entradaRoja = analogRead(A0);
  entradaAzul = analogRead(A1);
  entradaVerde = analogRead(A2);
  
  salidaRoja = map(entradaRoja, 0, 1023, 0, 255);
  salidaAzul = map(entradaAzul, 0, 1023, 0, 255);
  salidaVerde = map(entradaVerde, 0, 1023, 0, 255);
  
  analogWrite(ledRojo, salidaRoja);
  analogWrite(ledAzul, salidaAzul);
  analogWrite(ledVerde, salidaVerde);
  
  Serial.print("ROJO:");
  Serial.println(salidaRoja);
  Serial.print("AZUL:");
  Serial.println(salidaAzul);
  Serial.print("VERDE:");
  Serial.println(salidaVerde);
  
  delay(1000); // Wait for 100 millisecond(s)

}