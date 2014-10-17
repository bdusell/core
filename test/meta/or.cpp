#include "meta/or.h"
#include "unit_test.h"

UNIT_TEST(meta_or) {
#define _TEST_COMBO( a , b , result ) \
	UNIT_TEST_TRUE((meta::or_<a, b>::value == result), #a " and " #b " = " #result);
	_TEST_COMBO(false, false, false);
	_TEST_COMBO(false, true, true);
	_TEST_COMBO(true, false, true);
	_TEST_COMBO(true, true, true);
}
