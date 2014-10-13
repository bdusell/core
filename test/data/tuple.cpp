#include "datastruct/tuple.h"
#include "unit_test.h"
#include <cstring>
#include <string>
#include "math/util.h"
struct MyClass {};
UNIT_TEST(tuple) {

	datastruct::tuple<int, const char *> a(5, "lol");
	UNIT_TEST_TRUE(a.get<0>() == 5, "get first of two elements (int)");
	UNIT_TEST_TRUE(strcmp(a.get<1>(), "lol") == 0, "get second of two elements (string constant)");
	a.get<0>() = 10;
	UNIT_TEST_TRUE(a.get<0>() == 10, "set first of two elements");
	a.get<1>() = ":)";
	UNIT_TEST_TRUE(strcmp(a.get<1>(), ":)") == 0, "set the second of two elements");

	int myint = 5;
	datastruct::tuple<int, int &> b(42, myint);
	UNIT_TEST_TRUE(b.get<1>() == 5, "member is a reference type");
	UNIT_TEST_TRUE(&b.get<1>() == &myint, "address of member and referenced variable are the same");
	myint = 333;
	UNIT_TEST_TRUE(b.get<1>() == 333, "modify referenced variable");
	b.get<1>() = 222;
	UNIT_TEST_TRUE(myint == 222, "modify referenced variable through member");

	datastruct::tuple<int &, int> bcopy(b);
	UNIT_TEST_TRUE(bcopy.get<0>() == 42 && &bcopy.get<0>() == &b.get<0>(), "copied first member");
	UNIT_TEST_TRUE(bcopy.get<1>() == 222 && &bcopy.get<1>() != &b.get<1>(), "copied second member");

	bcopy.set();

	const datastruct::tuple<int &, int &> bconstcopy(bcopy);
	UNIT_TEST_TRUE(&bconstcopy.get<0>() == &b.get<0>(), "first member of const tuple");
	UNIT_TEST_TRUE(&bconstcopy.get<1>() == &bcopy.get<1>(), "second member of const tuple");

	datastruct::tuple<char, int, long> c('a', 5, 7l);
	UNIT_TEST_TRUE(c.get<0>() == 'a', "get first of three elements");
	UNIT_TEST_TRUE(c.get<1>() == 5, "get second of three elements");
	UNIT_TEST_TRUE(c.get<2>() == 7, "get third of three elements");
	datatstruct::tuple<char &, int &, long &> d(c);
	UNIT_TEST_TRUE(&d.get<0>() == &c.get<0>(), "copy constructor");

/*
	float myfloat = 1.23;
	MyClass myobj;
	datastruct::tuple<float &, std::string, const MyClass &> c(myfloat, "alpha", myobj);
	UNIT_TEST_TRUE(math::real_equal<float>(c.get<0>(), 1.23) && &c.get<0>() == &myfloat, "get first of three elements (float &)");
	UNIT_TEST_TRUE(c.get<1>() == "alpha", "get second of three elements (std::string)");
	UNIT_TEST_TRUE(&c.get<2>() == &myobj, "get third of three elements (object)");

	float myfloat = 8.88;
	datastruct::tuple<float &, bool, char> b(myfloat, true, 'Z');
	UNIT_TEST_TRUE(math::real_equal(b.get<0>(), 8.88), "get first of two elements (float &)");
	UNIT_TEST_TRUE(&b.get<0>() == &myfloat, "get address of reference element");
	b.get<0>() = 1.23;
	UNIT_TEST_TRUE(math::real_equal(myfloat, 1.23), "modify variable through reference element");
	UNIT_TEST_TRUE(b.get<1>(), "get second of three elements");
	UNIT_TEST_TRUE(b.get<2>() == 'Z', "get third of three elements");
*/
}
