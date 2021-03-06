#include <SPI.h>
#include "RF24.h"

bool online = false;

#include "config.h"
#include "rcData.h"
#include "accelerator.h"
#include "battery.h"
#include "debugger.h"
#include "onlineButton.h"
#include "radio.h"

void setup() {

#ifdef DEBUG
  setupDebug();
#endif

  setupBatteryLevel();
  setupAccelerator();
  setupLatchingButton();
  setupRadio();
}

void loop() {
  readAccelerator();
  online = getLatchingState(online);
  
  if (online)  {
    online = sendRadioData();
  }

  checkBatteryLevel();

#ifdef DEBUG
  loopDebug();
#endif
}
