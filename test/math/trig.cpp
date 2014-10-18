#include "math/trig.h"
#include "unit_test.h"
#include "math/util.h"

UNIT_TEST(math_trig) {
	UNIT_TEST_TRUE(math::real_equal(math::sin(0.0), 0.0), "sin(0) = 0");
}
