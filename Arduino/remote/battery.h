
const uint8_t BatteryPercentageLOW = 20;

void setupBatteryLevel() {
  pinMode(Battery_Pin, INPUT);
  pinMode(LowBatteryLed_Pin, OUTPUT);
}

void checkBatteryLevel() {
  // TODO: Add a check Battery on a period (like each minute or so)
  
  uint8_t percentage = constrain(
    map(analogRead(Battery_Pin), 900, 1023, 0, 100)
  , 0, 100);

#ifdef DEBUG_BAT
  Serial.print("Battery Level at: ");
  Serial.print(percentage);
#endif

  if (percentage <= BatteryPercentageLOW) {
    digitalWrite(LowBatteryLed_Pin, HIGH);
  } else {
    digitalWrite(LowBatteryLed_Pin, LOW);
  }

}
