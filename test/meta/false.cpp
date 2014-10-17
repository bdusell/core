#include "meta/false.h"
#include "unit_test.h"

UNIT_TEST(meta_false) {
	UNIT_TEST_TRUE(!meta::false_::value, "value is false");
}
