#ifndef GRAPHICS_GLUT_MOUSE_H
#define GRAPHICS_GLUT_MOUSE_H

#include "graphics/types.h"
#include "graphics/glut/app.h"

namespace graphics {
namespace glut {

class mouse {

public:

	mouse() : _left(false), _middle(false), _right(false) {}

	bool &left() { return _left; }
	bool &middle() { return _middle; }
	bool &right() { return _right; }

	const pointpx &pos() const { return _location; }

	inline void update(int x, int y) { _location.set(x, y); }

	void update(int x, int y, int button, int state) {
		update(x, y);
		bool pressed = state == button_state::pressed;
		switch(button) {
		case mouse_button::left:
			_left = pressed;
			break;
		case mouse_button::middle:
			_middle = pressed;
			break;
		case mouse_button::right:
			_right = pressed;
			break;
		}
	}

private:

	pointpx _location;
	bool _left, _middle, _right;

};

} // namespace glut
} // namespace graphics

#endif

