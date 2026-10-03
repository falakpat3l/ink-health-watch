// ink-health-watch firmware entry point.
//
// Day 1 (v0.1.0-alpha): boot banner only. It keeps the board powered from
// the battery, prints the version and pin map over USB serial, and reads
// the battery voltage once a minute. Display, IMU and logging come later
// (see ROADMAP.md).

#include <Arduino.h>

#include "board_pins.h"
#include "version.h"

namespace {

float readBatteryVolts() {
  const uint32_t millivolts = analogReadMilliVolts(ink::pins::kBatteryAdc);
  return (millivolts / 1000.0f) * ink::pins::kBatteryDividerRatio;
}

void printBanner() {
  Serial.println();
  Serial.println("ink-health-watch " INK_VERSION);
  Serial.println("Research and portfolio prototype, not a medical device.");
  Serial.printf("I2C: SDA=%u SCL=%u\n", ink::pins::kI2cSda, ink::pins::kI2cScl);
  Serial.printf("e-paper: CS=%u DC=%u RST=%u BUSY=%u\n", ink::pins::kEpdCs,
                ink::pins::kEpdDc, ink::pins::kEpdRst, ink::pins::kEpdBusy);
}

}  // namespace

void setup() {
  // Hold the battery latch so the board stays on when running from the LiPo.
  pinMode(ink::pins::kBatteryLatch, OUTPUT);
  digitalWrite(ink::pins::kBatteryLatch, HIGH);

  // Keep the display and audio blocks off until they are used.
  pinMode(ink::pins::kEpdPowerEn, OUTPUT);
  digitalWrite(ink::pins::kEpdPowerEn, HIGH);
  pinMode(ink::pins::kAudioPowerEn, OUTPUT);
  digitalWrite(ink::pins::kAudioPowerEn, HIGH);

  Serial.begin(115200);
  delay(1500);  // give USB CDC time to enumerate
  printBanner();
}

void loop() {
  Serial.printf("battery: %.2f V\n", readBatteryVolts());
  delay(60UL * 1000UL);
}
