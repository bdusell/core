#include "meta/is_pointer.h"
#include "unit_test.h"

struct MyClass {};

UNIT_TEST(meta_is_pointer) {
	UNIT_TEST_TRUE(meta::is_pointer<int *>::value, "true for pointer type");
	UNIT_TEST_TRUE(!meta::is_pointer<int>::value, "false for primitive type");
	UNIT_TEST_TRUE(meta::is_pointer<MyClass *>::value, "true for pointer to class type");
	UNIT_TEST_TRUE(!meta::is_pointer<MyClass>::value, "false for class type");
}
