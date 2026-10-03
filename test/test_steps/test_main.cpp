// Host unit tests for lib/steps. Run with:  pio test -e native

#include <unity.h>

#include <cmath>

#include "steps.h"

using ink::steps::Accel;
using ink::steps::LowPass;
using ink::steps::magnitude;

void setUp() {}
void tearDown() {}

void test_magnitude_at_rest_is_one_g_in_any_orientation() {
  TEST_ASSERT_FLOAT_WITHIN(1e-6f, 1.0f, magnitude({0.0f, 0.0f, 1.0f}));
  TEST_ASSERT_FLOAT_WITHIN(1e-6f, 1.0f, magnitude({0.0f, -1.0f, 0.0f}));
  const float s = 1.0f / std::sqrt(3.0f);
  TEST_ASSERT_FLOAT_WITHIN(1e-5f, 1.0f, magnitude({s, s, s}));
}

void test_magnitude_of_3_4_12_is_13() {
  TEST_ASSERT_FLOAT_WITHIN(1e-5f, 13.0f, magnitude({3.0f, -4.0f, 12.0f}));
}

void test_magnitude_of_zero_is_zero() {
  TEST_ASSERT_EQUAL_FLOAT(0.0f, magnitude({0.0f, 0.0f, 0.0f}));
}

void test_lowpass_first_sample_seeds_output() {
  LowPass lp(0.1f);
  TEST_ASSERT_FALSE(lp.primed());
  TEST_ASSERT_EQUAL_FLOAT(1.0f, lp.update(1.0f));
  TEST_ASSERT_TRUE(lp.primed());
}

void test_lowpass_moves_part_way_toward_new_input() {
  LowPass lp(0.25f);
  lp.update(0.0f);
  TEST_ASSERT_FLOAT_WITHIN(1e-6f, 1.0f, lp.update(4.0f));   // 0 + 0.25 * 4
  TEST_ASSERT_FLOAT_WITHIN(1e-6f, 1.75f, lp.update(4.0f));  // 1 + 0.25 * 3
}

void test_lowpass_converges_to_constant_input() {
  LowPass lp(0.2f);
  lp.update(0.0f);
  for (int i = 0; i < 100; ++i) lp.update(1.0f);
  TEST_ASSERT_FLOAT_WITHIN(1e-4f, 1.0f, lp.value());
}

void test_lowpass_smooths_alternating_noise() {
  // +-0.5 g noise around 1 g should shrink a lot after filtering.
  LowPass lp(0.1f);
  float max_dev = 0.0f;
  for (int i = 0; i < 200; ++i) {
    const float out = lp.update(i % 2 == 0 ? 1.5f : 0.5f);
    if (i > 50) max_dev = std::fmax(max_dev, std::fabs(out - 1.0f));
  }
  TEST_ASSERT_TRUE(max_dev < 0.06f);
}

void test_lowpass_alpha_is_clamped() {
  TEST_ASSERT_EQUAL_FLOAT(1.0f, LowPass(5.0f).alpha());
  TEST_ASSERT_TRUE(LowPass(0.0f).alpha() > 0.0f);
  TEST_ASSERT_TRUE(LowPass(-1.0f).alpha() > 0.0f);
  TEST_ASSERT_TRUE(LowPass(NAN).alpha() > 0.0f);
}

void test_lowpass_reset_forgets_history() {
  LowPass lp(0.5f);
  lp.update(10.0f);
  lp.update(10.0f);
  lp.reset();
  TEST_ASSERT_FALSE(lp.primed());
  TEST_ASSERT_EQUAL_FLOAT(2.0f, lp.update(2.0f));
}

void test_alpha_for_cutoff_and_sample_rate() {
  // 3 Hz cutoff at 50 Hz sampling (typical for walking): about 0.274
  TEST_ASSERT_FLOAT_WITHIN(1e-3f, 0.2738f, LowPass::alphaFor(3.0f, 50.0f));
  // Bad inputs mean "no filtering"
  TEST_ASSERT_EQUAL_FLOAT(1.0f, LowPass::alphaFor(0.0f, 50.0f));
  TEST_ASSERT_EQUAL_FLOAT(1.0f, LowPass::alphaFor(3.0f, -1.0f));
}

int main(int, char**) {
  UNITY_BEGIN();
  RUN_TEST(test_magnitude_at_rest_is_one_g_in_any_orientation);
  RUN_TEST(test_magnitude_of_3_4_12_is_13);
  RUN_TEST(test_magnitude_of_zero_is_zero);
  RUN_TEST(test_lowpass_first_sample_seeds_output);
  RUN_TEST(test_lowpass_moves_part_way_toward_new_input);
  RUN_TEST(test_lowpass_converges_to_constant_input);
  RUN_TEST(test_lowpass_smooths_alternating_noise);
  RUN_TEST(test_lowpass_alpha_is_clamped);
  RUN_TEST(test_lowpass_reset_forgets_history);
  RUN_TEST(test_alpha_for_cutoff_and_sample_rate);
  return UNITY_END();
}
