#include "meta/and.h"
#include "unit_test.h"
class and_test : public unit_test {
protected:
	void run_tests() {
#define _TEST_COMBO( a , b , result ) \
		UNIT_TEST_TRUE((meta::and_<a, b>::value == result), #a " and " #b " = " #result);
		_TEST_COMBO(false, false, false);
		_TEST_COMBO(false, true, false);
		_TEST_COMBO(true, false, false);
		_TEST_COMBO(true, true, true);
	}
};
UNIT_TEST_PROGRAM(and_test)
