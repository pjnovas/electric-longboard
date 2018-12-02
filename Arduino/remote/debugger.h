
void setupDebug() {
  Serial.begin(SERIAL_BAULRATE);
  Serial.println(F("STARTED TRANSIMITER - PRESS BUTTON TO START SENDING"));
}

void loopDebug() {
  if ( Serial.available() ) {
    char c = toupper(Serial.read());
    if ( c == 'T' && online == false ){      
      online = true;
    } else if ( c == 'R' && online == true ) {
      online = false;
    }
  }
}
