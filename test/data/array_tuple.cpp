#include "datastruct/array_tuple.h"
#include "unit_test.h"
#include <cstring>
#include "math/util.h"
UNIT_TEST(array_tuple) {
	datastruct::array_tuple<float, 2> a;
	UNIT_TEST_TRUE(true, "default constructible");
	datastruct::array_tuple<float, 2> b(1, 2);
	UNIT_TEST_TRUE(true, "two-element constructor");
	UNIT_TEST_TRUE(math::real_equal<float>(b.get<0>(), 1), "getting value through template constant");
	UNIT_TEST_TRUE(math::real_equal<float>(b.get(0), 1), "getting value through get() method");
	UNIT_TEST_TRUE(math::real_equal<float>(b[0], 1), "getting value through operator[]");
	const datastruct::array_tuple<int, 3> c(3, 4, 5);
	UNIT_TEST_TRUE(true, "three-element constructor");
	UNIT_TEST_TRUE(c.get<0>() == 3, "getting value through template constant (const)");
	UNIT_TEST_TRUE(c.get(1) == 4, "getting value through get() method (const)");
	UNIT_TEST_TRUE(c[2] == 5, "getting value through operator[] (const)");
	const datastruct::array_tuple<int, 4> d(6, 7, 8, 9);
	UNIT_TEST_TRUE(true, "four-element constructor");
	UNIT_TEST_TRUE((d == datastruct::array_tuple<int, 4>(6, 7, 8, 9)), "equality test");
	UNIT_TEST_TRUE((d != datastruct::array_tuple<int, 4>(6, 7, 9, 8)), "inequality test");
	datastruct::array_tuple<int, 4> e(d);
	UNIT_TEST_TRUE(d == e, "copy constructor");
	datastruct::array_tuple<char, 4> f;
	f.get<0>() = 'a';
	UNIT_TEST_TRUE(f[0] == 'a', "set through template constant");
	f.get(1) = 'b';
	UNIT_TEST_TRUE(f[1] == 'b', "set through get() method");
	f[2] = 'c';
	UNIT_TEST_TRUE(f[2] == 'c', "set through operator[]");
	f.set('1', '2', '3', '\0');
	UNIT_TEST_TRUE(f == "123", "set through set() method");
	UNIT_TEST_TRUE(strlen(f.array()) == 3, "array access");
	f = d;
	UNIT_TEST_TRUE(f == d, "assignment");
}
