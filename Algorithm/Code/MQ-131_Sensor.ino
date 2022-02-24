#include <MQUnifiedsensor.h>

//Definitions
#define placa "Arduino UNO"
#define Voltage_Resolution 5
#define pin A0 //Analog input 0 of your arduino
#define type "MQ-131" //MQ131
#define ADC_Bit_Resolution 10 // For arduino UNO/MEGA/NANO
#define RatioMQ131CleanAir 15 //RS / R0 = 15 ppm
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ131(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type);

void setup() {
  //Init the serial port communication - to debug the library
  Serial.begin(9600); //Init serial port

  //Set math model to calculate the PPM concentration and the value of constants
  MQ131.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ131.setA(23.943); MQ131.setB(-1.11); // Configurate the ecuation values to get O3 concentration

  /*
    Exponential regression:
  GAS     | a      | b
  NOx     | -462.43 | -2.204
  CL2     | 47.209 | -1.186
  O3      | 23.943 | -1.11
  */


  /*****************************  MQ Init ********************************************/ 
  //Remarks: Configure the pin of arduino as input.
  /************************************************************************************/ 
  MQ131.init(); 
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ131.setRL(10);
  */
  /*****************************  MQ CAlibration ********************************************/ 
  // Explanation: 
  // In this routine the sensor will measure the resistance of the sensor supposing before was pre-heated
  // and now is on clean air (Calibration conditions), and it will setup R0 value.
  // We recomend execute this routine only on setup or on the laboratory and save on the eeprom of your arduino
  // This routine not need to execute to every restart, you can load your R0 if you know the value
  // Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    MQ131.update(); // Update data, the arduino will be read the voltage on the analog pin
    calcR0 += MQ131.calibrate(RatioMQ131CleanAir);
    Serial.print(".");
  }
  MQ131.setR0(calcR0/10);
  Serial.println("  done!.");
  
  if(isinf(calcR0)) {Serial.println("Warning: Conection issue founded, R0 is infite (Open circuit detected) please check your wiring and supply"); while(1);}
  if(calcR0 == 0){Serial.println("Warning: Conection issue founded, R0 is zero (Analog pin with short circuit to ground) please check your wiring and supply"); while(1);}
  /*****************************  MQ CAlibration ********************************************/ 
  MQ131.serialDebug(true);
}

void loop() {
  MQ131.update(); // Update data, the arduino will be read the voltage on the analog pin

  

  float mq131 = MQ131.readSensor(); 
  Serial.print(F("O3 GAS : " ) ) ;  
//  Serial.println(mq131*100000) ;
  Serial.println(mq131, 6);
//  float a1 = MQ131.getA();
//  float b1 = MQ131.getB(); 
//  Serial.print(F("sibal"));
//  Serial.println(a1);
//  Serial.println(b1);
  
  delay(500); //Sampling frequency
}