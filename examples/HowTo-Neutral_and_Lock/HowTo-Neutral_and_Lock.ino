/*
    This example code will dimostrate the different between lock and neutral condition
    of the motor. can be used for advance robotic functions

    The circuit:
    * V+ pin of the motor ---> VCC of ESP32
    * D+ pin of the motor ---> GPIO pin 27
    * D- pin of the motor ---> GPIO pin 26 
    * V-/GND pin of the motor ---> GND pin of ESP32


    Created 25 May 2024
    By Ushan Chaminda
    
    Download the datasheet and wiring diagram from this link
    https://drive.google.com/file/d/14rxRRS_ALYlHMCaU1q9OvN5yCySvRpoB/view?usp=share_link

*/

#include <RobomaticsGearMotor.h>

//First Select two GPIO pins which can output PWM signals in your development board
int signalDp = 26;
int singnalDn = 27;

//Then create a motor object with above pins
RobomaticsGearMotor motor = RobomaticsGearMotor(signalDp, singnalDn);


void setup() {

  Serial.begin(9600);
  Serial.println("Robomatics Gear Motor Example - explain Lock and Neutral condition of the motor");
}


void loop() {

    Serial.println("Neutral the motor");
    motor.neutral();   //now the motor is neutral. You will feel easy to rotate motor axcel by hand.
    delay(10000);

    Serial.println("Lock the motor");
    motor.lock();      //now the motor is locked. You will feel stiffness compared to previous condition.
    delay(10000);
}
