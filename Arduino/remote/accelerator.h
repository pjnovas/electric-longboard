
void setupAccelerator() {
  pinMode(ACC_Pin, INPUT);
}

void readAccelerator() {
  data.acc = constrain(
    map(analogRead(ACC_Pin), 0, 1023, 0, 100)
  , 0, 100);

#ifdef DEBUG_ACC
  Serial.print("Read Acceleration: ");
  Serial.println(data.acc);
#endif
}
