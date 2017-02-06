#define RESIST_PIN   A0
float Vout;
int Vout_dig;
float resit;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {    
  Vout_dig=analogRead(RESIST_PIN);
  Vout = (5/1023)*(float)Vout_dig;
  /*
  Vout = (Vin*R2)/(R1+R2)
  R1 = ((Vin-Vout)*R2)/(Vout)
  */
  resit = ((5-Vout)*10000)/Vout;
  Serial.println(resit);
}


