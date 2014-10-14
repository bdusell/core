#include "terminal/color.h"
#include <sstream>
#include "unit_test.h"

UNIT_TEST(terminal_color) {
#define _TEST_COLOR(name, num) \
	{ \
		std::stringstream out; \
		out << terminal::color::name; \
		UNIT_TEST_EQUAL(out.str(), "\033[" #num "m", #name " color code is correct"); \
	}
	_TEST_COLOR(clear,   0)
	_TEST_COLOR(black,   30)
	_TEST_COLOR(red,     31)
	_TEST_COLOR(green,   32)
	_TEST_COLOR(yellow,  33)
	_TEST_COLOR(blue,    34)
	_TEST_COLOR(magenta, 35)
	_TEST_COLOR(cyan,    36)
	_TEST_COLOR(white,   37)
}
