#ifndef RobomaticsGearMotor_H 
#define RobomaticsGearMotor_H

#include <Arduino.h>

#define MAX_PWM_DUTY  255
#define MIN_PWM_DUTY  0

class RobomaticsGearMotor {
  private:
    uint8_t pin1;
    uint8_t pin2;

    bool mirrorFlag;
    bool fineControlEnable;

  
  public:
    // Constructor
    RobomaticsGearMotor(uint8_t pin1, uint8_t pin2);

    // Turn the motor on with a specified speed.
    void speed(int speed);

    // Turn the motor on with a specified speed, for a given time.
    void speed(int speed, int millisec);

    // Make motor neutral
    void neutral();

    // Make motor locked
    void lock();

    // Make the operarion mirrored for robotics applications
    void mirror(bool isEnable);

    // Make the operarion mirrored for robotics applications
    void fineControlMode(bool isEnable);

};

#endif