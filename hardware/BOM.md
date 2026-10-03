# Bill of materials

Prices are from Indian shops, checked on 3 Oct 2026. They change often, so
check again before buying.

| # | Part | Qty | Notes | Where | Price (Rs) |
| --- | --- | --- | --- | --- | --- |
| 1 | Waveshare ESP32-S3-ePaper-1.54 AIoT board, no touch, no battery | 1 | 200x200 B/W e-paper, ESP32-S3, 8 MB PSRAM, PCF85063 RTC, SHTC3, ES8311 codec + mic, microSD, Li-ion charger, USB-C, 2x6 header | [Hubtronics](https://hubtronics.in/esp32-s3-e-paper-1.54-without-battery) | 1,885 incl. GST |
| 2 | MPU6050 module (GY-521) | 1 | 3-axis accelerometer + 3-axis gyroscope, I2C address 0x68 | [Probots](https://probots.co.in/mpu6050-6dof-imu-sensor-module-gyroscope-accelerometer-gy521.html) | 199 incl. GST |
| 3 | 3.7 V single-cell LiPo, 300 to 400 mAh, **with protection circuit** | 1 | Needs an MX1.25 2-pin plug with + and - matching the board, see [safety](../docs/safety.md) | [Robu](https://robu.in/product/400mah-pcm-protected-micro-li-po-battery/) | 219 (check GST and plug) |
| 4 | MX1.25 2-pin pigtail | 1 | Only if the battery plug does not match | local / Robu | |
| 5 | microSD card, 8 to 32 GB | 1 | FAT32 | any shop | |
| 6 | Jumper wires (female-female) | 4 to 5 | MPU6050 to header J1 | any shop | |
| 7 | 3D-printed case and strap | 1 | Designed in Fusion 360, files in `case/` | own print | |

**Estimated core cost:** about Rs 2,300 for items 1 to 3.

## Board variants

- With battery included: Rs 2,399 at Hubtronics (out of stock on 3 Oct 2026).
  This avoids the plug polarity check.
- Touch + battery version: Rs 4,299 (out of stock). Touch is not needed.
- Waveshare sold a V1 board until 1 Nov 2025; V2 boards use OPI PSRAM.
  `platformio.ini` targets V2.

## Alternatives considered

See [docs/design-decisions.md](../docs/design-decisions.md).
