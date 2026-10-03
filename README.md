# ink-health-watch

[![CI](https://github.com/falakpat3l/ink-health-watch/actions/workflows/ci.yml/badge.svg)](https://github.com/falakpat3l/ink-health-watch/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
![Status: pre-release](https://img.shields.io/badge/status-pre--release-orange)

An open-source, wrist-worn health watch built on an ESP32-S3 e-paper board.
It shows time, steps and walking cadence on an always-on e-paper face, logs
daily activity to a microSD card, and gives gentle walk and medication
reminders.

> **Not a medical device.** This is a research and portfolio prototype for
> wellness and healthy-ageing experiments. It makes no diagnostic or
> treatment claims and must not be used for medical decisions.

## Why

I co-founded StrideMate, a low-cost walking-assist exoskeleton built on
ESP32 boards and an MPU6050 IMU. This watch reuses that gait know-how in a
small, low-power form factor: something you can wear all day that counts
steps, tracks walking cadence (a simple marker linked to mobility in older
adults), and nudges you to move.

## Features

| Feature | Status |
| --- | --- |
| Signal filters for the step algorithm, host-tested | done (v0.1.0-alpha) |
| Step detection and cadence | planned |
| e-paper watch face (time, steps, cadence) | planned |
| Activity log to microSD (CSV) + Python plotting tool | planned |
| Walk and medication reminders | planned |
| Deep sleep, wake on button or motion, battery level | planned |
| BLE sync to phone or laptop | planned |
| Voice notes transcribed by an AI over Wi-Fi | planned |
| 3D-printed wrist case (Fusion 360) | planned |

See [ROADMAP.md](ROADMAP.md) for the day-by-day plan.

## Hardware

- [Waveshare ESP32-S3-ePaper-1.54](https://docs.waveshare.com/ESP32-S3-ePaper-1.54):
  200x200 black/white e-paper, ESP32-S3 with 8 MB PSRAM, RTC, microphone,
  microSD slot and Li-ion charging
- MPU6050 (GY-521) accelerometer and gyroscope on the board's I2C header
- 3.7 V single-cell LiPo with a protection circuit
- 3D-printed case and strap

Full list with prices in [hardware/BOM.md](hardware/BOM.md), wiring in
[hardware/wiring.md](hardware/wiring.md), and battery rules in
[docs/safety.md](docs/safety.md).

Photos: coming once the board arrives.

## Project layout

```
platformio.ini      firmware (esp32s3) and host test (native) environments
src/                firmware
include/            board pin map and version
lib/steps/          pure C++ step and cadence algorithm, no hardware needed
test/               unit tests that run on a laptop and in CI
tools/              Python companion scripts (planned)
hardware/           bill of materials, wiring, case files
docs/               safety notes and design decisions
```

## Build and test

You need [PlatformIO](https://platformio.org/) (the VS Code extension or the
command line).

```bash
pio test -e native      # run the algorithm unit tests on your computer
pio run -e esp32s3      # build the firmware
pio run -e esp32s3 -t upload -t monitor   # flash the board and open serial
```

GitHub Actions runs both the tests and the firmware build on every push.

## Related work

- [Watchy](https://github.com/sqfmi/Watchy): open-source ESP32 e-paper watch
- [Oxford step counter](https://github.com/Oxford-step-counter/C-Step-Counter):
  open C step counting algorithm (used in Bangle.js)
- [GxEPD2](https://github.com/ZinggJM/GxEPD2): e-paper display library
- [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32): open voice assistant
  firmware with support for this Waveshare board

## License

[MIT](LICENSE) for code. Third-party libraries keep their own licenses.

Built by [Falak Patel](https://falakpatel.com).
