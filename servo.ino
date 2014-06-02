void Lower_Arm() {                              
    servo1.write(180);                    // puts servo at full extension  
}

void Sweep_Arm() { 
  for(servo2pos = 0; servo2pos < 190; servo2pos += 2)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 2 degree 
    servo2.write(servo2pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(servo2pos = 180; servo2pos>=0; servo2pos-=2)     // goes from 180 degrees to 0 degrees 
  {                                
    servo2.write(servo2pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
}
