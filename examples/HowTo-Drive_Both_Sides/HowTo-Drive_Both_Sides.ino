/*
    Driver Robomatics Gear motor both Sides

    This example code will driver the Robomatics gear motor both sides with UNO,ESP32 and NodeMCU

    The circuit:
    * V+ pin of the motor ---> VCC 
    * D+ pin of the motor ---> GPIO pin 27
    * D- pin of the motor ---> GPIO pin 26 
    * V-/GND pin of the motor ---> GND


    Created 25 May 2024
    By Ushan Chaminda
    
    Download the datasheet and wiring diagram from this link
    http://datasheet

*/

#include <RobomaticsGearMotor.h>

//First Select two GPIO pins which can output PWM signals in your development board
int signalDp = 26;
int singnalDn = 27;

//Then create a motor object with above pins
RobomaticsGearMotor motor = RobomaticsGearMotor(signalDp, singnalDn);


void setup() {

  Serial.begin(9600);
  Serial.println("Robomatics Gear Motor Example - driver both side");
}


void loop() {

  // let's speed up motor to postive direction starting from 0
  for (int i = 0 ; i < 255; i++){
    motor.speed(i);
    delay(10);
  }

  // now let's slow down motor speed to 0 from postive direction 
  for (int i = 255 ; i >= 0; i--){
    motor.speed(i);
    delay(10);
  }

  // now let's speed up motor to negative direction starting from 0
  // note we are giving NEGATIVE values this time
  for (int i = 0 ; i > -255; i--){
    motor.speed(i);
    delay(10);
  }

  // finally let's slow down motor speed to 0 from negative direction
  for (int i = -255 ; i <= 0; i++){
    motor.speed(i);
    delay(10);
  }
}
