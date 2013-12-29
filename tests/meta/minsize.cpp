#include "meta/minsize.h"
#include "unit_test.h"
#include "meta/same_type.h"
class MySmallClass { char a; };
class MyBigClass { int *a, *b, *c; };
UNIT_TEST(minsize) {
#define _TEST( T, U, MSG ) \
	UNIT_TEST_TRUE((meta::same_type<meta::minsize<T>::type, U>::value), MSG);
	_TEST(char, char, "small primitive maps to itself")
	_TEST(long double, const long double &, "large primitive maps to reference to const")
	_TEST(MySmallClass, MySmallClass, "small class type maps to itself")
	_TEST(MyBigClass, const MyBigClass &, "big class type maps to reference to const")
}
