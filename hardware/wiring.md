# Wiring

Sources: Waveshare schematic (GPIO table and header J1) and the official
example code, <https://github.com/waveshareteam/ESP32-S3-ePaper-1.54>.
Not yet checked on real hardware: confirm with a multimeter before powering.

## Header J1 (2x6, 2.54 mm)

| Pin | Signal | Pin | Signal |
| --- | --- | --- | --- |
| 1 | GPIO1 | 2 | VSYS |
| 3 | GPIO2 | 4 | 3V3 |
| 5 | GPIO3 | 6 | GND |
| 7 | GPIO19 (USB D-) | 8 | GPIO48 (I2C SCL) |
| 9 | GPIO20 (USB D+) | 10 | GPIO47 (I2C SDA) |
| 11 | GPIO43 (UART TX) | 12 | GPIO44 (UART RX) |

## MPU6050 (GY-521) to J1

| GY-521 pin | J1 pin | Board signal |
| --- | --- | --- |
| VCC | 4 | 3V3 |
| GND | 6 | GND |
| SCL | 8 | GPIO48 |
| SDA | 10 | GPIO47 |
| INT | 1 | GPIO1 (wake from deep sleep, used later) |
| AD0 | not connected | address stays 0x68 |
| XDA, XCL | not connected | |

Notes:

- Use **3V3 (pin 4), never VSYS (pin 2)**. VSYS is the raw system supply.
- The I2C bus is shared. Addresses in use: RTC PCF85063 `0x51`, SHTC3
  `0x70`, ES8311 codec `0x18`, MPU6050 `0x68`. No clashes.
- The GY-521 has its own pull-up resistors. Together with the board's
  pull-ups this is fine for short wires.
- Keep wires short (under 10 cm) inside the case.

## On-board pins used by the firmware

See [`include/board_pins.h`](../include/board_pins.h).

| Function | GPIO |
| --- | --- |
| e-paper BUSY, RST, DC, CS, SCK, MOSI | 8, 9, 10, 11, 12, 13 |
| e-paper power enable (LOW = on) | 6 |
| Audio power enable (LOW = on) | 42 |
| Battery latch (HIGH = stay on) | 17 |
| Battery voltage (ADC, 1:2 divider) | 4 |
| BOOT button / PWR button | 0 / 18 |
| RTC interrupt | 5 |
| microSD CLK, CMD, D0 | 39, 41, 40 |
