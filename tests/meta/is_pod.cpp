#include "meta/is_pod.h"
#include "unit_test.h"
class MyClass {};
class is_pod_test : public unit_test {
protected:
	void run_tests() {
#define _TEST_TRUE( T ) \
		UNIT_TEST_TRUE(meta::is_pod<T>::value, #T " is a plain old data type");
#define _TEST_FALSE( T ) \
		UNIT_TEST_TRUE(!meta::is_pod<T>::value, #T " is not a plain old data type");
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
		_TEST_TRUE(char *)
		_TEST_TRUE(int **)
		_TEST_TRUE(MyClass *)
		_TEST_FALSE(MyClass)
		_TEST_FALSE(char &)
		_TEST_FALSE(int[3])
	}
};
UNIT_TEST_PROGRAM(is_pod_test)
