#include "functional/operators.h"
#include "unit_test.h"

UNIT_TEST(functional_operators) {
	UNIT_TEST_TRUE(functional::operators::add()(1, 2) == 3, "Addition operator.");
	UNIT_TEST_TRUE(functional::operators::subtract()(2, 1) == 1, "Subtraction operator.");
	UNIT_TEST_TRUE(functional::operators::multiply()(2, 3) == 6, "Multiplication operator.");
	UNIT_TEST_TRUE(functional::operators::divide()(4, 2) == 2, "Division operator.");
	int a = 0;
	UNIT_TEST_TRUE(functional::operators::assign()(a, 1) == 1, "Assignment operator.");
	UNIT_TEST_TRUE(functional::operators::assign()(functional::operators::assign()(a, 2), 3), "Compount assignment.");
	UNIT_TEST_TRUE(functional::operators::add_assign()(a, 1) == 4, "+= operator.");
	UNIT_TEST_TRUE(functional::operators::subtract_assign()(a, 1) == 3, "-= operator.");
	UNIT_TEST_TRUE(functional::operators::multiply_assign()(a, 2) == 6, "*= operator.");
	UNIT_TEST_TRUE(functional::operators::divide_assign()(a, 3) == 2, "/= operator.");
	UNIT_TEST_TRUE(functional::operators::equals()(2, 2), "Equality operator.");
	UNIT_TEST_TRUE(functional::operators::not_equals()(2, 3), "Inequality operator.");
	UNIT_TEST_TRUE(functional::operators::less()(1, 2), "Less than operator.");
	UNIT_TEST_TRUE(functional::operators::less_equals()(2, 2), "Less than or equals operator.");
	UNIT_TEST_TRUE(functional::operators::greater()(2, 1), "Greater than operator.");
	UNIT_TEST_TRUE(functional::operators::greater_equals()(2, 2), "Greater than or equals operator.");
}
