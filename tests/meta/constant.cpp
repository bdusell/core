#include "meta/constant.h"
#include "unit_test.h"
UNIT_TEST(constant) {
	UNIT_TEST_TRUE((meta::constant<int, 5>::value == 5), "integer constant 5");
	UNIT_TEST_TRUE((meta::constant<bool, false>::value == false), "boolean constant false");
	UNIT_TEST_TRUE((meta::constant<char, 'a'>::value == 'a'), "character constant \'a\'");
}
