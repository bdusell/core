#include "meta/if.h"
#include "unit_test.h"
#include "meta/same_type.h"
class if_test : public unit_test {
protected:
	void run_tests() {
		UNIT_TEST_TRUE((meta::same_type<meta::if_<1 == 1, int, float>::type, int>::value), "positive condition works");
		UNIT_TEST_TRUE((meta::same_type<meta::if_<1 == 2, int, float>::type, float>::value), "negative condition works");
	}
};
UNIT_TEST_PROGRAM(if_test)
