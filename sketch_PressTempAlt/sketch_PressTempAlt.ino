//#include <SFE_BMP180.h>
#include <LibPrintf.h>
#include <Adafruit_BMP085.h>

#define SEA_LEVEL_PRESSURE 101325 //pressione standard al livello del mare oppure quella reale al livello del mare

/*
Con questa libreria si ha la possibilità di calcolare anche l'altitudine ma non comprendo come si faccia a calcolare la pressione 
al livello del mare della zona in cui si effettua la rilevazione... o meglio nei vari tutorial che ho trovato si parla di una misurazione simile.
Ho inoltre inserito una libreria che permette di organizzare l'output con la funzione printf(), con questa funzione si ha la possibilità
di strutturare l'outuput con una sola stampa, cosa che invece non succedeva con la print() o la println()
*/

//SFE_BMP180 bmp;
Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(115200);
  while(!bmp.begin()){
    Serial.println("Sensore non trovato!");
    delay(1000);
  }
}

void loop() {
  char status;
  float t,p,a;
  t=bmp.readTemperature();
  // notare che la lettura con questa libreria pare molto più snella, non vorrei ci fossero conseguenze impreviste in caso di errore.
  // purtroppo la correttezza o meno del codice si può osservare solo con il sensore in mano
  p=bmp.readPressure();
  
  a=bmp.readAltitude(SEA_LEVEL_PRESSURE);
 
  printf("Temperatura: %5f°C-Pressione: %10Pa-Altitudine: %fm",t,p,a);
  delay(1000);
}
