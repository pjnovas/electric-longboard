#include <SPI.h>
#include "RF24.h"

#include "config.h"
#include "rcData.h"

RF24 radio(CEPin, CSPin);

void setup() {
  
#ifdef DEBUG
  Serial.begin(SERIAL_BAULRATE);
  Serial.println("STARTED RECEIVER - THIS DUDE JUST LISTENS");
#endif
  
  radio.begin();
  radio.setAutoAck(1);
  radio.setPALevel(RF24_PA_LOW);
  
  radio.openWritingPipe(MISO_PIPE_ADDR);
  radio.openReadingPipe(1, MOSI_PIPE_ADDR);
  
  radio.startListening();
}

void loop() {
  unsigned long got_time;
  
  if( radio.available()){
    
    radio.read(&data, sizeof(RcData));

#ifdef DEBUG
    Serial.print(F("Got Data "));
    Serial.println(data.acc);
#endif
  }
 
}
