#include "meta/is_primitive.h"
#include "unit_test.h"

class MyClass {};

UNIT_TEST(meta_is_primitive) {
#define _TEST_TRUE( T ) \
	UNIT_TEST_TRUE(meta::is_primitive<T>::value, #T " is a primitive type");
#define _TEST_FALSE( T ) \
	UNIT_TEST_TRUE(!meta::is_primitive<T>::value, #T " is not a primitive type");
	_TEST_TRUE(char)
	_TEST_TRUE(signed char)
	_TEST_TRUE(short int)
	_TEST_TRUE(int)
	_TEST_TRUE(long int)
	_TEST_TRUE(unsigned char)
	_TEST_TRUE(unsigned short int)
	_TEST_TRUE(unsigned int)
	_TEST_TRUE(unsigned long int)
	_TEST_TRUE(wchar_t)
	_TEST_TRUE(bool)
	_TEST_TRUE(float)
	_TEST_TRUE(double)
	_TEST_TRUE(long double)
	_TEST_FALSE(char *)
	_TEST_FALSE(int **)
	_TEST_FALSE(MyClass *)
	_TEST_FALSE(MyClass)
	_TEST_FALSE(char &)
	_TEST_FALSE(int[3])
}
