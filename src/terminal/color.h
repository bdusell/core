#ifndef _TERMINAL_COLOR_H_
#define _TERMINAL_COLOR_H_

#include <iostream>

namespace terminal {
namespace color {

enum color_code { black, red, green, yellow, blue, magenta, cyan, white };
enum clear_code { clear = white + 1 };

} // namespace color
} // namespace terminal

inline std::ostream &operator<<(std::ostream &output, terminal::color::color_code c) {
	char str[] = {033, '[', '3', 0, 'm', 0};
	str[3] = '0' + c;
	return output << str;
}

inline std::ostream &operator<<(std::ostream &output, terminal::color::clear_code c) {
	return output << "\033[0m";
}

#endif

