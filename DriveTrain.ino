 void Move(boolean direction){
   int pwr;
   //Convert speed from percentage to analog pwr
   //pwr = 255 * (speed/100);
   for(pwr = 0; pwr <= 150; pwr += 5) {
     analogWrite(pin_LMotorE, pwr);
     analogWrite(pin_RMotorE, pwr);
     delay(30);
   } 
   digitalWrite(pin_LMotor, direction);
   digitalWrite(pin_RMotor, direction);
 }

 void Turn(byte theta, boolean direction) {
   if (theta > 0){//Turn Right
     digitalWrite(pin_RMotor, !direction);
   }else if(theta < 0){//Turn Left
     digitalWrite(pin_LMotor, !direction);
   }
 }

 void HardTurn(byte theta, boolean direction) {
   if (theta > 0){//HardTurn Right
     digitalWrite(pin_RMotor, !direction);
     digitalWrite(pin_LMotor, direction);
   }else if(theta < 0){//HardTurn Left
     digitalWrite(pin_LMotor, !direction);
     digitalWrite(pin_RMotor, direction);
   }
 }

 void Motor_PowerDown(){
   int pwr;
   for(pwr = 255; pwr >=15; pwr -= 15) {
     analogWrite(pin_LMotorE, pwr);
     analogWrite(pin_RMotorE, pwr);
     delay(30);
   }
   digitalWrite(pin_LMotorE, LOW);
   digitalWrite(pin_RMotorE, LOW);
 }
