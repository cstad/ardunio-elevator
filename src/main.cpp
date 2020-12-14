#include <Arduino.h>
#include <Remote.h>
#include <StepperMotorController.h>

const String APP_NAME = "Ardunio Elevator";
const int REMOTE_PIN = 7;
int stepperPins[4] = {8, 9, 10, 11};

// Remote
Remote remote(REMOTE_PIN);

// Stepper Motor Controller
StepperMotorController stepperController(stepperPins, 4.445, 3);

void setup()
{
  Serial.begin(9600);
  remote.enableIRIn();
  Serial.println("Hello, " + APP_NAME);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (remote.hasValue()) {
    int floor = remote.getValue();
    Serial.println("User selected floor");
    Serial.println(floor);

    int currentFloor = stepperController.getCurrentFloor();

    if (floor > 0 && floor != currentFloor) {
      Serial.println("elevator is on floor:");
      Serial.println(currentFloor);
      Serial.println("moving to floor:");
      Serial.println(floor);
      if (floor < currentFloor) {
        stepperController.downFloors(floor - currentFloor);
      } else {
        stepperController.upFloors(floor - currentFloor);
      }
    }

    delay(500);
    remote.resume();
  }
}