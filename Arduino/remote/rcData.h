// The size of this struct should not exceed 32 bytes

const uint8_t ACC_BRAKE[] = {0, 40};
const uint8_t ACC_IDLE[] = {40, 50};
const uint8_t ACC_FORWARD[] = {50,100};

struct RcData {
  // 0 to 40 brakes 
  // 40 to 55 idle 
  // 55 to 100 forward
  byte acc;

  // Future Features
  // boolean mode = false; // Mode (toggle speed limit)
  // boolean invert = false; // Invert motor direction
};

RcData data;
