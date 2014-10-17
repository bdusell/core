#include "meta/bool.h"
#include "unit_test.h"

UNIT_TEST(meta_bool) {
	UNIT_TEST_TRUE(!meta::bool_<false>::value, "false type");
	UNIT_TEST_TRUE(meta::bool_<true>::value, "true type");
}
