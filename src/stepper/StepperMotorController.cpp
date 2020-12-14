#include<StepperMotorController.h>
#include<StepperMotor.h>

const int MOVE_SPEED = 700;
const int LEVELING_SPEED = 200;
const double LEVELING_REVS = 1;

StepperMotorController::StepperMotorController(int pins[], double floorHeightInRevs, int maxFloors)
  : floorHeightInRevs(floorHeightInRevs)
  , maxFloors(maxFloors), stepper(32, 64, pins)
{
}

bool StepperMotorController::isMoving()
{
  return moving;
}

void StepperMotorController::reset()
{
  // TODO: Implement proximity switch to know when car is at first floor
  currentFloor = 1;
  setMoving(false);
}

// TODO: Implement up by revs
void StepperMotorController::upFloors(int numFloors)
{
  if (numFloors > 0 && !isMoving()) {
    if (currentFloor + numFloors <= maxFloors) {
      moveToFloor(numFloors * floorHeightInRevs);
      setCurrentFloor(currentFloor + numFloors);
    }
  }
}

// TODO: Implement down by revs
void StepperMotorController::downFloors(int numFloors)
{
  if (numFloors < 0 && !isMoving()) {
    if (currentFloor + numFloors >= 1) {
      moveToFloor(numFloors * floorHeightInRevs);
      setCurrentFloor(currentFloor + numFloors);
    }
  }
}

// TODO: Implement move by revs
void StepperMotorController::moveToFloor(double revolutions)
{
  double slowRevs = LEVELING_REVS;
  
  if (revolutions < 0) {
    slowRevs = -LEVELING_REVS;
  }

  setMoving(true);

  // Move car
  stepper.setSpeed(MOVE_SPEED);
  stepper.move(revolutions - slowRevs);
  // Level car
  stepper.setSpeed(LEVELING_SPEED);
  stepper.move(slowRevs);

  setMoving(false);
}

void StepperMotorController::setMoving(bool movin)
{
  moving = movin;
}

int StepperMotorController::getCurrentFloor()
{
  return currentFloor;
}

void StepperMotorController::setCurrentFloor(int floor)
{
  if (floor > 0 && floor <= maxFloors) {
    currentFloor = floor;
  }
}