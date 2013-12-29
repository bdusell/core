#ifndef GRAPHICS_GLUT_KEYBOARD_H
#define GRAPHICS_GLUT_KEYBOARD_H

#include <map>

namespace graphics {
namespace glut {

/* A mapping of keyboard keys to boolean switches. */
template <typename Key>
class keyboard_reader {

	typedef std::map<Key, bool *> map_type;

public:

	inline void bind(Key k, bool &b) { mapping[k] = &b; }

	void update(Key k, bool pressed) {
		typename map_type::iterator i = mapping.find(k);
		if(i != mapping.end()) *i->second = pressed;
	}

private:

	map_type mapping;

};

/* A GLUT special key. */
typedef unsigned int special_key;

/* A GLUT ASCII key. */
typedef char ascii_key;

/* A keyboard mapping for special keys. */
typedef keyboard_reader<special_key> special_keyboard_reader;

/* A keyboard mapping for ASCII keys. */
typedef keyboard_reader<ascii_key> ascii_keyboard_reader;

} // namespace glut
} // namespace graphics

#endif

