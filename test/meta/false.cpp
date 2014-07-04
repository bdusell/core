#include "meta/false.h"
#include "unit_test.h"
class false_test : public unit_test {
protected:
	void run_tests() {
		UNIT_TEST_TRUE(!meta::false_::value, "value is false");
	}
};
UNIT_TEST_PROGRAM(false_test)
