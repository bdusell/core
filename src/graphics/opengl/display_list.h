#ifndef GRAPHICS_OPENGL_DISPLAY_LIST_H
#define GRAPHICS_OPENGL_DISPLAY_LIST_H

#include <GL/gl.h>

namespace graphics {
namespace opengl {

///* Types *///

class display_list;
class display_list_capture;

/* A display list. */
class display_list {

public:

	/* Default constructor. Does not create a new display list. */
	inline display_list();
	
	/* Creates a new display list. */
	inline static display_list create();
	
	/* Get the display list's GL id. */
	inline GLuint get_id() const;
	
	/* Invoke the display list. */
	inline void draw() const;

private:

	inline display_list(GLuint id);
	GLuint _id;

};

/* A scoped object for capturing drawing commands for a display list. */
class display_list_capture {

public:

	/* Start recording. */
	inline display_list_capture(const display_list &list);
	
	/* Stop recording. */
	inline ~display_list_capture();

};

///* Implementations *///

display_list::display_list() {
}

display_list display_list::create() {
	return display_list(glGenLists(1));
}

GLuint display_list::get_id() const {
	return _id;
}

void display_list::draw() const {
	glCallList(_id);
}

display_list::display_list(GLuint id) : _id(id) {
}

display_list_capture::display_list_capture(const display_list &list) {
	glNewList(list.get_id(), GL_COMPILE);
}

display_list_capture::~display_list_capture() {
	glEndList();
}

} // namespace opengl
} // namespace graphics

#endif

