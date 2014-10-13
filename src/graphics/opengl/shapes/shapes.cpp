/*
File: shapes.cpp
Author: Brian DuSell
*/

#include <cmath>
#include "shapes.h"
//#include "drawing.h"
#include "math.h"

using namespace graphics::hw01;

void graphics::hw01::draw_square() {
	draw_square(-0.5f);
}

void graphics::hw01::draw_square(Float halfs) {
	draw_rect(halfs, halfs);
}

void graphics::hw01::draw_rect(Float halfw, Float halfh) {
	draw_rect(-halfw, -halfh, halfw, halfh);
}

void graphics::hw01::draw_rect(Float x1, Float y1, Float x2, Float y2) {
	{ drawing d(quads);
		d.vertex(x1, y1);
		d.vertex(x2, y1);
		d.vertex(x2, y2);
		d.vertex(x1, y2);
	}
}

void graphics::hw01::draw_line(Float t, Float l) {
	draw_rect(0.0f, -t, l, t);
}

void graphics::hw01::draw_circle(uint n) {
	draw_sector(n, 0.0f, 2.0f * pi);
}

void graphics::hw01::draw_circle(uint n, Float r) {
	draw_sector(n, 0.0f, 2.0f * pi, r);
}

void graphics::hw01::draw_ellipse(uint n, Float rx, Float ry) {
	draw_sector(n, 0.0f, 2.0f * pi, rx, ry);
}

void graphics::hw01::draw_ring(uint n, Float r1, Float r2) {
	draw_arc(n, 0.0f, 2.0f * pi, r1, r2);
}

void graphics::hw01::draw_ring(uint n, Float rx, Float ry, Float t) {
	draw_arc(n, 0.0f, 2.0f * pi, rx, ry, t);
}

void graphics::hw01::draw_sector(uint n, Float th1, Float th2) {
	Float theta;
	Float scale = (th2 - th1) / n;
	{ drawing d(triangle_fan);
		d.vertex(0.0f, 0.0f);
		for(uint i = 0; i <= n; ++i) {
			theta = i * scale + th1;
			d.vertex(cos(theta), sin(theta));
		}
	}
}

void graphics::hw01::draw_sector(uint n, Float th1, Float th2, Float r) {
	Float theta;
	Float scale = (th2 - th1) / n;
	{ drawing d(triangle_fan);
		d.vertex(0.0f, 0.0f);
		for(uint i = 0; i <= n; ++i) {
			theta = i * scale + th1;
			d.vertex(r * cos(theta), r *sin(theta));
		}
	}
}

void graphics::hw01::draw_sector(uint n, Float th1, Float th2,
	Float rx, Float ry) {
	Float theta;
	Float scale = (th2 - th1) / n;
	{ drawing d(triangle_fan);
		d.vertex(0.0f, 0.0f);
		for(uint i = 0; i <= n; ++i) {
			theta = i * scale + th1;
			d.vertex(rx * cos(theta), ry * sin(theta));
		}
	}
}

void graphics::hw01::draw_arc(uint n, Float th1, Float th2,
	Float r1, Float r2) {

	Float theta, sin_, cos_;
	Float scale = (th2 - th1) / n;
	{ drawing d(quad_strip);
		for(uint i = 0; i <= n; ++i) {
			theta = i * scale + th1;
			sin_ = sin(theta);
			cos_ = cos(theta);
			d.vertex(r1 * cos_, r1 * sin_);
			d.vertex(r2 * cos_, r2 * sin_);
		}
	}

}

void graphics::hw01::draw_arc(uint n, Float th1, Float th2,
	Float rx, Float ry, Float t) {

	Float theta, sin_, cos_;
	Float scale = (th2 - th1) / n;
	Float rx0 = rx - t, ry0 = ry - t;
	{ drawing d(quad_strip);
		for(uint i = 0; i <= n; ++i) {
			theta = i * scale + th1;
			sin_ = sin(theta);
			cos_ = cos(theta);
			d.vertex(rx0 * cos_, ry0 * sin_);
			d.vertex(rx * cos_, ry * sin_);
		}
	}

}

graphics::hw01::carat_hint<sharp, flat>::carat_hint(
	Float W_, Float H_, Float t_) :
	
	W(W_),
	H(H_),
	W_half(W / 2.0f),
	x1(t_ / H * sqrt(sqr(H) + sqr(W_half))),
	yA(H / W_half),
	y1(yA(W_half - x1))

	{
}

template <>
void graphics::hw01::draw_carat<sharp, flat>(
	const carat_hint<sharp, flat> &hint) {
	
	{ drawing d(quad_strip);
		d.vertex(0.0f, 0.0f);
		d.vertex(hint.x1, 0.0f);
		d.vertex(hint.W_half, hint.H);
		d.vertex(hint.W_half, hint.y1);
		d.vertex(hint.W, 0.0f);
		d.vertex(hint.W - hint.x1, 0.0f);
	}
}

graphics::hw01::carat_hint<sharp, sharp>::carat_hint(
	Float W_, Float H_, Float t_) :
	
	W(W_),
	H(H_),
	W_half(W / 2.0f)
	{

	Float C1 = sqr(t_ / W_half);
	Float a = 1.0f - C1;
	Float b = 2.0f * C1 * H;
	Float c = -sqr(t_) - C1 * sqr(H);
	y1 = quadratic_formula<Float>(a, b, c).soln_plus();

}

template <>
void graphics::hw01::draw_carat<sharp, sharp>(
	const carat_hint<sharp, sharp> &hint) {
	
	{ drawing d(quad_strip);
		d.vertex(0.0f, 0.0f);
		d.vertex(0.0f, hint.y1);
		d.vertex(hint.W_half, hint.H - hint.y1);
		d.vertex(hint.W_half, hint.H);
		d.vertex(hint.W, 0.0f);
		d.vertex(hint.W, hint.y1);
	}
}

graphics::hw01::carat_hint<flat, flat>::carat_hint(
	Float W_, Float H_, Float t_) :

	W(W_),
	H(H_),
	W_half(W / 2.0f)
	{
		
	Float C1 = sqr(t_ / (2.0f * H));
	Float a = 1.0f - C1;
	Float b = 2.0f * C1 * W;
	Float c = -sqr(t_) - C1 * sqr(W);
	x1 = quadratic_formula<Float>(a, b, c).soln_plus();
	
	tip_left = (W - x1) / 2.0f;
	tip_right = W - tip_left;
	yA.c = H / tip_left;
	y1 = yA(W_half - x1);

}

template <>
void graphics::hw01::draw_carat<flat, flat>(
	const carat_hint<flat, flat> &hint) {

	{ drawing d(triangle_fan);
		d.vertex(hint.W_half, hint.y1);
		d.vertex(hint.x1, 0.0f);
		d.vertex(0.0f, 0.0f);
		d.vertex(hint.tip_left, hint.H);
		d.vertex(hint.tip_right, hint.H);
		d.vertex(hint.W, 0.0f);
		d.vertex(hint.W - hint.x1, 0.0f);
	}
}

graphics::hw01::carat_hint<flat, sharp>::carat_hint(
	Float W_, Float H_, Float t_) :

	W(W_),
	H(H_),
	W_half(W / 2.0f)
	{

	Float C1 = sqr(t_ / W);
	Float a = 1.0f - C1;
	Float b = -2.0f * H * (1.0f + C1);
	Float c = sqr(H) * (1.0f - C1) - sqr(t_);
	y1 = quadratic_formula<Float>(a, b, c).soln_minus();
	x1 = (W * y1) / (H + y1);
	yB.c = y1 / x1;
	y2 = yB(W_half);
}

template <>
void graphics::hw01::draw_carat<flat, sharp>(
	const carat_hint<flat, sharp> &hint) {
	
	{ drawing d(triangle_fan);
		d.vertex(hint.W_half, hint.y2);
		d.vertex(0.0f, 0.0f);
		d.vertex(0.0f, hint.H - hint.y1);
		d.vertex(hint.x1, hint.H);
		d.vertex(hint.W - hint.x1, hint.H);
		d.vertex(hint.W, hint.H - hint.y1);
		d.vertex(hint.W, 0.0f);
	}
}

graphics::hw01::slant_hint<vert, vert>::slant_hint(
	Float W_, Float H_, Float t_) :
	W(W_),
	H(H_)
	{
	
	Float C1 = sqr(t_ / W);
	Float a = 1.0f - C1;
	Float b = 2.0f * C1 * H;
	Float c = -sqr(t_) - C1 * sqr(H);
	y1 = quadratic_formula<Float>(a, b, c).soln_plus();
}

template <>
void graphics::hw01::draw_slant(const slant_hint<vert, vert> &hint) {
	{ drawing d(quads);
		d.vertex(0.0f, 0.0f);
		d.vertex(hint.W, hint.H - hint.y1);
		d.vertex(hint.W, hint.H);
		d.vertex(0.0f, hint.y1);
	}
}

graphics::hw01::slant_hint<vert_outside, vert>::slant_hint(
	Float W_, Float H_, Float t_) :
	W(W_),
	H(H_),
	y1(t_ / W * sqrt(sqr(H) + sqr(W)))
	{
}

template <>
void graphics::hw01::draw_slant(
	const slant_hint<vert_outside, vert> &hint) {
	{ drawing d(quads);
		d.vertex(0.0f, -hint.y1);
		d.vertex(hint.W, hint.H - hint.y1);
		d.vertex(hint.W, hint.H);
		d.vertex(0.0f, 0.0f);
	}
}

