/*
    Set Robomatics Gear motor to work in mirror mode

    In many cases of building robots motors get mirrored.
    which makes it difficult to apply same control logic to both motors to driver in same direction
    In such cases use the  MIRROR function in as shown in this example
    

                ^^^^   Front  ^^^^ 
                       _____
                    __|     |__
                   |           |
                 __|           |__ 
                |                 |   
                |                 |   
                |                 |   
           __   |-----       -----|   __
  Left    |  |  |Motor       Motor|  |  |  Right
  Wheel   |  |==|  A           B  |==|  |  Wheel
          |  |  |----         ----|  |  |
          |__|  |                 |  |__|
                |_________________|
                        
                        Rear

    The circuit:
    for this example I'm using Two motors named MotorA and MotorB

    MotorA
    * V+ pin of the motor ---> VCC
    * D+ pin of the motor ---> GPIO pin 27
    * D- pin of the motor ---> GPIO pin 26 
    * V-/GND pin of the motor ---> GND

    MotorB
    * V+ pin of the motor ---> VCC
    * D+ pin of the motor ---> GPIO pin 22
    * D- pin of the motor ---> GPIO pin 23 
    * V-/GND pin of the motor ---> GND


    Created 25 May 2024
    By Ushan Chaminda
    
    Download the datasheet and wiring diagram from this link
    http://datasheet

*/

#include <RobomaticsGearMotor.h>

//First Select two GPIO pins which can output PWM signals in your development board
int MotorA_signalDp = 26;
int MotorA_singnalDn = 27;

int MotorB_signalDp = 22;
int MotorB_singnalDn = 23;


//Then create two motor object with above pins
RobomaticsGearMotor motorA = RobomaticsGearMotor(MotorA_signalDp, MotorA_singnalDn);
RobomaticsGearMotor motorB = RobomaticsGearMotor(MotorB_signalDp, MotorB_singnalDn);



void setup() {

  //mirror motorB
  motorB.mirror(true);        //this will change the direction of motorB

  Serial.begin(9600);
  Serial.println("Robomatics Gear Motor Example - driver both side");
}


void loop() {

  // let's speed up boths motor to postive direction starting from 0
  for (int i = 0 ; i < 255; i++){
    motorA.speed(i);
    motorB.speed(i);
    delay(10);
  }

  // now let's slow down both motor speed to 0 from postive direction 
  for (int i = 255 ; i >= 0; i--){
    motor.speed(i);
    delay(10);
  }

}
