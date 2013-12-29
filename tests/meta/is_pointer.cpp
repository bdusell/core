#include "meta/is_pointer.h"
#include "unit_test.h"
struct MyClass {};
class is_pointer_test : public unit_test {
protected:
	void run_tests() {
		UNIT_TEST_TRUE(meta::is_pointer<int *>::value, "true for pointer type");
		UNIT_TEST_TRUE(!meta::is_pointer<int>::value, "false for primitive type");
		UNIT_TEST_TRUE(meta::is_pointer<MyClass *>::value, "true for pointer to class type");
		UNIT_TEST_TRUE(!meta::is_pointer<MyClass>::value, "false for class type");
	}
};
UNIT_TEST_PROGRAM(is_pointer_test)
