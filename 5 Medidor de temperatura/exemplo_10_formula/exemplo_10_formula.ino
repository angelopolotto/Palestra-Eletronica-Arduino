#include <math.h>

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 return Temp;
}

void setup() {
 Serial.begin(9600);
}

void loop() {
 Serial.println(int(Thermistor(analogRead(0))));  // display Celcius
 delay(100);
}


