#include "meta/bool.h"
#include "unit_test.h"
class bool_test : public unit_test {
protected:
	void run_tests() {
		UNIT_TEST_TRUE(!meta::bool_<false>::value, "false type");
		UNIT_TEST_TRUE(meta::bool_<true>::value, "true type");
	}
};
UNIT_TEST_PROGRAM(bool_test)
