void Move(boolean direction){
  int pwr;
  //Convert speed from percentage to analog pwr
  //pwr = 255 * (speed/100);
  digitalWrite(pin_LMotor, direction);
  digitalWrite(pin_RMotor, direction);
  for(pwr = 0; pwr <= MAX_PWR; pwr += 5) {
    analogWrite(pin_LMotorE, pwr-10);
    analogWrite(pin_RMotorE, pwr);
    //delay(30); //Why delay here?
  } 
}

void Turn(byte theta, boolean direction) {
  if (theta > 0){//Turn Right
    digitalWrite(pin_RMotor, !direction);
  }else if(theta < 0){//Turn Left
    digitalWrite(pin_LMotor, !direction);
  }
}

void Motor_PowerDown(){
  int pwr;
  for(pwr = Check_MotorPWR(); pwr >=15; pwr -= 15) {
    analogWrite(pin_LMotorE, pwr-10);
    analogWrite(pin_RMotorE, pwr);
    delay(30);
  }
  Serial.println(Check_MotorPWR());
  digitalWrite(pin_LMotorE, LOW);
  digitalWrite(pin_RMotorE, LOW);
  Serial.println(Check_MotorPWR());
}

int Check_MotorPWR(){
  int val = (analogRead(pin_LMotorE) + analogRead(pin_RMotorE))/2;    // read the value from the sensor
  return map(val, 0, 1023, 0, 255);  // make val a number between 0 
}
