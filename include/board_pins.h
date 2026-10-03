// Pin map for the Waveshare ESP32-S3-ePaper-1.54 (V2, no touch).
//
// Source: Waveshare schematic "ESP32-S3-Touch-ePaper-1.54-Schematic.pdf"
// (GPIO table and header J1) and user_config.h in the official Arduino
// examples: https://github.com/waveshareteam/ESP32-S3-ePaper-1.54
// Checked on 3 Oct 2026. Not yet verified on real hardware.
#pragma once

#include <stdint.h>

namespace ink::pins {

// e-paper (SPI, 200x200 black/white)
constexpr uint8_t kEpdBusy = 8;
constexpr uint8_t kEpdRst = 9;
constexpr uint8_t kEpdDc = 10;
constexpr uint8_t kEpdCs = 11;
constexpr uint8_t kEpdSck = 12;
constexpr uint8_t kEpdMosi = 13;

// Power switches. EPD and audio are ON when the pin is LOW.
// The battery latch keeps the board powered when the pin is HIGH.
constexpr uint8_t kEpdPowerEn = 6;
constexpr uint8_t kAudioPowerEn = 42;
constexpr uint8_t kBatteryLatch = 17;

// Buttons
constexpr uint8_t kBootButton = 0;   // also usable as a deep sleep wake pin
constexpr uint8_t kPowerButton = 18;

// Battery voltage: ADC1 channel 3, behind a 1:2 divider (200k / 200k)
constexpr uint8_t kBatteryAdc = 4;
constexpr float kBatteryDividerRatio = 2.0f;

// Shared I2C bus: RTC, SHTC3, audio codec, and our MPU6050 on header J1
constexpr uint8_t kI2cSda = 47;
constexpr uint8_t kI2cScl = 48;
constexpr uint8_t kRtcInt = 5;

// microSD (SD_MMC, 1-bit mode)
constexpr uint8_t kSdClk = 39;
constexpr uint8_t kSdCmd = 41;
constexpr uint8_t kSdD0 = 40;

// Free GPIO on header J1, planned for the MPU6050 INT line (RTC capable,
// so it can wake the chip from deep sleep).
constexpr uint8_t kImuInt = 1;

}  // namespace ink::pins

namespace ink::i2c_addr {

constexpr uint8_t kRtcPcf85063 = 0x51;
constexpr uint8_t kShtc3 = 0x70;
constexpr uint8_t kEs8311 = 0x18;  // 7-bit form of 0x30
constexpr uint8_t kMpu6050 = 0x68;  // AD0 left low on the GY-521

}  // namespace ink::i2c_addr
