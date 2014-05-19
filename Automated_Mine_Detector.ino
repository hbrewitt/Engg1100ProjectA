 /* Pin Mapping
 DIGITAL   2  |3|  4  |5|  |6|  7  8  |9|  |10|  |11|  12  13
           2       1   1    1   1                 3    2
 */

//Define and setup all pins/constants

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

 //Constants for Drivetrain
 const int FORWARD = LOW;
 const int REVERSE = HIGH;
 boolean Motor_Direction = FORWARD;

 void setup(){
   pinMode(pin_LMotor, OUTPUT);
   pinMode(pin_RMotor, OUTPUT);
   pinMode(pin_SR04TRIG, OUTPUT);
   pinMode(pin_SR04ECHO, INPUT);
   pinMode(pin_Marker, OUTPUT);
   Serial.begin(9600);
 }

 void loop(){
  if(Ping_Range() < 10){
      HardTurn(120, FORWARD);
      delay(100);
      
  while(Ping_Range() > 10 {
        Move(FORWARD);
        if(detSignal > xyz) {
          Mark(HIGH)
          
      } 
         
  }
 
 }
