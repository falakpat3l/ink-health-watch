#include "steps.h"

#include <cmath>

namespace ink::steps {

namespace {
constexpr float kPi = 3.14159265358979f;
}  // namespace

float magnitude(const Accel& a) {
  return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

LowPass::LowPass(float alpha) {
  if (!(alpha > 0.0f)) {  // also catches NaN
    alpha = 1e-6f;
  } else if (alpha > 1.0f) {
    alpha = 1.0f;
  }
  alpha_ = alpha;
}

float LowPass::update(float x) {
  if (!primed_) {
    value_ = x;
    primed_ = true;
  } else {
    value_ += alpha_ * (x - value_);
  }
  return value_;
}

void LowPass::reset() {
  value_ = 0.0f;
  primed_ = false;
}

float LowPass::alphaFor(float cutoff_hz, float sample_rate_hz) {
  if (!(cutoff_hz > 0.0f) || !(sample_rate_hz > 0.0f)) {
    return 1.0f;  // no filtering
  }
  const float dt = 1.0f / sample_rate_hz;
  const float rc = 1.0f / (2.0f * kPi * cutoff_hz);
  return dt / (rc + dt);
}

}  // namespace ink::steps
