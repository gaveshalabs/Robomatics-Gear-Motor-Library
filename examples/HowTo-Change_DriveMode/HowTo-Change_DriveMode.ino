/*
    Change to Drive-Lock and Drive-Coast modes

    used in advance motor control

    Drive-lock mode  -  Gives much linear respond for speed values over 0 to 255 range, (for both direction)
                        making control fine and smooth
                        
                        when speed is 0 motor goes to lock condition.

                        In this mode motor goes to lock condition on each PWM cycles 
                        creating closed current loop to consume it's own back EMF current.
                        So in this mode motor tends to stop faster compared to driver-coast mode.
                        <This is the default mode>


    Drive-coast mode -  Allow motors to run free when motor speed is 0

                        
                        In this mode motor goes to neutral condition on each PWM cycles 
                        creating suden current lose, So motor runs free until it is stoped by the friction forces

    This example code will driver the Robomatics gear motor both sides.

    The circuit:
    * V+ pin of the motor ---> VCC of ESP32
    * D+ pin of the motor ---> GPIO pin 27
    * D- pin of the motor ---> GPIO pin 26 
    * V-/GND pin of the motor ---> GND pin of ESP32


    Created 25 May 2024
    By Ushan Chaminda
    
    Download the datasheet and wiring diagram from this link
    http://datasheet

*/

#include "RobomaticsGearMotor.h"

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

  //set driver-lock mode
  motor.fineControlMode(true);   
  Serial.println("Enabling driver-lock mode")         
  delay(1000);

  // let's speed up motor to postive direction starting from 0 and 
  // drop the speed to 0 to see sudden stop action.
  motor.fineControlMode(true);
  for (int i = 0 ; i < 255; i++){
    motor.speed(i);
    delay(10);
  }
  motor.speed(0);

 
  //set driver-coast mode
  motor.fineControlMode(false);   
  Serial.println("Enabling driver-Coast mode")         
  delay(1000);

  // let's speed up motor to postive direction starting from 0 and
  // drop the speed to 0 to see slow stop action.
  for (int i = 0 ; i < 255; i++){
    motor.speed(i);
    delay(10);
  }
  motor.speed(0);
}
