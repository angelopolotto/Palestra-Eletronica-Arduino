#define analogInPin A0

int sensorValue = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("Potenc = " );            
  Serial.println(sensorValue);      
  delay(500);                     
}