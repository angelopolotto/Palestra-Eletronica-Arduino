#include <Bounce2.h>//https://github.com/thomasfredericks/Bounce2

int ledPin = 13;
int buttonPin = 2;
Bounce  bouncer  = Bounce();

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
	digitalWrite(buttonPin, HIGH);//Ativa o resitor de pull up
	bouncer.attach(buttonPin);
	bouncer.interval(5);
}
int flag = 0;
void loop()
{ 
  bouncer.update();
  flag = bouncer.read();
  
  if(flag)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin, LOW);
}


