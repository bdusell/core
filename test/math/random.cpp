#include "math/random.h"
#include "unit_test.h"

UNIT_TEST(math_random) {
	math::srand();
	UNIT_TEST_COMPILES("srand()");
	double r1 = math::rand_real(0.0, 1.0);
	UNIT_TEST_TRUE(0.0 <= r1 && r1 <= 1.0, "rand_real(0.0, 1.0)");
	int r2 = math::rand_int(10, 20);
	UNIT_TEST_TRUE(10 <= r2 && r2 <= 20, "rand_int(10, 20)");
	int r3 = math::rand_int_exclusive(10);
	UNIT_TEST_TRUE(0 <= r3 && r3 < 10, "rand_int_exlusive(10)");
	int r4 = math::rand_int_exclusive(15, 30);
	UNIT_TEST_TRUE(15 <= r4 && r4 <= 30, "rand_int_exclusive(15, 30)");
	float r5 = math::rand(0.0f, 1.0f);
	UNIT_TEST_TRUE(0.0f <= r5 && r5 <= 1.0f, "rand(0.0f, 1.0f)");
	double r6 = math::rand(0.0, 1.0);
	UNIT_TEST_TRUE(0.0 <= r6 && r6 <= 1.0, "rand(0.0, 1.0)");
	int r7 = math::rand(0, 10);
	UNIT_TEST_TRUE(0 <= r7 && r7 <= 10, "rand(0, 10)");
	long r8 = math::rand(0l, 10l);
	UNIT_TEST_TRUE(0l <= r8 && r8 <= 10l, "rand(0l, 10l)");
}
