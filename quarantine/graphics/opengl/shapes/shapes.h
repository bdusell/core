#ifndef _GRAPHICS_SHAPES_SHAPES_H_
#define _GRAPHICS_SHAPES_SHAPES_H_

#include "graphics/types.h"
#include "graphics/opengl/drawing.h"
#include "math/util.h"
#include "math/cartesian/point.h"
#include "math/cartesian/rectangle.h"

namespace graphics {
namespace shapes {

///* Functions *///

/* Draw a centered unit square. */
void draw_square();

/* Draw a square given a half-side length. */
void draw_square(Float halfs);

/* Draw a rectangle given a half-width and a half-height. */
void draw_rect(Float halfw, Float halfh);

/* Draw a rectangle given two of its corners. */
void draw_rect(Float x1, Float y1, Float x2, Float y2);

/* Draw a solid line on the positive x-axis of a given half-thickness and
length. */
void draw_line(Float halft, Float l);

/* Draw a unit circle. */
void draw_circle(uint n);

/* Draw a circle with radius r. */
void draw_circle(uint n, Float r);

/* Draw an ellipse given x and y radii. */
void draw_ellipse(uint n, Float rx, Float ry);

/* Draw a ring given two radii. */
void draw_ring(uint n, Float r1, Float r2);

/* Draw an elliptical ring given x and y outer radii and a thickness. */
void draw_ring(uint n, Float rx, Float ry, Float t);

/* Draw a sector of a unit circle. */
void draw_sector(uint n, Float th1, Float th2);

/* Draw a sector of a circle with radius r. */
void draw_sector(uint n, Float th1, Float th2, Float r);

/* Draw a sector of an ellipse with x and y radii. */
void draw_sector(uint n, Float th1, Float th2, Float rx, Float ry);

/* Draw a circular arc given outer and inner radii. */
void draw_arc(uint n, Float th1, Float th2, Float r1, Float r2);

/* Draw an elliptical arc given outer x and y radii and a thickness. */
void draw_arc(uint n, Float th1, Float th2, Float rx, Float ry, Float t);

///* Types *///

enum carat_style { sharp, flat };

/* A packet of values which are the computationally hard parts of drawing a
carat shape. */
template <carat_style TipStyle, carat_style LegStyle>
class carat_hint;

/* Draw a carat shape with a certain tip and leg style. */
template <carat_style TipStyle, carat_style LegStyle>
void draw_carat(const carat_hint<TipStyle, LegStyle> &hint);

enum slant_style { horiz, vert, vert_outside };

template <slant_style BottomStyle, slant_style TopStyle>
class slant_hint;

template <slant_style BottomStyle, slant_style TopStyle>
void draw_slant(const slant_hint<BottomStyle, TopStyle> &hint);

typedef math::cartesian::rectangle<Float> rectf;
typedef math::cartesian::rectangle<Pixel> rectpx;

///* Implementations *///

template <>
class carat_hint<sharp, flat> {

public:

	carat_hint(Float W_, Float H_, Float t_);

	Float W, H, W_half, x1;
	scalar_function<Float> yA;
	Float y1;

};

template <>
void draw_carat<sharp, flat>(const carat_hint<sharp, flat> &hint);

template <>
class carat_hint<sharp, sharp> {

public:

	carat_hint(Float W_, Float H_, Float t_);
	
	Float W, H, W_half, y1;

};

template <>
void draw_carat<sharp, sharp>(const carat_hint<sharp, sharp> &hint);

template <>
class carat_hint<flat, flat> {

public:

	carat_hint(Float W_, Float H_, Float t_);
	
	Float W, H, W_half, x1, y1, tip_left, tip_right;
	scalar_function<Float> yA;

};

template <>
void draw_carat<flat, flat>(const carat_hint<flat, flat> &hint);

template <>
class carat_hint<flat, sharp> {

public:

	carat_hint(Float W_, Float H_, Float t_);
	
	Float W, H, W_half, y1, x1, y2;
	scalar_function<Float> yB;

};

template <>
void draw_carat<flat, sharp>(const carat_hint<flat, sharp> &hint);

template <>
class slant_hint<vert, vert> {

public:

	slant_hint(Float W_, Float H_, Float t_);

	Float W, H, y1;

};

template <>
void draw_slant<vert, vert>(const slant_hint<vert, vert> &hint);

template <>
class slant_hint<vert_outside, vert> {

public:

	slant_hint(Float W_, Float H_, Float t_);
	
	Float W, H, y1;

};

template <>
void draw_slant<vert_outside, vert>(const slant_hint<vert_outside, vert> &hint);

} // namespace shapes
} // namespace graphics

#endif
