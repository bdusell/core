#include "meta/choose.h"
#include "unit_test.h"
#include "meta/same_type.h"
UNIT_TEST(choose) {
	UNIT_TEST_TRUE((meta::same_type<meta::choose<0, int, char>::type, int>::value), "choice 1 of 2");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<1, int, char>::type, char>::value), "choice 2 of 2");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<0, int, char, float>::type, int>::value), "choice 1 of 3");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<1, int, char, float>::type, char>::value), "choice 2 of 3");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<2, int, char, float>::type, float>::value), "choice 3 of 3");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<0, int, char, float, double>::type, int>::value), "choice 1 of 4");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<1, int, char, float, double>::type, char>::value), "choice 2 of 4");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<2, int, char, float, double>::type, float>::value), "choice 3 of 4");
	UNIT_TEST_TRUE((meta::same_type<meta::choose<3, int, char, float, double>::type, double>::value), "choice 4 of 4");
}
