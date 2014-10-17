#ifndef _GRAPHICS_GLUT_APP_H_
#define _GRAPHICS_GLUT_APP_H_

#include <GL/glut.h>
#include "graphics/opengl/types.h"
#include "math/util.h"

namespace graphics {
namespace glut {

namespace callback {
/* Flags for specifying which callbacks to register with the app class
 * template. */
enum {
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

/* Flags for specifying window modes. These are to be used by the user `App`
 * class in the `window_mode` member function. */
namespace mode {
enum {
	rgb           = GLUT_RGB,
	depth         = GLUT_DEPTH,
	alpha         = GLUT_ALPHA,
	double_buffer = GLUT_DOUBLE
};
}

/* Values for the `button` parameter in the `mouse` member function of the
 * user `App` class. */
namespace mouse_button {
enum {
	left   = GLUT_LEFT_BUTTON,
	middle = GLUT_MIDDLE_BUTTON,
	right  = GLUT_RIGHT_BUTTON
};
}

/* Values for the `state` parameter in the `mouse` member function of the
 * user `App` class. */
namespace button_state {
enum {
	pressed  = GLUT_DOWN,
	released = GLUT_UP
};
}

/* Mnemonics for some ASCII keys as recognized by GLUT. */
namespace ascii_key {
enum {
	esc       = 033,
	enter     = '\r',
	backspace = '\b',
	tab       = '\t'
};
}

/* Values for non-ASCII ("special") keyboard keys. */
namespace special_key {
enum {
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

/* A class template for building interactive graphics applications using GLUT.
 * A user-defined GLUT application is built by defining a class which defines
 * a certain set of member functions and passing this class's type as the
 * template parameter `app` to this class. The `Callbacks` parameter is a
 * set of flags which determines which member functions will be registered with
 * GLUT.
 *
 * A program's main function will have a form like:
 * ```
 * int main(int argc, char **argv) {
 *   return app<MyApp, MyApp::callbacks>::run(argc, argv);
 * }
 * ```
 *
 * User application API
 * --------------------
 *
 * The `app` class must implement the following member functions.
 *
 * * `app(argc, argv)` (constructor)
 * * `int window_mode()`
 *   Returns window mode flags.
 * * `const char *window_title()`
 *   Returns a string for the title of the window.
 * * `void init()`
 *   Performs initialization tasks which can only be done after the window has
 *   been created.
 * * `int frame_time()`
 *   Returns the number of milliseconds to pause between each frame. Note that
 *   this can be changed dynamically.
 *
 * The callbacks which may optionally be defined depending on the flags passed
 * in `Callbacks` are as follows. The name of the corresponding flag is always
 * the same as the name of the member function.
 *
 * * `void display()`
 * * `void reshape()`
 * * `void keyboard(key, x, y)`
 * * `void keyboard_up(key, x, y)`
 * * `void mouse(button, state, x, y)`
 * * `void motion(x, y)`
 * * `void passive_motion(x, y)`
 * * `void special(key, x, y)`
 * * `void special_up(key, x, y)`
 * * `void update()`
 */
template <typename App, int Callbacks = App::callbacks>
class app {

public:

	static int run(int &argc, char **argv);

private:

	static void display_func() {
		__instance->display();
	}

	static void reshape_func(int width, int height) {
		__instance->reshape(width, height);
	}

	static void keyboard_func(unsigned char key, int x, int y) {
		__instance->keyboard(key, x, y);
	}

	static void keyboard_up_func(unsigned char key, int x, int y) {
		__instance->keyboard_up(key, x, y);
	}

	static void mouse_func(int button, int state, int x, int y) {
		__instance->mouse(button, state, x, y);
	}

	static void motion_func(int x, int y) {
		__instance->motion(x, y);
	}

	static void passive_motion_func(int x, int y) {
		__instance->passive_motion(x, y);
	}

	static void special_func(int key, int x, int y) {
		__instance->special(key, x, y);
	}

	static void special_up_func(int key, int x, int y) {
		__instance->special_up(key, x, y);
	}

	static void update_func(int value) {
		__instance->update();
		glutPostRedisplay();
		glutTimerFunc(__instance->frame_time(), &update_func, value);
	}

	static App *__instance;
};

template <typename App, int Callbacks>
int app<App, Callbacks>::run(int &argc, char **argv) {

	glutInit(&argc, argv);

	App instance(argc, argv);
	__instance = &instance;

	glutInitDisplayMode(instance.window_mode());
	glutCreateWindow(instance.window_title());

#define _SET_CALLBACK(NAME, GLUT_NAME) \
	if(Callbacks & callback::NAME) { \
		glut ## GLUT_NAME ## Func(&NAME ## _func); \
	}
	_SET_CALLBACK(display, Display);
	_SET_CALLBACK(reshape, Reshape);
	_SET_CALLBACK(keyboard, Keyboard);
	_SET_CALLBACK(keyboard_up, KeyboardUp);
	_SET_CALLBACK(mouse, Mouse);
	_SET_CALLBACK(motion, Motion);
	_SET_CALLBACK(passive_motion, PassiveMotion);
	_SET_CALLBACK(special, Special);
	_SET_CALLBACK(special_up, SpecialUp);
#undef _SET_CALLBACK

	if(Callbacks & callback::update) {
		glutTimerFunc(
			app<App, Callbacks>::__instance->frame_time(),
			&app<App, Callbacks>::update_func,
			0
		);
	}

	instance.init();
	glutMainLoop();
	return 1;
}

/* A convenient base class which provides some useful defaults and utility
 * functions to user classes which will be wrapped by `app`. */
class app_base {

public:

	inline static void window_position(int x, int y) {
		glutInitWindowPosition(x, y);
	}

	inline static void window_size(int w, int h) {
		glutInitWindowSize(w, h);
	}

	inline static void window_size(const graphics::sizepx &size) {
		window_size(size.width(), size.height());
	}

	inline static void init() {
	}
};

/* Convert screen coordinates to 2D world coordinates. */
point2f screen_coord_to_world_coord(
	const pointpx &p,
	const sizepx &screen,
	const rectf &world)
{
	return point2f(
		(Float) p.x() / (Float) screen.width() * world.xrange() + world.p1.x(),
		(Float) (screen.height() - p.y()) / (Float) screen.height() * world.yrange() + world.p1.y()
	);
}

/* A represenation of the application's window. */
class app_window {

public:

	inline point2f world_coord(
		const pointpx &p,
		const rectf &world)
	const {
		return screen_coord_to_world_coord(p, _size, world);
	}

	inline const sizepx &size() const {
		return _size;
	}

	inline void update(int w, int h) { _size.set(w, h); }

private:

	sizepx _size;
};

} // namespace glut
} // namespace graphics

#endif
