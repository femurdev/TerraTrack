#include <TMC2209.h>

TMC2209 driver1;
TMC2209 driver2;

// === Pins ===
#define STEP1 D1
#define DIR1  D2
#define EN1   D0
#define STEP2 D4
#define DIR2  D5
#define EN2   D3
#define UART_PIN D6

const long SERIAL_BAUD = 115200;
const uint8_t RUN_CURRENT_PERCENT = 100;   // 100% power
const uint8_t HOLD_CURRENT_PERCENT = 0;    // 0% hold current

const int STEP_DELAY_US = 5000;  // step speed
const long TOTAL_STEPS = 4000;  // how far to go

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== MAX POWER MODE ===");

  Serial1.begin(SERIAL_BAUD, SERIAL_8N1, UART_PIN, UART_PIN);

  // === DRIVER 1 ===
  driver1.setup(Serial1, SERIAL_BAUD, TMC2209::SERIAL_ADDRESS_0, UART_PIN, UART_PIN);
  driver1.setRunCurrent(RUN_CURRENT_PERCENT);
  driver1.setHoldCurrent(HOLD_CURRENT_PERCENT);
  driver1.setMicrostepsPerStep(1);       // full step for max torque
  driver1.disableStealthChop();          // spreadCycle = stronger torque
  driver1.enable();

  // === DRIVER 2 ===
  driver2.setup(Serial1, SERIAL_BAUD, TMC2209::SERIAL_ADDRESS_1, UART_PIN, UART_PIN);
  driver2.setRunCurrent(RUN_CURRENT_PERCENT);
  driver2.setHoldCurrent(HOLD_CURRENT_PERCENT);
  driver2.setMicrostepsPerStep(1);
  driver2.disableStealthChop();
  driver2.enable();

  // === Control pins ===
  pinMode(EN1, OUTPUT); digitalWrite(EN1, LOW); // active low
  pinMode(EN2, OUTPUT); digitalWrite(EN2, LOW);
  pinMode(DIR1, OUTPUT); digitalWrite(DIR1, HIGH);
  pinMode(DIR2, OUTPUT); digitalWrite(DIR2, HIGH);
  pinMode(STEP1, OUTPUT);
  pinMode(STEP2, OUTPUT);

  Serial.println("Drivers armed for full power!");
  delay(500);
}

void loop() {
  // move forward
  for (long i = 0; i < TOTAL_STEPS; i++) {
    digitalWrite(STEP1, HIGH);
    digitalWrite(STEP2, HIGH);
    delayMicroseconds(2);
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    delayMicroseconds(STEP_DELAY_US);
  }

  Serial.println("Done.");
}
