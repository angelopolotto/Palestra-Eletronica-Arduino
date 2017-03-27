#include <max6675.h>
#define Rele 9
#define ReleGnd 10
#define TermoGndPin 2
#define TermoVccPin 3
#define TermoCLK 4
#define TermoCS 5
#define TermoDO 6

MAX6675 termopar(TermoCLK, TermoCS, TermoDO);

void setup(){
  Serial.begin(9600);
  pinMode(Rele, OUTPUT);
  pinMode(TermoVccPin, OUTPUT); digitalWrite(TermoVccPin, HIGH);
  pinMode(TermoGndPin, OUTPUT); digitalWrite(TermoGndPin, LOW);
  pinMode(ReleGnd, OUTPUT); digitalWrite(ReleGnd, LOW);
  delay(500);
}

unsigned potenciaSoldador = 0;
float temperaturaLida, temperaturaDesejada = 80;
void loop(){
  temperaturaLida = termopar.readCelsius();
  potenciaSoldador = (int)mapParametros(temperaturaLida, temperaturaDesejada, 10, 0, 255);
  analogWrite(Rele, potenciaSoldador);
  printValores();
  delay(500);
}

//https://www.arduino.cc/en/reference/map 
long mapParametros(long x, long in_min, long in_max, long out_min, long out_max){
  if(in_min >= x)
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  else
    return out_min;
}

void printValores(){
  Serial.print("Temp Desejada = ");
  Serial.println(temperaturaDesejada);
  Serial.print("--> Temp Lida = ");
  Serial.println(temperaturaLida);
  Serial.print("--> potenciaSoldador = ");
  Serial.println(potenciaSoldador);
}

