#define DEBUG
// #define DEBUG_ACC // Activate to see potenciometer values
// #define DEBUG_BAT // Activate to see battery level

#ifdef DEBUG
  #define SERIAL_BAULRATE 115200
#endif

#define CEPin 7
#define CSPin 8

#define MOSI_PIPE_ADDR 0xE9E8F0F0B8LL
#define MISO_PIPE_ADDR 0xE9E8F0F0B9LL

#define ONLINE_Pin 3                    // MUST have an internal PULLUP resistor
#define ONLINE_PRESS_TIME 500

#define ACC_Pin A0
#define Battery_Pin A1
#define LowBatteryLed_Pin 4

#define SEND_DATA_DELAY_MS 100
#define SEND_DATA_MAX_TRIES 30
