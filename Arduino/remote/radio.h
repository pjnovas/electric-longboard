
RF24 radio(CEPin, CSPin);

unsigned long radio_delay_lastTime = 0;
uint8_t conn_tries = 0;

void setupRadio() {
  radio.begin();
  radio.setAutoAck(1);
  radio.setPALevel(RF24_PA_LOW);
  
  radio.openWritingPipe(MOSI_PIPE_ADDR);
  radio.openReadingPipe(1, MISO_PIPE_ADDR);

  radio.startListening();
}

bool sendRadioData() {
  if (millis() - radio_delay_lastTime > SEND_DATA_DELAY_MS) {
    
    radio.stopListening();
    unsigned long start_time = micros();
  
#ifdef DEBUG
    Serial.print(F("Now sending - "));
    Serial.print(start_time); 
#endif
  
    bool ack = radio.write(&start_time, sizeof(unsigned long));
      
    radio.startListening();
    radio_delay_lastTime = millis();

    if (!ack) {
      conn_tries++;
    } else {
      conn_tries = 0;
    }

#ifdef DEBUG
    if (!ack){
      Serial.print(F(" - Failed - TRY: "));
      Serial.println(conn_tries);
    } else {
      Serial.println(F(" - OK"));
    }
#endif

    if (conn_tries > SEND_DATA_MAX_TRIES) {
      conn_tries = 0;
#ifdef DEBUG
      Serial.println(F("OFFLINE TIMEOUT: MAX TRIES REACHED"));
#endif
      return false; // returns an OFFLINE state
    }

    return true;
  }
}
