#include "functional/operators.h"
#include "unit_test.h"

UNIT_TEST(functional_operators) {
	UNIT_TEST_TRUE(functional::add()(1, 2) == 3, "Addition operator.");
	UNIT_TEST_TRUE(functional::subtract()(2, 1) == 1, "Subtraction operator.");
	UNIT_TEST_TRUE(functional::multiply()(2, 3) == 6, "Multiplication operator.");
	UNIT_TEST_TRUE(functional::divide()(4, 2) == 2, "Division operator.");
	int a = 0;
	UNIT_TEST_TRUE(functional::assign()(a, 1) == 1, "Assignment operator.");
	UNIT_TEST_TRUE(functional::assign()(functional::assign()(a, 2), 3), "Compount assignment.");
	UNIT_TEST_TRUE(functional::add_assign()(a, 1) == 4, "+= operator.");
	UNIT_TEST_TRUE(functional::subtract_assign()(a, 1) == 3, "-= operator.");
	UNIT_TEST_TRUE(functional::multiply_assign()(a, 2) == 6, "*= operator.");
	UNIT_TEST_TRUE(functional::divide_assign()(a, 3) == 2, "/= operator.");
	UNIT_TEST_TRUE(functional::equals()(2, 2), "Equality operator.");
	UNIT_TEST_TRUE(functional::not_equals()(2, 3), "Inequality operator.");
	UNIT_TEST_TRUE(functional::less()(1, 2), "Less than operator.");
	UNIT_TEST_TRUE(functional::less_equals()(2, 2), "Less than or equals operator.");
	UNIT_TEST_TRUE(functional::greater()(2, 1), "Greater than operator.");
	UNIT_TEST_TRUE(functional::greater_equals()(2, 2), "Greater than or equals operator.");
}
