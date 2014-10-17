#ifndef _GRAPHICS_OPENGL_TYPES_H_
#define _GRAPHICS_OPENGL_TYPES_H_

#include <GL/gl.h>
#include "math/cartesian/point.h"
#include "math/cartesian/vector.h"
#include "math/cartesian/size.h"
#include "math/cartesian/rectangle.h"
#include "graphics/color/rgb.h"

namespace graphics {

/* Floating-point number type. */
typedef GLfloat Float;

/* Double-precision floating-point number type. */
typedef GLdouble Double;

/* Unsigned integer type. */
typedef unsigned int uint;

/* Pixel type. */
typedef int Pixel;

typedef math::cartesian::point<Float, 2> point2f;
typedef math::cartesian::point<Float, 3> point3f;
typedef math::cartesian::point<Float, 4> point4f;

typedef math::cartesian::vector<Float, 2> vector2f;
typedef math::cartesian::vector<Float, 3> vector3f;
typedef math::cartesian::vector<Float, 4> vector4f;

typedef graphics::color::rgb<Float, 3> rgbf;
typedef graphics::color::rgb<Float, 4> rgbaf;

typedef math::cartesian::point<Pixel, 2> pointpx;
typedef math::cartesian::size<Pixel, 2> sizepx;

typedef math::cartesian::rectangle<Float> rectf;

}

#endif
