/*
File: transform.h
Author: Brian DuSell

Matrix transformation utilities.
*/

#ifndef GRAPHICS_OPENGL_TRANSFORM_H
#define GRAPHICS_OPENGL_TRANSFORM_H

#include <GL/gl.h>
#include "math/cartesian/tuple.h"
#include "math/cartesian/vector.h"

namespace graphics {
namespace opengl {

///* Types *///

/* Matrix mode specifier. */
enum matrix_mode {
	modelview_matrix  = GL_MODELVIEW,
	projection_matrix = GL_PROJECTION,
	texture_matrix    = GL_TEXTURE,
	color_matrix      = GL_COLOR
};

/* A scoped matrix push; instantiate it to perform a GL matrix push on the
current matrix. */
class matrix_push {
public:

	/* Pushes the current matrix. */
	inline matrix_push();
	
	/* Sets the current matrix and pushes it. */
	inline matrix_push(matrix_mode mode);

	/* Pops the current matrix. */
	inline ~matrix_push();
	
};

///* Functions *///

/* Set the current matrix mode. */
inline void set_matrix_mode(matrix_mode mode);

/* Get the current matrix mode. */
inline matrix_mode get_matrix_mode();

/* Load the identity matrix. */
inline void load_identity();

/* Set the viewport. */
inline void set_viewport(GLint x, GLint y, GLsizei w, GLsizei h);

/* Translate the current matrix. */
template <typename T>
void translate(T x, T y, T z);
template <typename T>
void translate(const math::cartesian::tuple<T, 3> &v);

/* Translate the current matrix in the xy plane. */
template <typename T>
inline void translate(T x, T y);
template <typename T>
inline void translate(const math::cartesian::tuple<T, 2> &v);

/* Rotate the current matrix by a certain number of degrees normal to a certain
vector. */
template <typename T>
void rotate(T degrees, T x, T y, T z);
template <typename T>
void rotate(T degrees, math::cartesian::vector<T, 3> &normal);

/* Rotate the current matrix by a certain number of degrees in the xy plane. */
template <typename T>
void rotate(T degrees);

/* Scale the current matrix. */
template <typename T>
void scale(T x, T y, T z);

/* Scale the current matrix in the xy plane. */
template <typename T>
void scale(T x, T y);

///* Implementations *///

matrix_push::matrix_push() {
	glPushMatrix();
}

matrix_push::matrix_push(matrix_mode mode) {
	set_matrix_mode(mode);
	glPushMatrix();
}

matrix_push::~matrix_push() {
	glPopMatrix();
}

void set_matrix_mode(matrix_mode mode) {
	glMatrixMode((GLenum) mode);
}

matrix_mode get_matrix_mode() {
	GLint params[1];
	glGetIntegerv(GL_MATRIX_MODE, params);
	return (matrix_mode) params[0];
}

void load_identity() {
	glLoadIdentity();
}

void set_viewport(GLint x, GLint y, GLsizei w, GLsizei h) {
	glViewport(x, y, w, h);
}

template <typename T>
inline void translate(T x, T y, T z) {
	translate<GLfloat>(x, y, z);
}

template <>
inline void translate<GLfloat>(GLfloat x, GLfloat y, GLfloat z) {
	glTranslatef(x, y, z);
}

template <>
inline void translate<GLdouble>(GLdouble x, GLdouble y, GLdouble z) {
	glTranslated(x, y, z);
}

template <typename T>
inline void translate(const math::cartesian::tuple<T, 3> &v) {
	translate(v.x(), v.y(), v.z());
}

template <typename T>
inline void translate(T x, T y) {
	translate(x, y, T(0));
}

template <typename T>
inline void translate(const math::cartesian::tuple<T, 2> &v) {
	translate(v.x(), v.y());
}

template <>
inline void rotate<GLfloat>(GLfloat degrees, GLfloat x, GLfloat y, GLfloat z) {
	glRotatef(degrees, x, y, z);
}

template <>
inline void rotate<GLdouble>(GLdouble degrees, GLdouble x, GLdouble y, GLdouble z) {
	glRotated(degrees, x, y, z);
}

template <typename T>
inline void rotate(T degrees, const math::cartesian::vector<T, 3> &normal) {
	rotate(degrees, normal.x(), normal.y(), normal.z());
}

template <typename T>
inline void rotate(T degrees) {
	rotate(degrees, T(0), T(0), T(1));
}

template <>
inline void scale<GLfloat>(GLfloat x, GLfloat y, GLfloat z) {
	glScalef(x, y, z);
}

template <>
inline void scale<GLdouble>(GLdouble x, GLdouble y, GLdouble z) {
	glScaled(x, y, z);
}

template <typename T>
inline void scale(T x, T y) {
	scale(x, y, T(1));
}

} // namespace opengl
} // namespace graphics

#endif

