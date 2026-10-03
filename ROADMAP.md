# Roadmap

One milestone per working day, each tagged as a pre-release
(`v0.N.0-alpha`). Phase A needs no hardware, so work continues while the
board is on its way. Phase B starts when the board arrives.

## Phase A: no hardware needed

- [x] **v0.1.0-alpha** Repo skeleton, docs (BOM, wiring, safety), PlatformIO
  project, CI, first signal filters with host unit tests
- [ ] **v0.2.0-alpha** Step detection: peak detection on the filtered
  acceleration magnitude, tested on synthetic walking signals
- [ ] **v0.3.0-alpha** Real walking data: wrist recordings from a phone
  (phyphox app) saved in `data/`, tests compare detected and hand-counted
  steps
- [ ] **v0.4.0-alpha** Cadence (steps per minute) and a daily summary
- [ ] **v0.5.0-alpha** Watch face simulator: draw the 200x200 face on the
  computer and save a PNG preview
- [ ] **v0.6.0-alpha** CSV log format and a Python companion that reads,
  summarises and plots a day
- [ ] **v0.7.0-alpha** Walk and medication reminder scheduler, host-tested
- [ ] **v0.8.0-alpha** First wrist case design in Fusion 360, from
  Waveshare's mechanical drawing

## Phase B: on the board

- [ ] e-paper watch face: time from the RTC, partial refresh every minute
- [ ] MPU6050 over I2C: raw readings and a calibration routine
- [ ] On-device step counting and cadence
- [ ] microSD logging
- [ ] Power: deep sleep, wake on button or motion, battery percentage,
  measured battery life
- [ ] BLE sync to phone or laptop
- [ ] Reminders on the watch, set from the companion script
- [ ] Voice note: record to microSD, transcribe with an AI over Wi-Fi,
  show the text
- [ ] Printed wrist case, real photos in the README
- [ ] **v1.0.0** release, design decisions and changelog complete

## Later ideas

- Link walking cadence with StrideMate exoskeleton gait telemetry
- Smart-glasses style clip-on display (separate project)
