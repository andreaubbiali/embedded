
#include <AccelStepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 5  //D1
#define IN2 4  //D2
#define IN3 14 //D5
#define IN4 12 //D6

int swithInput = D7;
int startRotationInput = D3;
bool isStarting, rotation;

// AccelStepper::HALF4WIRE -> to indicate we’re controlling the stepper motor with four wires
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

void setup() {
  // initialize the serial port
  Serial.begin(115200);

  isStarting = true;
  rotation = true;

  // set the speed and acceleration
  stepper.setMaxSpeed(500);
  stepper.setAcceleration(100);

  // set target position
  stepper.runToNewPosition(stepsPerRevolution);
  
  pinMode(swithInput, INPUT);
  pinMode(startRotationInput, INPUT);
  attachInterrupt(digitalPinToInterrupt(swithInput), limitSwitch, FALLING);
  attachInterrupt(digitalPinToInterrupt(startRotationInput), startRotation, FALLING);
}

void loop() {

  if (rotation) {
    // check current stepper motor position to invert direction
    if (stepper.distanceToGo() == 0){
      stepper.moveTo(-stepper.currentPosition());
      Serial.println("Changing direction");
    }
    // move the stepper motor (one step at a time)
    stepper.run();
  }

  // delay(500);
}

ICACHE_RAM_ATTR void limitSwitch() {
  Serial.println("FINE CORSA CLICCATO");

  if (isStarting) {
    stepper.setCurrentPosition(0);
    stepper.move(stepsPerRevolution);
    isStarting = false;
  }
  rotation = false;
}

ICACHE_RAM_ATTR void startRotation() {
  Serial.println("ENTRA start rotation");

  rotation = true;
}


