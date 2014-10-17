#include "meta/param.h"
#include "unit_test.h"
#include "meta/same_type.h"

struct MySmallClass { char c; };
struct MyLargeClass { int *a, *b; };

UNIT_TEST(meta_param) {
#define _SAME_TYPE(T, U, MSG) \
	UNIT_TEST_TRUE((meta::same_type<meta::param<T>::type, U>::value), MSG);
	_SAME_TYPE(char, char, "small primitive maps to self")
	_SAME_TYPE(long double, const long double &, "large primitive maps to reference to const")
	_SAME_TYPE(MySmallClass, const MySmallClass &, "small class maps to reference to const")
	_SAME_TYPE(MyLargeClass, const MyLargeClass &, "large class maps to reference to const")
	_SAME_TYPE(const char, char, "small const primitive maps to non-const self")
	_SAME_TYPE(const long double, const long double &, "large const primitive maps to reference to const")
	_SAME_TYPE(char *, char *, "pointer to non-const maps to self");
	_SAME_TYPE(const char *, const char *, "pointer to const maps to self");
	_SAME_TYPE(char * const, char *, "const pointer to non-const maps to non-const pointer to non-const")
	_SAME_TYPE(char &, char &, "reference to non-const maps to self")
	_SAME_TYPE(const char &, const char &, "reference to const maps to self (don\'t pass by value - you might want the address)")
	_SAME_TYPE(char *&, char *&, "reference to pointer maps to self")
	_SAME_TYPE(const char * const &, const char * const &, "reference to const pointer to const maps to self")
	_SAME_TYPE(char[3], const char(&)[3], "array maps to reference to array of const")
	_SAME_TYPE(const char[3], const char(&)[3], "array of const maps to reference to array of const")
	_SAME_TYPE(char(&)[3], char(&)[3], "reference to array of non-const maps to self")
	_SAME_TYPE(const char(&)[3], const char(&)[3], "reference to array of const maps to self")
}
