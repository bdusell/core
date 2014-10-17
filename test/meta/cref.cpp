#include "meta/cref.h"
#include "unit_test.h"
#include "meta/same_type.h"

class MySmallClass {
	char value;
};

class MyLargeClass {
	int *a, *b;
};

UNIT_TEST(cref) {
	UNIT_TEST_TRUE((meta::same_type<meta::cref<int>::type, int>::value), "small primitive maps to itself");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<long double>::type, const long double &>::value), "large primitive maps to const reference");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<const char>::type, char>::value), "small const primitive maps to non-const");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<const long double>::type, const long double &>::value), "large const primitive maps to const reference");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<MySmallClass>::type, const MySmallClass &>::value), "small class type maps to const reference");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<MyLargeClass>::type, const MyLargeClass &>::value), "large class type maps to const reference");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<int *>::type, int *>::value), "pointer type maps to itself");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<const int *>::type, const int *>::value), "pointer to const maps to itself");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<char * const>::type, char *>::value), "const pointer maps to non-const");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<int &>::type, const int &>::value), "reference type maps to const reference");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<const int &>::type, const int &>::value), "const reference maps to itself");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<int[3]>::type, const int(&)[3]>::value), "array type maps to const array reference");
	UNIT_TEST_TRUE((meta::same_type<meta::cref<const int(&)[3]>::type, const int(&)[3]>::value), "const array type maps to itself");
}
