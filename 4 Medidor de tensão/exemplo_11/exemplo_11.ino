#define RESIST_PIN   A0
float Vin;
float R1;
float Vref = 5;
float Steps=1023;
float StepSize = (float)Vref/(float)Steps;
float R2 = 10000;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  ADC=analogRead(RESIST_PIN);
  Vin = StepSize*(float)ADC;
  /*
  Vout = (Vin*R2)/(R1+R2)
  R1 = ((Vin-Vout)*R2)/(Vout)
  */
  R1 = (float)((5-Vin)*10000)/(float)Vin;
  Serial.println(R1);
  delay(300);
}


