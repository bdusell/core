#include "math/util.h"
#include "unit_test.h"
#include <iostream>
UNIT_TEST(util) {

#define _VALUE 5.5
#define _VALUE_STR "5.5"

#define _ARGS_1(TYPE) \
	static_cast<TYPE>(_VALUE)

#define _ARGS_2(TYPE) \
	_ARGS_1(TYPE), _ARGS_1(TYPE)

#define _ARGS_3(TYPE) \
	_ARGS_2(TYPE), _ARGS_1(TYPE)

#define _ARGS_STR_1 _VALUE_STR

#define _ARGS_STR_2 _ARGS_STR_1 ", " _ARGS_STR_1

#define _ARGS_STR_3 _ARGS_STR_2 ", " _ARGS_STR_1

#define _TEST_TYPE(FUNC, TYPE, N) \
	std::cout << (#FUNC "<" #TYPE ">(" _ARGS_STR_ ## N ") = ") << math::FUNC(_ARGS_ ## N(TYPE)) << std::endl;

#define _TEST_FUNC(FUNC, N) \
	_TEST_TYPE(FUNC, int, N) \
	_TEST_TYPE(FUNC, long, N) \
	_TEST_TYPE(FUNC, float, N) \
	_TEST_TYPE(FUNC, double, N) \
	_TEST_TYPE(FUNC, long double, N)

	_TEST_FUNC(sqr, 1)
	_TEST_FUNC(sqrt, 1)
	_TEST_FUNC(exp, 1)
	_TEST_FUNC(pow, 2)
	_TEST_FUNC(log, 1)
	_TEST_FUNC(log10, 1)
	_TEST_FUNC(log, 2)
	_TEST_FUNC(floor, 1)
	_TEST_FUNC(ceil, 1)
	_TEST_FUNC(floor_div, 2)
	_TEST_FUNC(ceil_div, 2)
	_TEST_FUNC(mod, 2)
	_TEST_FUNC(strict_mod, 2)
	_TEST_FUNC(max, 2)
	_TEST_FUNC(min, 2)
	_TEST_FUNC(clamp, 3)
	_TEST_FUNC(abs, 1)

	UNIT_TEST_TRUE(math::real_equal(1.0 / 3.0 + 2.0 / 3.0, 1.0, 0.0001, 0.0001),
		"equality test for floating point values with absolute and relative tolerances");
	UNIT_TEST_TRUE(math::real_equal(1.0 / 3.0 + 2.0 / 3.0, 1.0, 0.0001),
		"equality test for floating point values with absolute and relative tolerances equal");
	UNIT_TEST_TRUE(math::real_equal(1.0 / 3.0 + 2.0 / 3.0, 1.0),
		"equality test for floating point values, default");

}
