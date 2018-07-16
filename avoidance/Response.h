/*
 * desc : fetch current distance
 * retn : distence on unit cm
 */
float ultrasonic_distance_3_2() {
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  delayMicroseconds(5);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  unsigned long sonic_duration = pulseIn(2, HIGH);
  float distance_cm = (sonic_duration / 2.0) / 29.1;
  return distance_cm;
}

/*
 * desc : multiple fetching current front distance and calculating average distance
 * retn : distence on unit cm
 */
float ultrasonic_distance() {
  float totalDistance = 0.0;
  for(int i = 0 ; i < ultrasonicDetectDistSample ; i++) {
    totalDistance += ultrasonic_distance_3_2();
    delayMicroseconds(ultrasonicDetectDistMSPeroid);
  }
  return (totalDistance / ultrasonicDetectDistSample);
}

void forward() {
  digitalWrite(10,HIGH);
  analogWrite(5,200);
  digitalWrite(11,HIGH);
  analogWrite(6,200);
}

void backward() {
  digitalWrite(10,LOW);
  analogWrite(5,200);
  digitalWrite(11,LOW);
  analogWrite(6,200);
}

void right() {
  digitalWrite(10,LOW);
  analogWrite(5,200);
  digitalWrite(11,HIGH);
  analogWrite(6,200);
}

void left() {
  digitalWrite(10,HIGH);
  analogWrite(5,200);
  digitalWrite(11,LOW);
  analogWrite(6,200);
}

void stop() {
  analogWrite(5,0);
  analogWrite(6,0);
}
