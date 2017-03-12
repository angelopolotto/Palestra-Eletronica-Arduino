#define LED_1 13
#define LDR A0

int val = 0, med;
void setup()
{
  Serial.begin(9600); 
  // Inicializa as portas como saidas digitais.
  pinMode(LED_1, OUTPUT);
}
void loop()
{
  // Retira dez amostras e faz uma média, isso evita ruidos e acionamentos intermitentes.
  med = 0;
  for(int i=0;i<10;i++) //Faz 10 vezes a leitura do sensor
  {
    val = analogRead(LDR); // Lê o LDR.
    med = med + val; //Armazenamento na varíavel LDR o valor lido + o valor anterior
    delay(5); //Delay se 10 milissegundos
  }
  med = med/10;
  Serial.print("Med = " );                       
  Serial.println(med);
  
  if( med <= 400)// A sensibilidade deve ser ajustada através desse número.
	{
    digitalWrite(LED_1, HIGH);
  }
  else
	{
    digitalWrite(LED_1, LOW);
  }
  //delay(50);
}


