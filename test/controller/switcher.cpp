#include "controller/switcher.h"
#include "unit_test.h"
#include "math/util.h"
UNIT_TEST(switcher) {
	controller::switcher<bool, int> a(false, 1, 2);
	UNIT_TEST_TRUE(a == 1, "getting the false value");
	a.cond() = true;
	UNIT_TEST_TRUE(a == 2, "setting the condition to true and getting the true value");
	a.cond() = false;
	UNIT_TEST_TRUE(a == 1, "false value again");

	bool s = true;
	controller::switcher<bool &, float> b(s, 1.23, 4.56);
	UNIT_TEST_TRUE(math::real_equal<float>(b, 4.56), "getting true value when referenced condition is true");
	s = false;
	UNIT_TEST_TRUE(math::real_equal<float>(b, 1.23), "getting false value when referenced condition is false");
	b.cond() = true;
	UNIT_TEST_TRUE(s, "setting condition modifies referenced value");
}
