int ledPin = 11;
int buttonPin = 2;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
int flag = 0;
void loop()
{
  // read from the button pin
  int button = digitalRead(buttonPin);
  if (button==HIGH)
  {
    delay(300);
    button = digitalRead(buttonPin);
    if (button==LOW){
      flag = !flag;
    }
  } 
  if(flag)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin, LOW);
}


