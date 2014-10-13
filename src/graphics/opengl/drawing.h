#ifndef _GRAPHICS_OPENGL_DRAWING_H_
#define _GRAPHICS_OPENGL_DRAWING_H_

#include <GL/gl.h>
#include "meta/param.h"

namespace graphics {
namespace opengl {

///* Types *///

/* Drawing modes. */
enum drawing_mode {
	points         = GL_POINTS,
	lines          = GL_LINES,
	line_strip     = GL_LINE_STRIP,
	line_loop      = GL_LINE_LOOP,
	triangles      = GL_TRIANGLES,
	triangle_strip = GL_TRIANGLE_STRIP,
	triangle_fan   = GL_TRIANGLE_FAN,
	quads          = GL_QUADS,
	quad_strip     = GL_QUAD_STRIP,
	polygon        = GL_POLYGON
};

class drawing;

/* Scoped object for drawing a shape. */
class drawing {

public:

	/* Start drawing the shape. */
	inline drawing(drawing_mode mode);

	/* Stop drawing the shape. */
	inline ~drawing();
	
	/* Specify a vertex for the shape. */
	template <typename T>
	void vertex(T x, T y) const;
	
	template <typename T>
	void vertex(T x, T y, T x) const;
	
	template <typename T>
	void vertex(T x, T y, T x, T w) const;

};

///* Implementations *///

drawing::drawing(drawing_mode mode) {
	glBegin((GLuint) mode);
}

drawing::~drawing() {
	glEnd();
}

template <>
inline void drawing::vertex<GLshort>(GLshort x, GLshort y) const {
	glVertex2s(x, y);
}

template <>
inline void drawing::vertex<GLint>(GLint x, GLint y) const {
	glVertex2i(x, y);
}

template <>
inline void drawing::vertex<GLfloat>(GLfloat x, GLfloat y) const {
	glVertex2f(x, y);
}

template <>
inline void drawing::vertex<GLdouble>(GLdouble x, GLdouble y) const {
	glVertex2d(x, y);
}

template <>
inline void drawing::vertex<GLshort>(GLshort x, GLshort y, GLshort z) const {
	glVertex3s(x, y, z);
};

template <>
inline void drawing::vertex<GLint>(GLint x, GLint y, GLint z) const {
	glVertex3i(x, y, z);
};

template <>
inline void drawing::vertex<GLfloat>(GLfloat x, GLfloat y, GLfloat z) const {
	glVertex3f(x, y, z);
};

template <>
inline void drawing::vertex<GLdouble>(GLdouble x, GLdouble y, GLdouble z) const {
	glVertex3d(x, y, z);
};

template <>
inline void drawing::vertex<GLshort>(GLshort x, GLshort y, GLshort z, GLshort w) const {
	glVertex4s(x, y, z, w);
};

template <>
inline void drawing::vertex<GLint>(GLint x, GLint y, GLint z, GLint w) const {
	glVertex4i(x, y, z, w);
};

template <>
inline void drawing::vertex<GLfloat>(GLfloat x, GLfloat y, GLfloat z, GLfloat w) const {
	glVertex4f(x, y, z, w);
};

template <>
inline void drawing::vertex<GLdouble>(GLdouble x, GLdouble y, GLdouble z, GLdouble w) const {
	glVertex4d(x, y, z, w);
};

} // namespace opengl
} // namespace graphics

#endif
