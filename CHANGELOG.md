# Changelog

All notable changes to this project are listed here.
The format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/)
and versions follow [Semantic Versioning](https://semver.org/).

## [0.1.0-alpha] - 2026-10-03

### Added

- PlatformIO project with two environments: `esp32s3` (firmware) and
  `native` (host unit tests).
- Board pin map for the Waveshare ESP32-S3-ePaper-1.54 (V2), taken from
  Waveshare's schematic and example code.
- Boot firmware: keeps the battery latch on, prints version and pins over
  USB serial, reads battery voltage once a minute.
- `lib/steps`: acceleration magnitude and a low pass filter, the first
  building blocks of the step counter, with 10 host unit tests.
- Docs: bill of materials, wiring plan for the MPU6050, battery safety
  notes, design decisions, roadmap.
- GitHub Actions CI: host tests and firmware build on every push.
- MIT license.

[0.1.0-alpha]: https://github.com/falakpat3l/ink-health-watch/releases/tag/v0.1.0-alpha
