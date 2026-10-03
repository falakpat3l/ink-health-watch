// Step and cadence signal processing.
//
// Pure C++ with no hardware or Arduino dependencies, so it runs both on
// the ESP32-S3 and on a laptop (the "native" PlatformIO environment used
// for unit tests in CI).
//
// Day 1 provides the first building blocks:
//   * Accel: one accelerometer sample in g
//   * magnitude(): orientation-free size of a sample
//   * LowPass: exponential moving average to smooth noisy samples
// Peak detection and cadence are added in later milestones.
#pragma once

namespace ink::steps {

// One accelerometer sample, in units of g (1 g = 9.81 m/s^2).
struct Accel {
  float x;
  float y;
  float z;
};

// Length of the acceleration vector. A watch at rest reads about 1.0 g
// whichever way the wrist is turned, which is why step detection works on
// the magnitude instead of a single axis.
float magnitude(const Accel& a);

// First order low pass filter (exponential moving average):
//   y[n] = y[n-1] + alpha * (x[n] - y[n-1])
// alpha is clamped to the range (0, 1]. Small alpha = smoother but slower.
// The first sample after construction or reset() seeds the output, so the
// filter does not need time to "warm up" from zero.
class LowPass {
 public:
  explicit LowPass(float alpha);

  float update(float x);
  float value() const { return value_; }
  float alpha() const { return alpha_; }
  bool primed() const { return primed_; }
  void reset();

  // alpha for a given cutoff frequency (Hz) and sample rate (Hz).
  static float alphaFor(float cutoff_hz, float sample_rate_hz);

 private:
  float alpha_;
  float value_ = 0.0f;
  bool primed_ = false;
};

}  // namespace ink::steps
