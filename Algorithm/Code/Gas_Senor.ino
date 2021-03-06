#include "DHT.h"
#define DHTPIN 2  
#define DHTTYPE DHT11

#include <MQUnifiedsensor.h>
/************************Hardware Related Macros************************************/
#define         Board                   ("Arduino UNO")
#define         Pin                     (A0)  //Analog input 3 of your arduino
/***********************Software Related Macros************************************/
#define         Type                    ("MQ-2") //MQ2
#define         Voltage_Resolution      (5)
#define         ADC_Bit_Resolution      (10) // For arduino UNO/MEGA/NANO
#define         RatioMQ2CleanAir        (27.5) //RS / R0 = 9.83 ppm 

/*****************************Globals***********************************************/
MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

DHT dht(DHTPIN, DHTTYPE);
/*****************************Globals***********************************************/

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port
  

  //Set math model to calculate the PPM concentration and the value of constants
  MQ2.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ2.setA(36974); MQ2.setB(-3.109); // Configurate the ecuation values to get LPG concentration
  /*
    Exponential regression:
    Gas    | a      | b
    H2     | 987.99 | -2.162
    LPG    | 574.25 | -2.222
    CO     | 36974  | -3.109
    Alcohol| 3616.1 | -2.675
    Propane| 658.71 | -2.168
  */

  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ2.init(); 
  dht.begin();
  //Serial.print("Calibrating please wait.");
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    MQ2.update(); // Update data, the arduino will be read the voltage on the analog pin
    calcR0 += MQ2.calibrate(RatioMQ2CleanAir);
    Serial.print(".");
  }
  MQ2.setR0(calcR0/10);
 // Serial.println("  done!.");
 
}

void loop() 
{
  
  MQ2.update(); // Update data, the arduino will be read the voltage on the analog pin
  
  float mq2 = MQ2.readSensor();
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Sensor will read PPM concentration using the model and a and b values setted before or in the setup
  
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("??C "));
  Serial.print(F("LPG GAS : "));
  Serial.println(mq2,3);
  
  delay(500); //Sampling frequency
  
}
