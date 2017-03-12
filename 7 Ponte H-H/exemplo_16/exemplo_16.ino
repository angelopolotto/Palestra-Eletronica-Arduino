int IN1 = 5 ; int IN2 = 6;//motor A
int IN3 = 10; int IN4 = 7;//motor B
int velocidade = 0;
void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}
void loop(){
  digitalWrite(IN2,LOW);//Sentido Horario 
  digitalWrite(IN1,230);//Alta
  digitalWrite(IN1,150);//Intermediaria
  digitalWrite(IN1,80);//Baixa
  digitalWrite(IN4,LOW);//Sentido Horario Motor B
  while (velocidade < 255){//velocidade de 0 a 255
    digitalWrite(IN3,velocidade);
    velocidade = velocidade + 10;
    delay(50);
  }
  while (velocidade > 0){//velocidade de 255 a 0
    digitalWrite(IN3,velocidade);
    velocidade = velocidade - 10;
    delay(50);
  }
}


