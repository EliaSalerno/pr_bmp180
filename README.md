# BMP180 Barometric Pressure/Temperature/Altitude Sensor- 5V ready
## How to Set Up the BMP180 Barometric Pressure Sensor on an Arduino
### The BMP180 barometric pressure sensor is a great sensor that can be used to predict the weather, detect altitude, and measure vertical velocity. It’s perfect for weather stations, remote controlled vehicles, weather balloons, and lots of other projects. It’s an extremely sensitive sensor too. As you’ll see in a minute, it can detect changes in altitude of just a few inches.
### The BMP180 is a piezoresistive sensor that detects pressure. Piezoresistive sensors are made up of a semiconducting material (usually silicon) that changes resistance when a mechanical force like atmospheric pressure is applied.
### The BMP180 measures both pressure and temperature, because temperature changes the density of gasses like air. At higher temperatures, air is not as dense and heavy, so it applies less pressure on the sensor. At lower temperatures, air is more dense and weighs more, so it exerts more pressure on the sensor. The sensor uses real-time temperature measurements to compensate the pressure readings for changes in air density.
### The BMP180 outputs an uncompensated temperature (UT) value and an uncompensated pressure (UP) value. The temperature measurement is taken first, followed by a pressure measurement.
```
I materiali utilizzati nei trasmettitori di pressione piezoresistivi presentano una certa dipendenza dalla temperatura. 
Il comportamento della misura dei trasmettitori di pressione varia, quindi, in base alla temperatura. 
Di conseguenza, si verificano offset del punto zero legati alla temperatura ed errori di intervallo. 
In parole semplici,se si applica una pressione di 10 bar a 25°C e, una seconda volta, a 100 °C si otterranno valori diversi. 
Nell’analisi di una scheda tecnica per gli utenti, questo significa che valori di accuratezza eccellenti in realtà servono a poco 
se la compensazione della temperatura non è adeguata. 
```
![alt text](https://www.circuitbasics.com/wp-content/uploads/2017/05/Arduino-BMP180-Tutorial-Measurement-Flow-Chart.png)

## BMP180

### The Bosch BMP180 runs on 3.3V, but many breakout boards have a voltage regulator and an I2C level shifter so you can power it with either 3.3V or 5V.

![alt text](https://www.circuitbasics.com/wp-content/uploads/2017/05/Arduino-Pressure-Sensor-Tutorial-BMP180-Pin-Diagram.png)

> Installing the BMP180 Library

### Before we start programming the BMP180, download and install the library. 
### I’m going to use a really useful BMP180 library from Sparkfun. It takes care of all the math for calculating the true temperature and pressure readings, 
### as well as the math for calculating altitude.

https://github.com/sparkfun/BMP180_Breakout_Arduino_Library/archive/master.zip

### You can download a ZIP file of the library from this link. To install it, open up the Arduino IDE, go to Sketch > Include Library > Add Library, then select the ZIP file you just downloaded.

https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2016/09/bmp180-barometris-sensor_bb.png?w=700&quality=100&strip=all&ssl=1

### ---
