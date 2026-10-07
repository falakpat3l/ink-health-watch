# Guide: how this code works

A plain-English tour, so you can find your way around and change things safely.

## What it does today

The watch boots, keeps itself powered from the battery, prints its version and pin map over USB, and prints the battery voltage once a minute. The step-counting maths is being built in `lib/steps/` and tested on your computer before it goes on the watch. The display and logging come next (see `ROADMAP.md`).

## Run it

You need PlatformIO (the VS Code extension, or `pip install platformio`).

1. `pio test -e native` runs the step maths tests on your computer. No watch needed.
2. `pio run -e esp32s3` builds the firmware.
3. `pio run -e esp32s3 -t upload -t monitor` puts it on the watch and shows its messages.

## The big picture

```
src/main.cpp          the watch program: setup() runs once, loop() runs forever
   uses
include/board_pins.h  which chip pin is wired to what
lib/steps/            step maths, plain C++ with no hardware code,
                      so the same file runs on the watch and on your laptop
```

Keeping the maths away from the hardware is the one important idea here: you can test it in seconds on your laptop, and only flash the watch when it already works.

## Where things live

| File | What it does | Open it when you want to... |
|---|---|---|
| `src/main.cpp` | The watch program | change what the watch does |
| `include/board_pins.h` | Pin numbers and the battery divider ratio | wiring changes |
| `include/version.h` | The version string | making a release |
| `lib/steps/src/steps.h` and `steps.cpp` | Step maths: `magnitude()` and the `LowPass` smoothing filter | improve step counting |
| `test/test_steps/test_main.cpp` | Tests for the step maths | after changing the maths |
| `platformio.ini` | Build settings: `esp32s3` for the watch, `native` for laptop tests | rarely |
| `hardware/` | Parts list, wiring, case notes | buying or wiring |
| `docs/` | Why things are done this way, and safety notes | before big changes |

## Common changes

**Add a new piece of step maths.** Declare it in `steps.h`, write it in `steps.cpp`, add a test in `test_main.cpp`, then run `pio test -e native`.

**Pin moved on a new board.** Change it in `include/board_pins.h` only.

## Check you didn't break anything

```
pio test -e native
pio run -e esp32s3
```

GitHub Actions runs both on every push.

## Words you will see

- **Native**: building for your laptop instead of the watch.
- **Magnitude**: the overall size of a movement, whichever way the wrist is turned.
- **Low-pass filter**: smoothing that ignores quick jitter. `alpha` near 0 is smoother but slower to react.
- **Unity**: the small testing library PlatformIO uses.
