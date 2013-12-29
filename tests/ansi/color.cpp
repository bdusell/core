#include "ansi/color.h"
int main() {
#define _PRINT_COLOR( NAME ) \
	std::cout << ansi::color:: NAME << #NAME << ansi::color::clear << " text" << std::endl
	_PRINT_COLOR(black);
	_PRINT_COLOR(red);
	_PRINT_COLOR(green);
	_PRINT_COLOR(yellow);
	_PRINT_COLOR(blue);
	_PRINT_COLOR(magenta);
	_PRINT_COLOR(cyan);
	_PRINT_COLOR(white);
	return 0;
}
