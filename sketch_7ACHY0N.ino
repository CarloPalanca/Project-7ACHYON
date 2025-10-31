#include <AFMotor.h> //Adafruit V1 motor shield library

#define forward   255
#define turn      255

AF_DCMotor motor1(4, MOTOR34_1KHZ ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor2(1, MOTOR12_1KHZ ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency

void setup()
{
  // input pinMode only. output is covered by #include <AFMotor.h>
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop()
{
  int AINL = digitalRead(A0); // analog input sensor L
  int AINC = digitalRead(A1); // analog input sensor C
  int AINR = digitalRead(A2); // analog input sensor R

  if (!AINL && AINC && !AINR) // 010
  {
    motor1.setSpeed(forward);
    motor2.setSpeed(forward);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  else if (AINL && AINC && !AINR) //110
  {
    motor1.setSpeed(turn);
    motor2.setSpeed(turn);
    motor1.run(FORWARD);
    motor2.run(RELEASE);
  }
  else if (!AINL && AINC && AINR) //011
  {
    motor1.setSpeed(turn);
    motor2.setSpeed(turn);
    motor1.run(RELEASE);
    motor2.run(FORWARD);
  }
  else if (AINL && !AINC && !AINR) //100
  {
    motor1.setSpeed(turn);
    motor2.setSpeed(turn);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  }
  else if (!AINL && !AINC && AINR) //001
  {
    motor1.setSpeed(turn);
    motor2.setSpeed(turn);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }
}
