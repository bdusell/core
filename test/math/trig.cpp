#include "math/trig.h"
#include "unit_test.h"
#include "math/util.h"

UNIT_TEST(math_trig) {
	UNIT_TEST_TRUE(math::real_equal(math::sin(0.0), 0.0), "sin(0) = 0");
	UNIT_TEST_TRUE(math::real_equal(math::cos(0.0), 1.0), "cos(0) = 1");
	UNIT_TEST_TRUE(math::real_equal(math::tan(math::pi / 4.0), 1.0), "tan(pi/4) = 1");
	UNIT_TEST_TRUE(math::real_equal(math::asin(0.0), 0.0), "asin(0) = 0");
	UNIT_TEST_TRUE(math::real_equal(math::acos(1.0), 0.0), "acos(0) = 0");
	UNIT_TEST_TRUE(math::real_equal(math::atan(1.0), math::pi / 4.0), "atan(1) = pi/4");
	UNIT_TEST_TRUE(math::real_equal(
		math::atan(1.0, 1.0),
		math::pi / 4.0
	), "atan(1 / 1) = pi/4");
	UNIT_TEST_TRUE(math::real_equal(
		math::atan(-1.0, -1.0),
		-math::pi * 3.0 / 4.0
	), "atan(-(pi/4) / -(pi/4)) = ");
}
