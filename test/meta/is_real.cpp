#include "meta/is_real.h"
#include "unit_test.h"
struct MyClass {};
UNIT_TEST(is_real) {
#define _TEST_TRUE( T ) \
	UNIT_TEST_TRUE(meta::is_real<T>::value, #T " is a real-valued type");
#define _TEST_FALSE( T ) \
	UNIT_TEST_TRUE(!meta::is_real<T>::value, #T " is not a real-valued type");
	_TEST_TRUE(float)
	_TEST_TRUE(double)
	_TEST_TRUE(long double)
	_TEST_TRUE(const float)
	_TEST_TRUE(const double)
	_TEST_TRUE(const long double)
	_TEST_FALSE(int)
	_TEST_FALSE(char)
	_TEST_FALSE(double *)
	_TEST_FALSE(const long double &)
	_TEST_FALSE(float **)
	_TEST_FALSE(MyClass)
}
