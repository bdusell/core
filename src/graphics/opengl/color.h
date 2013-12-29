#ifndef GRAPHICS_OPENGL_COLOR_H
#define GRAPHICS_OPENGL_COLOR_H

#include <GL/gl.h>
#include "graphics/color/rgb.h"

namespace graphics {
namespace opengl {

///* Functions *///

/* Set the current color. */
template <typename T>
void set_color(T r, T g, T b);

template <typename T>
void set_color(T r, T g, T b, T a);

template <typename T, int N>
inline void set_color(const graphics::color::rgb<T, N> &c);

/* Get the current color from the GL. */
template <typename T>
graphics::color::rgb<T, 4> get_color();

template <typename T>
void get_color(graphics::color::rgb<T, 4> &result);

template <>
inline void get_color(graphics::color::rgb<GLdouble, 4> &result);

template <>
inline void get_color(graphics::color::rgb<GLfloat, 4> &result);

template <>
inline void get_color(graphics::color::rgb<GLint, 4> &result);

/* Set the background or clear color of the GL. */
inline void set_background(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

template <>
inline void set_color<GLbyte>(GLbyte r, GLbyte g, GLbyte b) {
	glColor3b(r, g, b);
}

template <>
inline void set_color<GLshort>(GLshort r, GLshort g, GLshort b) {
	glColor3s(r, g, b);
}

template <>
inline void set_color<GLint>(GLint r, GLint g, GLint b) {
	glColor3i(r, g, b);
}

template <>
inline void set_color<GLfloat>(GLfloat r, GLfloat g, GLfloat b) {
	glColor3f(r, g, b);
}

template <>
inline void set_color<GLdouble>(GLdouble r, GLdouble g, GLdouble b) {
	glColor3d(r, g, b);
}

template <>
inline void set_color<GLubyte>(GLubyte r, GLubyte g, GLubyte b) {
	glColor3ub(r, g, b);
}

template <>
inline void set_color<GLushort>(GLushort r, GLushort g, GLushort b) {
	glColor3us(r, g, b);
}

template <>
inline void set_color<GLuint>(GLuint r, GLuint g, GLuint b) {
	glColor3ui(r, g, b);
}

template <>
inline void set_color<GLbyte>(GLbyte r, GLbyte g, GLbyte b, GLbyte a) {
	glColor4b(r, g, b, a);
}

template <>
inline void set_color<GLshort>(GLshort r, GLshort g, GLshort b, GLshort a) {
	glColor4s(r, g, b, a);
}

template <>
inline void set_color<GLint>(GLint r, GLint g, GLint b, GLint a) {
	glColor4i(r, g, b, a);
}

template <>
inline void set_color<GLfloat>(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	glColor4f(r, g, b, a);
}

template <>
inline void set_color<GLdouble>(GLdouble r, GLdouble g, GLdouble b, GLdouble a) {
	glColor4d(r, g, b, a);
}

template <>
inline void set_color<GLubyte>(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
	glColor4ub(r, g, b, a);
}

template <>
inline void set_color<GLushort>(GLushort r, GLushort g, GLushort b, GLushort a) {
	glColor4us(r, g, b, a);
}

template <>
inline void set_color<GLuint>(GLuint r, GLuint g, GLuint b, GLuint a) {
	glColor4ui(r, g, b, a);
}

template <typename T, int N>
inline void set_color(const graphics::color::rgb<T, N> &c) {
	set_color(c.r(), c.g(), c.b());
}

template <typename T>
graphics::color::rgb<T, 4> get_color() {
	rgb<T, 4> result;
	get_color(result);
	return result;
}

template <>
void get_color(graphics::color::rgb<GLdouble, 4> &result) {
	glGetDoublev(GL_CURRENT_COLOR, result.array());
}

template <>
void get_color(graphics::color::rgb<GLfloat, 4> &result) {
	glGetFloatv(GL_CURRENT_COLOR, result.array());
}

template <>
void get_color(graphics::color::rgb<GLint, 4> &result) {
	glGetIntegerv(GL_CURRENT_COLOR, result.array());
}

void set_background(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	glClearColor(r, g, b, a);
}

} // namespace opengl
} // namespace graphics

#endif

