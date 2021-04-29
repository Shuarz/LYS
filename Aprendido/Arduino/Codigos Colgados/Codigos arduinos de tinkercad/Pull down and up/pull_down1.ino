const int button1Pin = 2;  
  
const int ledPin =  3;  

void setup()
{
  pinMode(button1Pin, INPUT);
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  int button1State; 

  button1State = digitalRead(button1Pin);

  // A == B significa "EQUIVALENTE". 
  // A && B significa "Y". Esto es verdadero si ambos lados son verdaderos.
  // A || B significa "OR". Esto es verdadero si uno de los dos lados (o los dos a la vez) son verdaderos.
  // !A significa "NO". Convierte lo que viene después en lo contrario.
      
  if (button1State == HIGH)
  {
   digitalWrite(ledPin, HIGH);  // turn the LED on
  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn the LED off
  }
}