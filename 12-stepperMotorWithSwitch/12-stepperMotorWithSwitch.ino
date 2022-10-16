
#include <AccelStepper.h>

const int stepsPerRevolution = 4096;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 D1
#define IN2 D2
#define IN3 D5
#define IN4 D6

int swithInput = D7;
int startRotationInput = D3;
bool rotation, isLeftRotation;

// AccelStepper::HALF4WIRE -> to indicate we’re controlling the stepper motor with four wires
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

void setup() {
  // initialize the serial port
  Serial.begin(115200);

  rotation = true;

  // set the speed and acceleration
  stepper.setMaxSpeed(600);
  stepper.setAcceleration(150);

  // set target position
  stepper.runToNewPosition(stepsPerRevolution);
  isLeftRotation = false;
  
  pinMode(swithInput, INPUT_PULLUP);
  pinMode(startRotationInput, INPUT);
  attachInterrupt(digitalPinToInterrupt(swithInput), limitSwitch, RISING);
  attachInterrupt(digitalPinToInterrupt(startRotationInput), startRotation, FALLING);
}

void loop() {

  if (rotation) {
    // check current stepper motor position to invert direction
    // if (stepper.distanceToGo() == 0){
    //   stepper.moveTo(-stepper.currentPosition());
    //   Serial.println("Changing direction");
    // }
    if (stepper.distanceToGo() == 0) {
      // isLeftRotation = !isLeftRotation;
      stepper.move(getDirection() * stepsPerRevolution);      
    }

    // move the stepper motor (one step at a time)
    stepper.run();
  }

  // delay(500);
}

ICACHE_RAM_ATTR void limitSwitch() {
  Serial.println("FINE CORSA CLICCATO");
  
  isLeftRotation = !isLeftRotation;
  stepper.setCurrentPosition(0);
  stepper.setMaxSpeed(600);
  stepper.setAcceleration(150);

  rotation = false;
}

int getDirection() {
  if (isLeftRotation) {
    return -1;
  } else {
    return 1;
  }
}

ICACHE_RAM_ATTR void startRotation() {
  Serial.println("ENTRA start rotation");
  
  rotation = true;
}


