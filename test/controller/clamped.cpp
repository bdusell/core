#include "controller/clamped.h"
#include "unit_test.h"
UNIT_TEST(clamped) {
	controller::clamped<int> a(2, 0, 5);
	UNIT_TEST_TRUE(a == 2, "casts to initialized value");
	a += 10;
	UNIT_TEST_TRUE(a == 5, "stays clamped after addition");
	a -= 10;
	UNIT_TEST_TRUE(a == 0, "stays clamped after subtraction");
	a = 10;
	UNIT_TEST_TRUE(a == 5, "stays clamped after assignment");
	a = -10;
	UNIT_TEST_TRUE(a == 0, "stays clamped after assignment");
	a = 3;
	UNIT_TEST_TRUE(a == 3, "assigns within bounds");
	a += 1;
	UNIT_TEST_TRUE(a == 4, "increments within bounds");
	a -= 2;
	UNIT_TEST_TRUE(a == 2, "decrements within bounds");
	controller::clamped<int> b(50, 0, 10);
	UNIT_TEST_TRUE(b == 10, "initializes within bounds");
}
