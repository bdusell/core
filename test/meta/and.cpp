#include "meta/and.h"
#include "unit_test.h"
UNIT_TEST(meta_and) {
#define _TEST_COMBO( a , b , result ) \
	UNIT_TEST_TRUE((meta::and_<a, b>::value == result), #a " and " #b " = " #result);
	_TEST_COMBO(false, false, false);
	_TEST_COMBO(false, true, false);
	_TEST_COMBO(true, false, false);
	_TEST_COMBO(true, true, true);
}
