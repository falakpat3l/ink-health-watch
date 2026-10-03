# Safety

## Not a medical device

This watch is a research and portfolio prototype for wellness experiments.
It does not diagnose, treat, monitor or prevent any disease, and its step
and cadence numbers are estimates. Do not use it for medical decisions. A
device that made such claims would be regulated as a medical device (by
CDSCO in India, and by similar agencies elsewhere).

Medication reminders are a convenience only. Never rely on them as the only
way to remember a dose.

## Battery rules

1. Use only a **protected** single-cell 3.7 V LiPo (it has a small
   protection circuit, PCM, on the cell).
2. Charge only through the board's own charging circuit over USB-C.
3. **Check plug polarity before connecting.** MX1.25 plugs are not
   standard: compare the red and black wires with the + and - marks on
   the board. Reversed polarity can destroy the board or the cell.
4. Never charge unattended while testing, and never charge a swollen,
   dented or hot cell.
5. Do not pierce, bend or squeeze the cell. Leave room for it in the case,
   and keep it away from sharp screw tips.
6. Stop and unplug if anything gets hot, smells, or swells.
7. Dispose of old cells at an e-waste collection point, not in household
   rubbish.

## Wearing it

- Remove the watch if the skin gets red or itchy. Print the case in a
  skin-friendly material (PETG or TPU) and keep the electronics fully
  covered.
- The watch is not waterproof. Keep it dry.

## Privacy

- Activity logs stay on the microSD card unless you choose to sync them.
- Voice notes (planned) are sent to an AI service for transcription only
  when you ask. API keys live in a git-ignored `secrets.h` and never go into
  the repository.
