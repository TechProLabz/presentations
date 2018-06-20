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

//servo pwm pin
int servo_pin=3;

//setting the ultrasound pins
int trigger_pin_forward = 7;
int echo_pin_forward = 6;
int trigger_pin_right = 8;
int echo_pin_right = 9;
int trigger_pin_left = 10;
int echo_pin_left = 11;

//ostacle distance
int od = 5;
int delaytime = 1500;

void setup() {
 Serial.begin(9600);
 
 pinMode(trigger_pin_forward,OUTPUT);
 pinMode(echo_pin_forward,INPUT);
 pinMode(trigger_pin_right,OUTPUT);
 pinMode(echo_pin_right,INPUT);
 pinMode(trigger_pin_left,OUTPUT);
 pinMode(echo_pin_left,INPUT);
 
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
  motor2.run(BACKWARD);
}

void right(){
   motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void backward(){
   motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void stop_bot(){
 motor1.run(RELEASE);
  motor2.run(RELEASE); 
}

int ultrasound_ping(trigger_pin,echo_pin){
  //clear trigger pin
  digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);

  //set the trigger pin HIGH for 10 micoseconds
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);

  //Read the echo pin and get the sound travel time
  long duration = pulseIn(echo_pin,HIGH);

  //calculating distance
  int distance = 0.034*duration/2;

  if(distance<=od)return 1;
  else return 0;
}

void loop() {
    int df = ultrasound_ping(trigger_pin_forward,echo_pin_forward);
    int dr = ultrasound_ping(trigger_pin_right,echo_pin_right);
    int dl = ultrasound_ping(trigger_pin_left,echo_pin_left);

    if(dr==1 && df==0 && dl==0){
      forward();
      delay(500);
    }
    else if(dr==1 && df==1 && dl==0){
      right();
      delay(delaytime);
    }
    else if(dr==0 && df==0 && dl==0){
      left();
      delay(delaytime);
    }
    else if(dr==0 && df==1 && dl==1){
      left();
      delay(delaytime);
    }
    else if(dr==1 && df==0 && dl==1){
      forward();
      delay(delaytime);
    }
    else if(dr==1 && df==1 && dl==1){
      right();
      delay(delaytime*2);
    }
    else if(dr==0 && df==1 && dl==0){
      right();
      delay(delaytime);
    }
    else if(dr==0 && df==0 && dl==1){
      forward();
      delay(delaytime);
    }
    else{
      forward();
      delay(500);
    }
}
