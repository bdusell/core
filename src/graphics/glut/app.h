#ifndef _GRAPHICS_GLUT_APP_H_
#define _GRAPHICS_GLUT_APP_H_

#include <GL/glut.h>
#include "graphics/types.h"

namespace graphics {
namespace glut {

///* Constants *///

namespace callback {
enum {
	/* Flags for specifying which callbacks to register with the app class
	template. */
	display         = 1 << 0,
	reshape         = 1 << 1,
	keyboard        = 1 << 2,
	keyboard_up     = 1 << 3,
	mouse           = 1 << 4,
	motion          = 1 << 5,
	passive_motion  = 1 << 6,
	special         = 1 << 7,
	special_up      = 1 << 8,
	update          = 1 << 9
};
}

namespace mode {
enum {
	/* Flags for specifying window modes, to be used by the user App class
	in the window_mode() method. */
	rgb           = GLUT_RGB,
	depth         = GLUT_DEPTH,
	alpha         = GLUT_ALPHA,
	double_buffer = GLUT_DOUBLE
};
}

namespace mouse_button {
enum {
	/* Values for the button parameter in the mouse(button, state, x, y)
	method of the user App class. */
	left   = GLUT_LEFT_BUTTON,
	middle = GLUT_MIDDLE_BUTTON,
	right  = GLUT_RIGHT_BUTTON
};
}

namespace button_state {
enum {
	/* Values for the state parameter in the mouse(button, state, x, y)
	method of the user App class. */
	pressed  = GLUT_DOWN,
	released = GLUT_UP
};
}

namespace ascii_key {
enum {
	/* Mnemonics for some ASCII keys */
	esc       = 033,
	enter     = '\r',
	backspace = '\b',
	tab       = '\t'
};
}

namespace special_key {
enum {
	/* Values for non-ASCII keyboard keys. */
	f1        = GLUT_KEY_F1,
	f2        = GLUT_KEY_F2,
	f3        = GLUT_KEY_F3,
	f4        = GLUT_KEY_F4,
	f5        = GLUT_KEY_F5,
	f6        = GLUT_KEY_F6,
	f7        = GLUT_KEY_F7,
	f8        = GLUT_KEY_F8,
	f9        = GLUT_KEY_F9,
	f10       = GLUT_KEY_F10,
	f11       = GLUT_KEY_F11,
	f12       = GLUT_KEY_F12,
	left      = GLUT_KEY_LEFT,
	up        = GLUT_KEY_UP,
	right     = GLUT_KEY_RIGHT,
	down      = GLUT_KEY_DOWN,
	page_up   = GLUT_KEY_PAGE_UP,
	page_down = GLUT_KEY_PAGE_DOWN,
	home      = GLUT_KEY_HOME,
	end       = GLUT_KEY_END,
	insert    = GLUT_KEY_INSERT
};
}

///* Types *///

/* A wrapper class template for building interactive graphics applications. It
wraps around a user-provided App class, which is passed as a type parameter and
must conform to a certain interface corresponding to a set of callbacks that
are requested through a bitmask, which is the second template parameter,
Callbacks.

A complete program built from the user class App takes the form:

int main(int argc, char **argv) {
	return app<App, Callbacks>::run(argc, argv);
}

The class App must implement:

- Required
// A constructor taking the command line arguments to the program.
App(argc, argv);
// A function returning a bitwise-or of mode:: flags.
int window_mode();
// A function returning a string for the title of the window.
const char *window_title();
// A function performing initialization tasks which can only be done after the
// window has been created
void init();

Depending on the flags passed in Callbacks, it must implement:

- callback::display
void display();

- callback::reshape
void reshape(width, height);

- callback::keyboard
void keyboard(key, x, y);

- callback::keyboard_up
void keyboard_up(key, x, y);

- callback::mouse
// Use mouse_button:: and button_state:: flags
void mouse(button, state, x, y);

- callback::motion
void motion(x, y);

- callback::passive_motion
void passive_motion(x, y);

- callback::special
void special(key, x, y);

- callback::special_up
void special_up(key, x, y);

- callback::update
void update();
// A function returning the number of milliseconds for pausing between each
// frame.
int frame_time();

*/
template <typename App, int Callbacks = App::callbacks>
class app {

public:
	
	static int run(int &argc, char **argv) {
	
		glutInit(&argc, argv);

		App instance(argc, argv);
		__instance = &instance;

		glutInitDisplayMode(instance.window_mode());
		glutCreateWindow(instance.window_title());

#define _SET_CALLBACK( NAME ) \
		set_callback<Callbacks & callback:: NAME >();
		_SET_CALLBACK(display);
		_SET_CALLBACK(reshape);
		_SET_CALLBACK(keyboard);
		_SET_CALLBACK(keyboard_up);
		_SET_CALLBACK(mouse);
		_SET_CALLBACK(motion);
		_SET_CALLBACK(passive_motion);
		_SET_CALLBACK(special);
		_SET_CALLBACK(special_up);
		_SET_CALLBACK(update);
#undef _SET_CALLBACK

		instance.init();

		glutMainLoop();
		
		return 1;
		
	}

private:

	template <int N>
	static void set_callback();

	template <>
	inline static void set_callback<0>() {
	}

#define _DEFINE_SET_CALLBACK( NAME , GLUTNAME ) \
	template <> \
	inline static void set_callback<callback:: NAME >() { \
		glut ## GLUTNAME ## Func(& NAME ## _func); \
	}

	_DEFINE_SET_CALLBACK(display, Display)
	_DEFINE_SET_CALLBACK(reshape, Reshape)
	_DEFINE_SET_CALLBACK(keyboard, Keyboard)
	_DEFINE_SET_CALLBACK(keyboard_up, KeyboardUp)
	_DEFINE_SET_CALLBACK(mouse, Mouse)
	_DEFINE_SET_CALLBACK(motion, Motion)
	_DEFINE_SET_CALLBACK(passive_motion, PassiveMotion)
	_DEFINE_SET_CALLBACK(special, Special)
	_DEFINE_SET_CALLBACK(special_up, SpecialUp)

#undef _DEFINE_SET_CALLBACK

	template <>
	inline static void set_callback<callback::update>() {
		glutTimerFunc(
			app<App, Callbacks>::__instance->frame_time(),
			&app<App, Callbacks>::update_func,
			0
		);
	}

	// Display
	static void display_func() {
		__instance->display();
	}

	// Reshape
	static void reshape_func(int width, int height) {
		__instance->reshape(width, height);
	}

	// Keyboard
	static void keyboard_func(unsigned char key, int x, int y) {
		__instance->keyboard(key, x, y);
	}

	// KeyboardUp
	static void keyboard_up_func(unsigned char key, int x, int y) {
		__instance->keyboard_up(key, x, y);
	}

	// Mouse
	static void mouse_func(int button, int state, int x, int y) {
		__instance->mouse(button, state, x, y);
	}

	// Motion
	static void motion_func(int x, int y) {
		__instance->motion(x, y);
	}

	// PassiveMotion
	static void passive_motion_func(int x, int y) {
		__instance->passive_motion(x, y);
	}

	// Special
	static void special_func(int key, int x, int y) {
		__instance->special(key, x, y);
	}

	// SpecialUp
	static void special_up_func(int key, int x, int y) {
		__instance->special_up(key, x, y);
	}

	// Update
	static void update_func(int value) {
		__instance->update();
		glutPostRedisplay();
		glutTimerFunc(__instance->frame_time(), &update_func, value);
	}

	static App *__instance;
	
};

/* A convenient base class for applications to be wrapped by the app class
template which provides default implementations and utility functions. */
class app_base {

public:

	inline static void window_position(int x, int y) {
		glutInitWindowPosition(x, y);
	}

	inline static void window_size(int w, int h) {
		glutInitWindowSize(w, h);
	}

	inline static void window_size(const sizepx &size) {
		window_size(size.width(), size.height());
	}

	inline static void init() {
	}

};

/* Convert screen coordinates to 2D world coordinates. */
point2f screen_coord_to_world_coord(const pointpx &p, const sizepx &screen, const rectf &world) {
	return point2f(
		realdiv<Float>(p.x(), screen.width()) * world.xrange() + world.p1.x(),
		realdiv<Float>(screen.height() - p.y(), screen.height()) * world.yrange() + world.p1.y()
	);
}

/* A represenation of the application's window. */
class app_window {

public:

	inline point2f world_coord(const pointpx &p, const rectf &world) const {
		return screen_coord_to_world_coord(p, _size, world);
	}

	inline const sizepx &size() const { return _size; }

	inline void update(int w, int h) { _size.set(w, h); }

private:

	sizepx _size;

};

} // namespace glut
} // namespace graphics

#endif
