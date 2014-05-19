void Activate_Marker(){
  //Set spray duration
  long spray_duration = 1000;
  
  int pwr;
  for(pwr = 135; pwr <=255; pwr += 15) {
    analogWrite(pin_Marker, pwr);
    delay(30);  //once marker is at full power, hold steady for 0.03seconds
  }
  
  delay(spray_duration);
  
  //Power down pump
  for(pwr = 255; pwr >=60; pwr -= 15) {
    analogWrite(pin_Marker, pwr);
    delay(30);
  }
  digitalWrite(pin_Marker, LOW);
}
