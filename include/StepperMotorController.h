#ifndef STEPPER_MOTOR_CONTROLLER_H
#define STEPPER_MOTOR_CONTROLLER_H

#include <StepperMotor.h>

class StepperMotorController
{
  private:
    double floorHeightInRevs;
    int maxFloors;
    StepperMotor stepper;
    bool moving = false;
    int currentFloor = 1;
  protected:
    void setMoving(bool);
    void setCurrentFloor(int);
    void moveToFloor(double);
  public:
    StepperMotorController(int[], double, int);
    bool isMoving();
    int getCurrentFloor();
    void upFloors(int);
    void downFloors(int);
    void reset();
};

#endif