# 📉 2021 Purdue Data Analysis Project by TEAM_Eco_Avengers 📈

<br> 

📑 *Project Title*
        
    A Study on the Relationship between Outdoor Air Public Data(ODA) and Indoor Air Measurement Data(IDA) in the United States

📅 *Project Period*

    10-10-2021(SUN) ~ 12-20-2021(MON)

🧖🏻 ♀️ *Problem Statement*
    
     Air pollution, such as yellow dust and fine dust, is a problem that all countries and institutions are trying to solve in modern society. 
     The importance of air quality is a fact that everyone knows well. In addition, the importance of air quality has become more prominent since the COVID-19 pandemic. 
     The U.S. Centers for Disease Control and Prevention (CDC) officially recognizes air transmission as a major transmission route for COVID-19, and the World Health Organization (WHO) also includes air transmission as a COVID-19 transmission route.
     
     With the above importance, many people check outdoor air quality data (fine dust and ultrafine dust concentrations) provided by the government or provided by each institution every day before starting their daily routine. 
     Nevertheless, it can be said that the general public's interest in indoor air quality is weaker than that of outdoor air quality.
     
     According to the U.S. Environmental Protection Agency, indoor air, where modern people live more than 80% to 90% of the day, 
     is 100 times more polluted than outside air and a study also suggested that indoor air pollutants are 100 times more likely to be delivered to human lungs than air pollutants. 
     The American Lung Association (ALA) also announced that indoor harmful substances are two to five times more than outdoor air and that there are cases of 100 times more harmful substances. 
     Analysts say that various chemical components discharged from walls and furniture, beds, pillows, house dust, and dust caused by human movement are combined, polluting indoor air.
     
     therefore, we compare major indoor air pollutants and factor data provided by the Environmental Protection Agency (EPA) with data measured directly in the actual indoor environment to see how much difference there is,
     between external air data provided by countries or institutions and actual indoor air data. 


📖 *Considerations*

    💻 Software Architecture : 
    1) Node-Red
    It is a flow-based development tool for wiring and visualizing hardware devices as part of the Internet of Things. 
    This program can use JavaScript language, which was used because developers who participated in this study can use JavaScript and it is convenient to extract file data in the form of JSON.
    
    2) Arduino Integrated development environment
    The Arduino integrated development environment is a development environment provided to users for Arduino programming. 
    In this study, data values were uploaded without using wireless communication in the form of LAN. When the Arduino MCU was executed, the required value was delivered to UART communication.
    
    3) Jupyter notebook
    Jupiter Laptop is an open source-based web application. It was used because visualization should be performed in each unit by comparing and analyzing indoor air measurement data and outdoor air public data.
        
    📡 Hardware Architecture : 
    Hardware basically used aurduino uno rev3(2) , pms 5003 (fine dust sensor), dht 11 (temperature and humidity sensor), mq2 (gas sensor), and mq131 (gas sensor). 
    The sensor selection criteria consisted of sensors capable of extracting external air components provided by EPA, and two Arduinoes were used due to the research characteristics in which relatively many sensors were used.



💡 *Novelty*

    1. Develop the existing simple algorithm's concept!
       => We researched about the existing smart farm system that irrigatie automatically using Fuzzy and Genetic Algorithms.
      But these were too complicated for us and they only focused on normal situations with stable power.
      So we researed about simple algorithm that uses only the soil moisture value as a variable.
      We developed this algorithm by adding the remaining amount of power and the distance away from the irrigation source as a variables.
      
    2. Use LoRa, LoRaWAN with Serverless(FaaS)!
       => Most smart farms have implemented wireless network using WiFi, Zigbee, and LoRaWAN to get sensor values.
      Wi-Fi was not suitable for our project because it has more delay and more power consumption than LoRa.
      And Zigbee, a low-power communication technology, it's not suitable for outdoor farms too, because of its limited to short communication coverage.
      So, we decided to use LoRa and LoRaWAN.There were many related research about smart farm using LoRaWAN.
      But we want to have more novelty in power saving. So, we used serverless and FaaS which is good way to reduce idle power consumption in our system,
      that needs to reduce the time inverval between sending data to the server.

🏛 *System Overview*
 <p align="center">
   <img src="https://user-images.githubusercontent.com/63999666/154166528-e93b8a23-4c23-4725-984c-12118b8ab57a.png" width="700"alt="Image Error"/>
</p>

    
    1. Tomatoes were planted in 4 areas, each with a soil moisture sensor and irrigation tube installed.
    
    2. The crop data is transmitted to the gateway through LoRa communication.
    
    3. The gateway sends the crop data to the Cloud through LoRaWAN communication.
    
    4. When the crop data arrives at the Cloud, store it in the database and apply the devised algorithm.
    
    5. The Cloud sends the irrigation command to the gateway.
    
    6. The irrigation command arrives at the Arduino which operates the irrigation system.

<p align="center">
   <img src="https://user-images.githubusercontent.com/63999666/154166751-cda74f22-55d4-4fe7-9cee-dfaab4dcb1d2.png" width="600" alt="Image Error"/>
</p>


    🥕Data Acquisition: In this part, soil moisture sensors acquire soil moisture values in tomato fields. The sensor is connected to the Arduino by a wire. 
    The soil moisture value is delivered as an integer type and 4 values are delivered as an array.
    Data on the remaining amount of battery to operate the automatic irrigation system and the acquired crop data are collected on an Arduino connected to the sensor.
    The sensor data collected by the Arduino is then transferred to the gateway through LoRa communication.
    
    🥕Central Control: This part is the main part of the project. The collected data from the Data Acquisition Unit arrives at the cloud from the gateway.
    It stores the crop data in the database at the time that the data arrives and applies the devised algorithm.
    The result of this algorithm, which is an irrigation command, is transmitted to the Arduino.
    By using Node-RED in the cloud, the farmer can monitor the data through the Node-RED User Interface (UI) remotely.
    
    🥕Irrigation: This part receives and executes the irrigation command sent from the cloud.
    In this part, the motor connected to the water pipe for irrigation is connected to the relay.
    The relay connected to the Arduino receives the "turn the motor on and off" command sent from the LoRa module to execute automatic irrigation.
 
🖥️ *Environment Setting*

    ✔️macOS Big Sur version 11.4  
    
    ✔️Arduino IDE version 1.8.13 
    
    ✔️Python version 3.7.3 
    
    ✔️Arduio Uno 
    
    ✔️LoRa Module : Dragino[1]
    
    ✔️Soil Moisture Sensor version 1.2
  
📤 *Installation*

    $ git clone https://github.com/MINJILEE-PURDUE/KSW_2021_Fall_Program.git
    $ cd thomas

👨 👩 👧 👧 *Collaborator*
     
    👩 💻Yujung Gil
       -Dongguk Univeristy
       -Major in Computer Science Engineering
       -kuj9628@naver.com
       -https://github.com/fairyroad
       
    🎅🏻Minjeong Kim
       -Dongguk University
       -Major in Computer Science Engineering
       -kimmin9624@dgu.ac.kr
       -https://github.com/kimminje0ng
      
    👰Jiho Park
       -Dongguk University
       -Major in Computer Science Engineering
       -2017112091@dgu.ac.kr
       -https://github.com/zihos
       
    👩 🚀Bryan Supinski
       -Purdue University
       -Major in CNIT
       -bryansupinski@gmail.com
       -https://github.com/dplok1
    
    👨🏻 🦱Damien Pham
       -Purdue University
       -Major in CNIT
       -minhduypham0210@gmail.com
       -https://github.com/damien7749
    
    👨🏻 💼Max Li
       -Purdue University
       -Major in CNIT
       -maxli32145@gmail.com
    
    🧔🏻Parker Alexander
       -Purdue University
       -Major in CNIT
       -carmelo15andonly@gmail.com 

[1] Open Source WiFi, Linux Appliance, Dragino. Accessed on: December 02, 2021. [Online]. Available: [Dragino](https://dragino.com/)
