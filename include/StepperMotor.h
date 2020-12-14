#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <Stepper.h>

class StepperMotor
{
  private:
    int stepsPerRev;
    Stepper stepper;
  protected:
    long stepsRequiredForRevolutions(double);
  public:
    StepperMotor(int, int, int[]);
    void setSpeed(long);
    void move(double);
};

#endif