#include <math.h>

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1)));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
 Temp = Temp - 273.15;
 return Temp;
}

void setup() {
 Serial.begin(115200);
 pinMode(7,OUTPUT);
}

void loop() {
 double Temperatura = Thermistor(analogRead(0));
 Serial.println(Temperatura);
 Temperatura<22 ? digitalWrite(7,HIGH) : digitalWrite(7,LOW);
 delay(100);
}