#include <max6675.h>
//Pinos
#define Rele A4
#define ReleGnd A5
#define TermoGndPin 2
#define TermoVccPin 3
#define TermoCLK 4
#define TermoCS 5
#define TermoDO 6
//Constantes
const float ganhoProporcional = 1.5;//Variável de controle, alterar para obter melhores resultados
const float temperaturaMinima = 0;//Temperatura minima arbritária
const unsigned PWMMin=0, PWMMax=255;//Valor minimo e máximo de PWM
//Variáveis
unsigned potenciaSoldador = 0;
float temperaturaLida,
      temperaturaSaida,
      erro, //variável de controle
      temperaturaMaxima,//Temperatura máxima estimada do soldador
      temperaturaDesejada = 100;//Pode ser alterada via terminal ou por um potenciômetro
//Inicialização de bibliotecas
MAX6675 termopar(TermoCLK, TermoCS, TermoDO);

void setup(){
  Serial.begin(9600);
  pinMode(Rele, OUTPUT);
  pinMode(TermoVccPin, OUTPUT); digitalWrite(TermoVccPin, HIGH);
  pinMode(TermoGndPin, OUTPUT); digitalWrite(TermoGndPin, LOW);
  pinMode(ReleGnd, OUTPUT); digitalWrite(ReleGnd, LOW);
  delay(500);

  temperaturaMaxima = temperaturaDesejada - temperaturaDesejada*0.3; //20% a mais da temperatura desejada
}

void loop(){
  temperaturaLida = termopar.readCelsius();
  erro = temperaturaDesejada - temperaturaLida;
  temperaturaSaida = erro*ganhoProporcional;
  potenciaSoldador = (int)mapParametros(temperaturaSaida, temperaturaMinima, temperaturaMaxima, PWMMin, PWMMax);
  analogWrite(Rele, potenciaSoldador);
  printValores();
  delay(500);
}

//Função para calcular a proporção do PWM pela temperatura
//Referencia: https://www.arduino.cc/en/reference/map 
long mapParametros(long x, long in_min, long in_max, long out_min, long out_max){
  if(x<0)
    return 0;
  //else if(in_min >= x)
    //return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  else
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    //return out_min;
}

//Exibe os valores
void printValores(){
  Serial.print("Temp Desejada = ");
  Serial.println(temperaturaDesejada);
  Serial.print("--> Temp Lida = ");
  Serial.println(temperaturaLida);
  Serial.print("--> erro = ");
  Serial.println(erro);
  Serial.print("--> temperatura saida = ");
  Serial.println(temperaturaSaida);
  Serial.print("--> pontencia soldador = ");
  Serial.println(potenciaSoldador);
}

