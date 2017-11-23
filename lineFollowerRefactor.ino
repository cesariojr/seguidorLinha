#include <Wire.h>
#include <AFMotor.h>

const int rightSensorPin = 2;
const int leftSensorPin = 0;

AF_DCMotor rightMotor(3, MOTOR12_1KHZ);
AF_DCMotor leftMotor(4);

#define RIGHT_MOTOR_DEFAULT_SPEED 75
#define LEFT_MOTOR_DEFAULT_SPEED 75
#define RIGHT_MOTOR_MAX_SPEED 130
#define LEFT_MOTOR_MAX_SPEED 130

void setup() {
  delay(2000);
}

void loop() {
  int rightSensorValue = analogRead(rightSensorPin);
  int leftSensorValue = analogRead(leftSensorPin);
 
 if (rightSensorValue >= 300 && leftSensorValue < 300) {
      rightMotor.run(RELEASE);
      leftMotor.run(FORWARD);
      leftMotor.setSpeed(LEFT_MOTOR_DEFAULT_SPEED);
  }
  else if (rightSensorValue < 300 && leftSensorValue >= 300) {
      rightMotor.run(FORWARD);
      leftMotor.run(RELEASE);
      righMotor.setSpeed(RIGHT_MOTOR_DEFAULT_SPEED);
  }
  else {
      rightMotor.run(FORWARD);
      leftMotor.run(FORWARD);
      rightMotor.setSpeed(RIGHT_MOTOR_DEFAULT_SPEED);
      leftMotor.setSpeed(LEFT_MOTOR_DEFAULT_SPEED);
  }
}
