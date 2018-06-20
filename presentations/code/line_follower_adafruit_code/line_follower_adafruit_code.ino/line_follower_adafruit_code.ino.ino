/*
 Line follower robot:
   Line follower is an autonomous robot which follows 
   either black line in white surface or white line in black surface.
   Robot must be able to detect particular line and keep following it.
   HARDWARE REQUIRED:-
   ARDUINO UNO:-1
   POWER CABLE:-1
   ADAFRUIT MOTOR DRIVER SHIELD:-1
   DC GEARED MOTOR:-2
   IR SENSORS:-2
   CHASSIS:-1
   WHEELS:-2
   CASTER WHEEL:-1
   JUMPER WIRE:-6
   BATTERY:-2
    The circuit:
    -analog 1 (A1): input pin for sensor1
    -analog 2 (A2): input pin for sensor2
    -motors2: output pin for motor1
    -motor3: output pin for motor2
    
   created and developed at 15 06 2018
   by Sushant Singh
   organisation:- Techprolabz The School Of Robotics
*/

#include <AFMotor.h>
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);


void setup() {
 Serial.begin(9600);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 motor1.setSpeed(150);   //set your motor speed acording to your motor specifications  
 motor2.setSpeed(150);
 motor1.run(RELEASE);
 motor2.run(RELEASE);

}

void forward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void left(){
   motor1.run(FORWARD);
  motor2.run(RELEASE);
}

void right(){
   motor1.run(RELEASE);
  motor2.run(FORWARD);
}

void stop_bot(){
 motor1.run(RELEASE);
  motor2.run(RELEASE); 
}

void loop() {
  int sense1=digitalRead(A1);
  int sense2=digitalRead(A2);
if ((sense1==1)&&(sense2==1))
{
  Serial.print("f");  // forward direction
  forward();
}
if ((sense1==1)&&(sense2==0)) //left direction
{
  Serial.print("l");
  left();
}
if((sense1==0)&&(sense2==1))  // right direction
{
  Serial.print("r");
  right();
}
if((sense1==0)&&(sense2==0))   //stop
{
  Serial.print("s");
 stop_bot();
}
}
