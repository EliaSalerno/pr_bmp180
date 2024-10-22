#include <math.h>
#include <SFE_BMP180.h>

int Altitude = 5;
SFE_BMP180 bmp180;

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1)));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
 Temp = Temp - 273.15;
 return Temp;
}

void setup() {
  Serial.begin(9600);
  bool success = bmp180.begin();
  if (success) {
    Serial.println("BMP180 init success");
  }
  pinMode(7,OUTPUT);
}

void loop() {
  char status;
  double T, P;
  bool success = false;

  double Temperatura = Thermistor(analogRead(0));
  int var = analogRead(1); // valore rilevato sul potenziometro/trimmer
  Altitude+=var; // valore rilevato dal potenziometro/trimmer aggiunto all'altitudine 
  status = bmp180.startTemperature();
  
  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          float comp = bmp180.sealevel(P, Altitude);
          
          Serial.print("Pressure: ");
          Serial.print(comp);
          Serial.println(" hPa");

          Serial.print("Temperature: ");
          Serial.print(T);
          Serial.println(" C");
        }
      }
    }
  }
  // Serial.println(Temperatura);
  // Temperatura<22 ? digitalWrite(7,HIGH) : digitalWrite(7,LOW);
  delay(100);
}