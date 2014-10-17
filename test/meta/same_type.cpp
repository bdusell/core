#include "meta/same_type.h"
#include "unit_test.h"

UNIT_TEST(meta_same_type) {
	UNIT_TEST_TRUE((meta::same_type<int, int>::value), "true for same types");
	UNIT_TEST_TRUE((!meta::same_type<float, double>::value), "false for different types");
	typedef char mychar;
	UNIT_TEST_TRUE((meta::same_type<char, mychar>::value), "true for typedefs");
	UNIT_TEST_TRUE((!meta::same_type<char, const char>::value), "false for different const qualifiers");
	UNIT_TEST_TRUE((!meta::same_type<char, char &>::value), "false for value vs. reference");
	UNIT_TEST_TRUE((meta::same_type<int[3], int[3]>::value), "true for array types with same length");
	UNIT_TEST_TRUE((!meta::same_type<int[3], int[4]>::value), "false for array types with different lengths");
	UNIT_TEST_TRUE((meta::same_type<const char, const char>::value), "true for same const types");
	UNIT_TEST_TRUE((!meta::same_type<const char, const float>::value), "false for different const types");
	typedef const char myconstchar;
	UNIT_TEST_TRUE((meta::same_type<const myconstchar, const char>::value), "true for double-const typedef vs. single-const");
}
