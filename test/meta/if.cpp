#include "meta/if.h"
#include "unit_test.h"
#include "meta/same_type.h"

UNIT_TEST(meta_if) {
	UNIT_TEST_TRUE((meta::same_type<meta::if_<1 == 1, int, float>::type, int>::value), "positive condition works");
	UNIT_TEST_TRUE((meta::same_type<meta::if_<1 == 2, int, float>::type, float>::value), "negative condition works");
}
