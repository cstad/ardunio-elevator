#include <StepperMotor.h>
#include <Stepper.h>

// Constructor
StepperMotor::StepperMotor(int motorSteps, int gearReduction, int pins[])
  : stepsPerRev{ gearReduction * motorSteps }
  , stepper{ Stepper(motorSteps, pins[0], pins[2], pins[1], pins[3]) }
 {
 }

void StepperMotor::setSpeed(long speed)
{
  stepper.setSpeed(speed);
}

void StepperMotor::move(double revolutions)
{
  long steps = stepsRequiredForRevolutions(revolutions);
  stepper.step(steps);
}

long StepperMotor::stepsRequiredForRevolutions(double revolutions)
{
  return (long) revolutions * stepsPerRev;
}