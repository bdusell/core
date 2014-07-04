/*
File: shapes.h
Author: Brian DuSell

Shape drawing utilities.
*/

#ifndef GRAPHICS_HW01_SHAPES_H
#define GRAPHICS_HW01_SHAPES_H

#include "math.h"
//#include "types.h"
//#include "point.h"
//#include "drawing.h"

namespace graphics {
namespace hw01 {

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

template <typename T>
class rect;

template <typename T>
class rect {

public:

	typedef point<T, 2> point_type;

	inline rect(T x1, T y1, T x2, T y2);
	inline rect(const point_type &p1, const point_type &p2);

	inline void set(T x1, T y1, T x2, T y2);

	template <typename U>
	inline void clamp(point<U, 2> &p) const;

	inline point_type center() const;
	inline T xrange() const;
	inline T yrange() const;

	point_type p1, p2;

};

typedef rect<Float> rectf;
typedef rect<Pixel> rectpx;

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

template <typename T>
rect<T>::rect(T x1, T y1, T x2, T y2) : p1(x1, y1), p2(x2, y2) {}

template <typename T>
rect<T>::rect(const point_type &p1_, const point_type &p2_) : p1(p1_), p2(p2_) {}

template <typename T>
void rect<T>::set(T x1, T y1, T x2, T y2) {
	p1.set(x1, y1);
	p2.set(x2, y2);
}

template <typename T>	
typename rect<T>::point_type rect<T>::center() const {
	return p1 + (p2 - p1) / 2;
}

template <typename T>
template <typename U>
void rect<T>::clamp(point<U, 2> &p) const {
	p.set(
		graphics::hw01::clamp<T>(p.x(), p1.x(), p2.x()),
		graphics::hw01::clamp<T>(p.y(), p1.y(), p2.y())
	);
}

template <typename T>
T rect<T>::xrange() const {
	return p2.x() - p1.x();
}

template <typename T>
T rect<T>::yrange() const {
	return p2.y() - p1.y();
}

} // namespace hw01
} // namespace graphics

#endif

