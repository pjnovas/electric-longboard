byte btn_current; // (LOW equals pressed - internal pullup resistor)

unsigned long btn_lastTime = 0;
byte btn_previous = HIGH;

void setupLatchingButton() {
  pinMode(ONLINE_Pin, INPUT_PULLUP);
}

bool getLatchingState(bool state) {
  btn_current = digitalRead(ONLINE_Pin);

  if (btn_current != btn_previous) { // pressed changed state
    
    if (btn_current == LOW){ // just started pressing

      btn_lastTime = millis();

#ifdef DEBUG
      Serial.println(F("ONLINE BUTTON PRESSED"));
#endif

    } else if ((millis() - btn_lastTime) > ONLINE_PRESS_TIME) { // just released      
    
      btn_previous = btn_current;
      bool newState = !state;
      
#ifdef DEBUG
      if (newState){
        Serial.println(F(">> ONLINE ------"));
      } else {
        Serial.println(F("XX OFFLINE -----"));
      }
#endif

      return newState;
    }
 
    btn_previous = btn_current;
  }
  
  return state;
}
