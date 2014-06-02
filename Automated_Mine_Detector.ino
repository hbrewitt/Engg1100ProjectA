 /* Pin Mapping
 DIGITAL   2  |3|  4  |5|  |6|  7  8  |9|  |10|  |11|  12  13
           2       1   1    1   1                 3    2
 */

//Define and setup all pins/constants

#include <Wire.h> //I2C Arduino Library
#include <Servo.h> //Servo Library

 //[1] DriveTrain in PWM Mode
 const int pin_LMotor = 4;
 const int pin_LMotorE = 5; //PWM
 const int pin_RMotor = 7;
 const int pin_RMotorE = 6; //PWM

 //[2] SR04 - Range Sensor
 const int pin_SR04TRIG = 12; 
 const int pin_SR04ECHO = 2; //Input

 //[3] Marker
 const int pin_Marker = 11; //PWM

 //[4] Magnetometer
 #define address 0x1E //0011110b, I2C 7bit address of HMC5883

 //[5] Servo1
 Servo servo1; 
 int servo1pos = 0;  
 Servo servo2;
 int servo2pos = 0;

 //Constants for Drivetrain
 const int FORWARD = LOW;
 const int REVERSE = HIGH;
 const int MAX_PWR = 150;
 boolean Motor_Direction = FORWARD;

 void setup(){
   pinMode(pin_LMotor, OUTPUT);
   pinMode(pin_RMotor, OUTPUT);
   pinMode(pin_SR04TRIG, OUTPUT);
   pinMode(pin_SR04ECHO, INPUT);
   pinMode(pin_Marker, OUTPUT);
   Serial.begin(9600);
   Wire.begin();
   //Put the HMC5883 IC into the correct operating mode
   Wire.beginTransmission(address); //open communication with HMC5883
   Wire.write(0x02); //select mode register
   Wire.write(0x00); //continuous measurement mode
   Wire.endTransmission();
   servo1.attach(9);
   servo2.attach(10);
   Lower_Arm();
 }

 void loop(){
   
   Ping_Range(); //returns the distance from sr04 for testing purposes
  
   //lol
    if(Ping_Range() < 15){
      Turn(90, FORWARD);
      delay(1000);
      Move(FORWARD);
      delay(500);
      Turn(90, FORWARD);
      delay(1000);
      Move(FORWARD);
      
    } 
    else {
      Move(FORWARD);
    }
    //still unsure if this is the best way to go about it 
   if(servo1pos = 180); {
     Sweep_Arm();
   }
 
 }
