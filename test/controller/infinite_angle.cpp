#include "controller/infinite_angle.h"
#include "unit_test.h"
#include "math/util.h"
UNIT_TEST(infinite_angle) {

	controller::infinite_angle<int> a(5);
	UNIT_TEST_TRUE(a == 0, "initializes to 0 by default");
	controller::infinite_angle<int> b(5, 2);
	UNIT_TEST_TRUE(b == 2, "initializes to given value");
	controller::infinite_angle<int> c(5, 7);
	UNIT_TEST_TRUE(c == 7, "does not wrap when initialized");
	b += 2;
	UNIT_TEST_TRUE(b == 4, "increments within bounds");
	b += 2;
	UNIT_TEST_TRUE(b == 1, "wraps when increments above bounds");
	b -= 4;
	UNIT_TEST_TRUE(b == 2, "wraps when decrements below bounds");
	b -= 1;
	UNIT_TEST_TRUE(b == 1, "decrements within bounds");
	b = 10;
	UNIT_TEST_TRUE(b == 10, "does not wrap when assigned");
	b = 3;
	UNIT_TEST_TRUE(b == 3, "assigns within bounds");

	controller::infinite_radian_angle<float> d;
	UNIT_TEST_TRUE(math::real_equal<float>(d, 0), "initializes to 0 by default");

	controller::infinite_radian_angle<float> e(math::pi);
	UNIT_TEST_TRUE(math::real_equal<float>(e, M_PI), "initializes to given value");

	e += (float) (math::pi * 20.5);
	UNIT_TEST_TRUE(math::real_equal<float>(e, 1.5 * M_PI), "wraps when increments above bounds");

	e -= (float) (math::pi * 20.2);
	UNIT_TEST_TRUE(math::real_equal<float>(e, 1.3 * M_PI), "wraps when decrements below bounds");

	e -= (float) (math::pi * 0.3);
	UNIT_TEST_TRUE(math::real_equal<float>(e, 1.0 * M_PI), "decrements within bounds");

	e += (float) (math::pi * 0.1);
	UNIT_TEST_TRUE(math::real_equal<float>(e, 1.1 * M_PI), "increments within bounds");

	e = (float) (50.0 * math::pi);
	UNIT_TEST_TRUE(math::real_equal<float>(e, 50.0 * M_PI), "does not wrap when assigned");

	e = (float) (1.23 * math::pi);
	UNIT_TEST_TRUE(math::real_equal<float>(e, 1.23 * M_PI), "assigns within bounds");

	controller::infinite_degree_angle<float> f;
	UNIT_TEST_TRUE(math::real_equal<float>(f, 0), "initializes to 0 by default");

	controller::infinite_degree_angle<float> g(60.0);
	UNIT_TEST_TRUE(math::real_equal<float>(g, 60.0), "initializes to given value");

	g += 30.0f;
	UNIT_TEST_TRUE(math::real_equal<float>(g, 90.0), "increments within bounds");

	g += 300.0f;
	UNIT_TEST_TRUE(math::real_equal<float>(g, 30.0), "wraps when increments above bounds");

	g -= 15.0f;
	UNIT_TEST_TRUE(math::real_equal<float>(g, 15.0), "decrements within bounds");

	g -= 180.0f;
	UNIT_TEST_TRUE(math::real_equal<float>(g, 195.0), "wraps when decrements below bounds");

	g = 125.0f;
	UNIT_TEST_TRUE(math::real_equal<float>(g, 125.0), "assigns within bounds");

	g = 9000.0f;
	UNIT_TEST_TRUE(math::real_equal<float>(g, 9000.0), "does not wrap when assigned");

}
