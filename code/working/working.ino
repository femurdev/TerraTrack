#include <TMC2209.h>

// Create two driver instances
TMC2209 driver1;
TMC2209 driver2;

// Pin configuration
const int UART_PIN = D6;   // Shared PDN_UART (GPIO21)
const int EN1_PIN  = D0;   // Enable for driver 1
const int EN2_PIN  = D3;   // Enable for driver 2 (new)
const int STEP1_PIN = D1;  // Step for driver 1
const int DIR1_PIN  = D2;  // Dir for driver 1
const int STEP2_PIN = D4;  // Step for driver 2
const int DIR2_PIN  = D5;  // Dir for driver 2

const long SERIAL_BAUD = 115200;

// Current settings
const uint8_t RUN_CURRENT_PERCENT = 100;
const uint8_t HOLD_CURRENT_PERCENT = 0;

// Delay between mode switches
const int DELAY_MS = 4000;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting dual TMC2209 on XIAO ESP32-C3...");

  // Initialize UART (half-duplex)
  Serial1.begin(SERIAL_BAUD, SERIAL_8N1, UART_PIN, UART_PIN);

  // --- Driver 1 setup ---
  driver1.setup(Serial1, SERIAL_BAUD, TMC2209::SERIAL_ADDRESS_0, UART_PIN, UART_PIN);
  driver1.setRunCurrent(RUN_CURRENT_PERCENT);
  driver1.setHoldCurrent(HOLD_CURRENT_PERCENT);
  driver1.enable();

  // --- Driver 2 setup ---
  driver2.setup(Serial1, SERIAL_BAUD, TMC2209::SERIAL_ADDRESS_1, UART_PIN, UART_PIN);
  driver2.setRunCurrent(RUN_CURRENT_PERCENT);
  driver2.setHoldCurrent(HOLD_CURRENT_PERCENT);
  driver2.enable();

  // Configure motion control pins
  pinMode(STEP1_PIN, OUTPUT);
  pinMode(DIR1_PIN, OUTPUT);
  pinMode(EN1_PIN, OUTPUT);
  digitalWrite(EN1_PIN, LOW); // Enable driver 1

  pinMode(STEP2_PIN, OUTPUT);
  pinMode(DIR2_PIN, OUTPUT);
  pinMode(EN2_PIN, OUTPUT);
  digitalWrite(EN2_PIN, LOW); // Enable driver 2

  driver1.setStandstillMode(driver1.NORMAL);
  driver2.setStandstillMode(driver2.NORMAL);

  Serial.println("Both TMC2209 drivers initialized successfully!");
}

void loop() {
  // Cycle through different standstill modes on both drivers
  Serial.println("Standstill mode = NORMAL");
  driver1.setStandstillMode(driver1.NORMAL);
  driver2.setStandstillMode(driver2.NORMAL);
  delay(DELAY_MS);

  Serial.println("Standstill mode = FREEWHEELING");
  driver1.setStandstillMode(driver1.FREEWHEELING);
  driver2.setStandstillMode(driver2.FREEWHEELING);
  delay(DELAY_MS);

  Serial.println("Standstill mode = STRONG_BRAKING");
  driver1.setStandstillMode(driver1.STRONG_BRAKING);
  driver2.setStandstillMode(driver2.STRONG_BRAKING);
  delay(DELAY_MS);

  Serial.println("Standstill mode = BRAKING");
  driver1.setStandstillMode(driver1.BRAKING);
  driver2.setStandstillMode(driver2.BRAKING);
  delay(DELAY_MS);

  Serial.println();
}
