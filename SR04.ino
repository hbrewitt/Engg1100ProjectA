long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}

long Ping_Range()
{
// establish variables for duration of the ping,
// and the distance result in inches and centimeters:
long duration, cm;
 
// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
pinMode(pin_SR04TRIG, OUTPUT);
digitalWrite(pin_SR04TRIG, LOW);
delayMicroseconds(2);
digitalWrite(pin_SR04TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(pin_SR04TRIG, LOW);
 
// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
duration = pulseIn(pin_SR04ECHO, HIGH);
 
// convert the time into a distance
cm = microsecondsToCentimeters(duration);

Serial.print("Range: ");
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);
return cm;
}
