int led = 3;
float entrada;
float salida;

void setup()
{
  pinMode(led, OUTPUT);
  
  Serial.begin(9600); // para poner el texto abajo y que tire bits
}

void loop()
{
  entrada= analogRead(A0);
  
  salida = map(entrada, 0, 1023, 0, 253);
  
  analogWrite(led, salida);
  
  delay(100); // Wait for 1000 millisecond(s)
  
  Serial.print("Entrada: ");
  Serial.print(entrada);
  Serial.print("salida: ");
  Serial.println(salida);
  
}