#include <SPI.h>
#include "RF24.h"

bool online = false;

#include "config.h"
#include "debugger.h"
#include "online_button.h"
#include "radio.h"

void setup() {

#ifdef DEBUG
  setupDebug();
#endif

  setupLatchingButton();
  setupRadio();
}

void loop() {
  online = getLatchingState(online);
  
  if (online)  {
    online = sendRadioData();
  }

#ifdef DEBUG
  loopDebug();
#endif
}
