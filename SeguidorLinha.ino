
#include <Wire.h>
#include <AFMotor.h>

const int SensorDireito = 2; // Sensor do lado direito - pino A2 - Visto de tras para frente
const int SensorEsquerdo = 0; // Sensor do lado esquerdo - pino A0

AF_DCMotor motor1(3, MOTOR12_1KHZ); // Motor Direito - Born 1 e 1kHz pwm - Visto de tras para frente
AF_DCMotor motor4(4); // Motor Esquerdo - Born 4 e 1kHz pwm - Motores 3 e 4 apenas em 1kHz

#define M1_DEFAULT_SPEED 75
#define M4_DEFAULT_SPEED 75
#define M1_MAX_SPEED 130
#define M4_MAX_SPEED 130

void setup() {
  delay(2000);
}

void loop() {
  int sLadoDireito = analogRead(SensorDireito);
  int sLadoEsquerdo = analogRead(SensorEsquerdo);
 
 if (sLadoDireito >= 300 && sLadoEsquerdo < 300) {
      motor1.run(RELEASE);
      motor4.run(FORWARD);
      motor4.setSpeed(M4_DEFAULT_SPEED);
  }
  else if (sLadoDireito < 300 && sLadoEsquerdo >= 300) {
      motor1.run(FORWARD);
      motor4.run(RELEASE);
      motor1.setSpeed(M1_DEFAULT_SPEED);
  }
  else {
      motor1.run(FORWARD);
      motor4.run(FORWARD);
      motor1.setSpeed(M1_MAX_SPEED);
      motor4.setSpeed(M4_MAX_SPEED);
  }
}
