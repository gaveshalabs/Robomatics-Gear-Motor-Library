/*
  DCMotor.h - implementation
  Copyright (c) 2023 Graziano Blasilli.
*/

#include "RobomaticsGearMotor.h"

/* class constructor */
RobomaticsGearMotor::RobomaticsGearMotor(uint8_t pin1, uint8_t pin2) {
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->mirrorFlag = false;
  this->fineControlEnable = true; 


  //set the motor PWM frequency to 100Hz
  analogWriteFrequency(100);

  pinMode(this->pin1, OUTPUT);
  pinMode(this->pin2, OUTPUT);
  this->speed(0);
}


// Turn the motor on with a specified speed.
void RobomaticsGearMotor::speed(int speed) {
  uint8_t l_speed = 0, r_speed = 0;

  //Ensure speed is within valid range (0-255)
  speed = constrain(speed, -255, 255);
  
  if (this->fineControlEnable){           // drive-lock mechanism
    l_speed = MAX_PWM_DUTY;
    r_speed = MAX_PWM_DUTY;

    if(speed < 0){
      r_speed -= abs(speed);
    }else if ( speed > 0){
      l_speed -= abs(speed); 
    }

    analogWrite(this->pin1, l_speed);
    analogWrite(this->pin2, r_speed);

  }else{                                // drive-coast mechanism
    l_speed = MIN_PWM_DUTY;
    r_speed = MIN_PWM_DUTY;
    
    if(speed < 0){
      l_speed += abs(speed);
    }else if ( speed > 0){
      r_speed += abs(speed); 
    }

    analogWrite(this->pin1, l_speed);
    analogWrite(this->pin2, r_speed);
  }
}

// Turn the motor on with a specified speed, for a given time.
void RobomaticsGearMotor::speed(int speed, int millisec) {
  this->speed(speed);
  delay(millisec);
  this->speed(0);
}


// Make motor Nuetral
void RobomaticsGearMotor::neutral(){
   analogWrite(this->pin1, MIN_PWM_DUTY);
  analogWrite(this->pin2, MIN_PWM_DUTY);
}

// Make motor Locked
void RobomaticsGearMotor::lock(){
  analogWrite(this->pin1, MAX_PWM_DUTY);
  analogWrite(this->pin2, MAX_PWM_DUTY);
}

// Make the driver operarion mirrored for robotic applications
void RobomaticsGearMotor::mirror(bool isEnable){
  uint8_t temp;
 
  if(this->mirrorFlag != isEnable){
    //swap pins
    temp = this->pin1;
    this->pin1 = this->pin2;
    this->pin2 = temp;
    
    //set the flag status
    this->mirrorFlag = isEnable;
  }
}


// Make the driver operarion mirrored for robotic applications
void RobomaticsGearMotor::fineControlMode(bool isEnable){ 
  this->fineControlEnable = isEnable; 
}
