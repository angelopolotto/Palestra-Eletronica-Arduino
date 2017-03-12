int ledPin = 13;
int buttonPin = 2;
int flag = LOW;
void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
	digitalWrite(buttonPin, HIGH);//Ativa o resitor de pull up
}
void loop(){
  int button = digitalRead(buttonPin);
  if (button==HIGH){
    delay(300);
    button = digitalRead(buttonPin);
    if (button==HIGH)
      flag = HIGH;
  }
  else{
    delay(300);
    button = digitalRead(buttonPin);
    if (button==LOW)
      flag = LOW;
  }
  if(flag)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin, LOW);
}


