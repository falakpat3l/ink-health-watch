# Design decisions

Short records of why things are the way they are. Newest at the bottom.

## 1. e-paper instead of AMOLED or LCD (2026-10-03)

An always-on watch face that updates once a minute fits e-paper well: it
uses no power to hold an image and is readable in sunlight. The cost is a
slow full refresh (about 1 second), so the firmware will use partial
refresh for the minute tick and deep sleep between updates.

Alternatives looked at: Waveshare 2.06" and 1.8" AMOLED boards (built-in
IMU and mic, but much higher power use), LilyGO T-Watch S3 (complete watch,
but micro-USB and often sold out in India) and Watchy v3 (excellent e-paper
watch, but no microphone or microSD, and import costs).

## 2. External MPU6050 (2026-10-03)

The chosen board has no motion sensor. The MPU6050 is the same IMU used in
StrideMate, so existing experience and calibration methods carry over. It
connects to the board's shared I2C bus through header J1 and its INT pin
can wake the ESP32-S3 from deep sleep.

## 3. PlatformIO + Arduino, with a hardware-free algorithm library (2026-10-03)

PlatformIO gives repeatable builds in CI. The step and cadence algorithm
lives in `lib/steps` as plain C++ with no Arduino code, so it can be unit
tested on a laptop and in GitHub Actions before any hardware exists.

## 4. Voice transcription off the watch (2026-10-03)

The ESP32-S3 can only run a wake word and a short list of fixed commands
on-device. Real speech-to-text needs a server model, so voice notes will
be recorded to microSD and sent over Wi-Fi to an AI service (or a phone)
for transcription. API keys stay in a git-ignored `secrets.h`.

## 5. MIT license (2026-10-03)

Simple and permissive, so others can reuse the code and the step
algorithm freely.

## 6. Wellness framing (2026-10-03)

The project is a research and portfolio prototype, not a medical device.
No diagnostic or treatment claims. See [safety.md](safety.md).
