#include <Servo.h>
//#include "BluetoothSerial.h"

Servo myFinger;
Servo myWrist;
Servo myArm;
Servo myMotor;

int servoFinger = 3;  // Change to the GPIO pin you are using
int servoWrist = 2;  // Change to the GPIO pin you are using
int servoArm = 4;
int servoMotor = 5;    // Change to the GPIO pin you are using

bool FingerState;
bool WristState;
bool ArmState;
bool MotorState;

//BluetoothSerial ESP_BT;

void setup() {
  myFinger.attach(servoFinger);
  myWrist.attach(servoWrist);
  myArm.attach(servoArm);
  myMotor.attach(servoMotor);
  
 //ESP_BT.begin("car");
  Serial.begin(9600);  // Serial for debugging
}

void loop() {
  if (Serial.available()>0) {
    int command = Serial.read();
    Serial.println(command);
    if (command == 49) {

      FingerState = !FingerState;
      
      if(FingerState){
      myFinger.write(180);
      delay(1500);
      Serial.println("finger moved to 0 degrees");
      }

      else{
      myFinger.write(110);
      Serial.println("finger moved to 110 degrees");
      }

    } 
    else if (command == 51) {

      WristState = ! WristState;

      if(WristState){
      myWrist.write(0);
      delay(1500);
      Serial.println("wrist moved to 0 degrees");
      }
      else{
      myWrist.write(70);
      Serial.println("wrist moved to 180 degrees");
      }
    } 
    else if (command == 50) {

      ArmState=!ArmState;

      if(ArmState){
      myArm.write(0);
      delay(1500);
      Serial.println("arm moved to 0 degrees");
      }
      else{
      myArm.write(120);
      Serial.println("arm moved to 180 degrees");
      }
    } 
    else if (command == 52) {
      MotorState=!MotorState;

      if(MotorState){ 
        //digitalWrite(servoMotor, HIGH);
        myMotor.write(0);
        Serial.println("hello");
      }
      else{
        //digitalWrite(servoMotor, LOW);
        myMotor.write(180);
        Serial.println("hi");
      }
    } 
    
    
    // Repeat the same logic for wrist and arm servos with different commands
  } 
  
  
  //delay(5000);
}