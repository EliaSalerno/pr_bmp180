# BMP180 Barometric Pressure/Temperature/Altitude Sensor- 5V ready
## How to Set Up the BMP180 Barometric Pressure Sensor on an Arduino

## BMP180

### The Bosch BMP180 runs on 3.3V, but many breakout boards have a voltage regulator and an I2C level shifter so you can power it with either 3.3V or 5V.

![alt text](https://www.circuitbasics.com/wp-content/uploads/2017/05/Arduino-Pressure-Sensor-Tutorial-BMP180-Pin-Diagram.png)

> Installing the BMP180 Library

### Before we start programming the BMP180, download and install the library. 
### I’m going to use a really useful BMP180 library from Sparkfun. It takes care of all the math for calculating the true temperature and pressure readings, 
### as well as the math for calculating altitude.

![zip libreria](https://github.com/sparkfun/BMP180_Breakout_Arduino_Library/archive/master.zip)

### You can download a ZIP file of the library from this link. To install it, open up the Arduino IDE, go to Sketch > Include Library > Add Library, then select the ZIP file you just downloaded.

![alt text](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2016/09/bmp180-barometris-sensor_bb.png?w=700&quality=100&strip=all&ssl=1)

# Nuova versione 
## Altra libreria, diverse funzioni ma codice più snello
### Nella directory librerie_utili si trova una nuova libreria che va aggiunta seguendo il seguente iter:
### barra strumenti -> sketch->Includi libreria->Aggiungi libreria da file .ZIP
### Invece la nuova libreria per il sensore va inserita in questo modo:
### Sketch -> Includi libreria -> gestisci librerie
### UGUALE METODO PER L'INSTALLAZIONE DELLA LIBRERIA PRECEDENTEMENTE TRATTATA
```
In questa versione del codice (che qui trovi sotto il nome sketch_PressTempAlt) uso la libreria Adafruit_BMP085 
compatibile anche con la versione 180. Ho trovato interessante il fatto che per la rilevazione usasse solo una 
versione rielaborata del read (readPressure, readTemperature, readAltitude) questa libreria mette a disposizione 
una funzione che calcola l'altitudine. Il problema è che si necessita della misurazione della pressione a livello
del mare. Sto pensando di creare un programma che permetta di inserire questo valore in modo dinamico senza dover
ogni volta mettere mani al codice. 
```
# Problemi di temperatura
## La temperatura non è corretta: come risolvere?
### link utili: 
 - https://overvolt.tech/sensori/2
 - https://www.arduinofacile.it/2021/04/29/controllo-di-temperatura-mediante-tmp36-tinkercad/
 - https://www.makerguides.com/tmp36-arduino-tutorial/

# Steinhart-Hart su termoresistenza
## Test equazione di Steinhart-Hart su termoresistenza
### Ho fatto un test su una termoresistenza che avevo a casa, utilizzando il primo dei tre link sopra. 
```
Il circuito è alimentato a 5v, ho fatto un partitore con una resistenza da 10k; utilizzando l'equazione di Steinhart-Hart ho testato il funzionamento 
in casa confrontando i valori con quelli rilevati dal termostato. Il risultato è stato ottimo!
Tra i due c'è una variazione di massimo 0,2 °
```
# Test trimmer per variare altitudine
## Ho realizzato questo test per vedere come alterare l'altitudine in fase di salita
### Nel repository è presente una foto del mio test

 - https://www.arduinofacile.it/2019/11/13/controllo-di-un-led-mediante-un-potenziometro/

### Questo è il link utile da cui comprendere come configurare il trimmer/potenziometro
### Differenza tra il trimmer e il potenziometro
### il potenziometro dispone di una manopolina per alterare il valore in uscita, mentre per il trimmer bisogna usare un cacciavite 

## Codice per invio su seriale
### Tempo addietro, su un progetto il cui scopo era inviare comandi ad arduino mediante seriale, ho realizzato il seguente codice

```
const unsigned int MAX_LMSG=1;  // 1 per il numero di cifre da poter accettare

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char tmsg=0;
  unsigned int val=0;
  static unsigned int MSG_POS=0;
  static char msg[MAX_LMSG+1];
  while(Serial.available()>0){
    tmsg=Serial.read();
    if(tmsg!='\n' && MSG_POS<MAX_LMSG){
      msg[MSG_POS++]=tmsg;
    }
    else
    {
      msg[MSG_POS]='\0';
      MSG_POS=0;
    }
  }
  val=atoi(msg);
  Serial.println(val);
  delay(1000);
}
```

### Si potrebbe implementare questo codice su quello del progetto precedente al posto del 
### trimmer/potenziometro, ovviamente se risulta possibile inviare mediante seriale.
### In breve lo scopo è di utilizzare il medesimo canale in entrambi e sensi e il seriale utilizzato 
### con il tablet dovrebbe permetterlo, quando vi spostate in montagna al cambio di altitudine 
### inserite da tablet il nuovo valore e lui con i suoi calcoli restituisce pressione e temperatura corretti.
