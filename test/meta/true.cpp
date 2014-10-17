#include "meta/true.h"
#include "unit_test.h"

UNIT_TEST(meta_true) {
	UNIT_TEST_TRUE(meta::true_::value, "value is true");
}
