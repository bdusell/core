#include "meta/ref.h"
#include "unit_test.h"
#include "meta/same_type.h"
struct MyClass {
	int *a, *b;
};
UNIT_TEST(ref) {
#define _TYPE_TEST( T , U , MSG ) \
	UNIT_TEST_TRUE((meta::same_type<meta::ref< T >::type, U >::value), MSG);
	_TYPE_TEST(char, char &, "small primitive maps to reference");
	_TYPE_TEST(long double, long double &, "large primitive maps to reference");
	_TYPE_TEST(const char, const char &, "small const primitive maps to reference to const");
	_TYPE_TEST(const long double, const long double &, "large const primitive maps to reference to const");
	_TYPE_TEST(MyClass, MyClass &, "class type maps to reference");
	_TYPE_TEST(const MyClass, const MyClass &, "const class type maps to reference to const");
	_TYPE_TEST(char &, char &, "reference maps to reference");
	_TYPE_TEST(const char &, const char &, "reference to const maps to reference to const");
	_TYPE_TEST(int[3], int(&)[3], "array maps to reference to array");
	_TYPE_TEST(const int[3], const int(&)[3], "array of const maps to reference to array of const");
}
