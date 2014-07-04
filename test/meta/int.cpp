#include "meta/int.h"
#include "unit_test.h"
#include "meta/same_type.h"
UNIT_TEST(int_) {
	UNIT_TEST_TRUE(meta::int_<10>::value == 10, "1 == 1");
	UNIT_TEST_TRUE((meta::same_type<meta::int_<3>, meta::int_<3> >::value), "equal integers have same type");
	UNIT_TEST_TRUE((!meta::same_type<meta::int_<3>, meta::int_<4> >::value), "unequal integers have different types");
}
