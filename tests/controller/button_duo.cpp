#include "controller/button_duo.h"
#include "unit_test.h"
UNIT_TEST(button_duo) {
	controller::button_duo a;
	bool &up = a.pos();
	bool &down = a.neg();
	UNIT_TEST_TRUE(a == 0, "zero when constructed");
	up = true;
	UNIT_TEST_TRUE(a == 1, "one when switched up");
	down = true;
	UNIT_TEST_TRUE(a == 0, "zero when switched up and down");
	up = false;
	UNIT_TEST_TRUE(a == -1, "negative one when switched down");
	down = false;
	UNIT_TEST_TRUE(a == 0, "zero when neither switched");
}
