#include "meta/true.h"
#include "unit_test.h"
class true_test : public unit_test {
protected:
	void run_tests() {
		UNIT_TEST_TRUE(meta::true_::value, "value is true");
	}
};
UNIT_TEST_PROGRAM(true_test)
