/*
File: alphabet.cpp
Author: Brian DuSell
*/

#include "graphics/shapes/alphabet.h"
#include <cmath>
#include <cstring>
//#include "math/math.h"
#include "graphics/opengl/transform.h"
#include "graphics/opengl/drawing.h"
#include "graphics/shapes/shapes.h"

#define SEGMENTS 30

using namespace graphics;
using namespace graphics::opengl;

void graphics::opengl::draw_string(const char *s, Float width, Float height,
	Float thickness, Float separation) {
	char c = *s++;
	Float shift = width + separation;

	if(!c) return; // If string is empty, do nothing

	{ matrix_push p;
		while(true) {
			// Letter to be drawn is stored in c and is not null
			draw_letter(c, width, height, thickness);
			if(!(c = *s++)) break; // Get the next letter, or stop when null
			translate<Float>(shift, 0.0f); // A letter will be drawn, so translate
		}
	}
}

Float graphics::opengl::draw_string_width(unsigned int length, Float width,
	Float spacing) {

	return max((length * width) + ((length - 1) * spacing), 0.0f);

}

void graphics::opengl::draw_letter(char c, Float width, Float height,
	Float thickness) {
	
	// Thank you, Python
	typedef void (*function_ptr)(Float, Float, Float);
	static const function_ptr function_array[] = {
		&drawA,
		&drawB,
		&drawC,
		&drawD,
		&drawE,
		&drawF,
		&drawG,
		&drawH,
		&drawI,
		&drawJ,
		&drawK,
		&drawL,
		&drawM,
		&drawN,
		&drawO,
		&drawP,
		&drawQ,
		&drawR,
		&drawS,
		&drawT,
		&drawU,
		&drawV,
		&drawW,
		&drawX,
		&drawY,
		&drawZ
	};
	
	if('A' <= c && c <= 'Z') {
		function_array[c - 'A'](width, height, thickness);
	}
	
}

void graphics::opengl::drawA(Float W, Float H, Float t) {

	carat_hint<flat, flat> hint(W, H, t);
	draw_carat(hint);

	Float top = H / 2.0f;
	Float bottom = top - t;
	Float x1_half = hint.x1 / 2.0f;
	Float x1 = hint.yA.inv(bottom) + x1_half;
	Float x2 = hint.yA.inv(top) + x1_half;
	{ drawing d(quads);
		d.vertex(x1, bottom);
		d.vertex(W - x1, bottom);
		d.vertex(W - x2, top);
		d.vertex(x2, top);
	}

}

void graphics::opengl::drawB(Float W, Float H, Float t) {

	Float r = (H + t) / 4.0f;
	
	drawE(W - r, H, t);

	{ matrix_push p;
		translate(W - r, r);
		draw_arc(SEGMENTS, -pi / 2.0f, pi / 2.0f, r - t, r);
		translate(0.0f, 2.0f * r - t);
		draw_arc(SEGMENTS, -pi / 2.0f, pi / 2.0f, r - t, r);
	}

}

void graphics::opengl::drawC(Float W, Float H, Float t) {
	Float rx = W / (1.0f + 1.0f / sqrt(2.0f));
	{ matrix_push p;
		translate(rx, H / 2.0f);
		draw_arc(SEGMENTS, pi / 4.0f, pi * 7.0f / 4.0f, rx, H / 2.0f, t);
	}
}

void graphics::opengl::drawD(Float W, Float H, Float t) {

	Float r = H / 2.0f;

	{ drawing d(quad_strip);
		d.vertex(W - r, 0.0f);
		d.vertex(W - r, t);
		d.vertex(0.0f, 0.0f);
		d.vertex(t, t);
		d.vertex(0.0f, H);
		d.vertex(t, H - t);
		d.vertex(W - r, H);
		d.vertex(W - r, H - t);
	}

	{ matrix_push p;
		translate(W - r, r);
		draw_arc(SEGMENTS, -pi / 2.0f, pi / 2.0f, r - t, r);
	}

}

void graphics::opengl::drawE(Float W, Float H, Float t) {

	{ drawing d(quad_strip);
		d.vertex(W, 0.0f);
		d.vertex(W, t);
		d.vertex(0.0f, 0.0f);
		d.vertex(t, t);
		d.vertex(0.0f, H);
		d.vertex(t, H - t);
		d.vertex(W, H);
		d.vertex(W, H - t);
	}
	
	draw_rect(t / 2.0f, (H - t) / 2.0f, W, (H + t) / 2.0f);

}

void graphics::opengl::drawF(Float W, Float H, Float t) {

	{ drawing d(quad_strip);
		d.vertex(t, 0.0f);
		d.vertex(0.0f, 0.0f);
		d.vertex(t, H - t);
		d.vertex(0.0f, H);
		d.vertex(W, H - t);
		d.vertex(W, H);
	}
	
	draw_rect(t / 2.0f, (H - t) / 2.0f, W, (H + t) / 2.0f);

}

void graphics::opengl::drawG(Float W, Float H, Float t) {

	drawC(W, H, t);

	Float ry = H / 2.0f;
	Float y0 = ry * (1.0f - sin(pi / 4.0f));
	Float y1 = (H - t) / 2.0f, y2 = (H + t) / 2.0f;
	Float x0 = W / 2.0f, x1 = W - t;
	{ drawing d(quad_strip);
		d.vertex(x1, y0);
		d.vertex(W, y0);
		d.vertex(x1, y1);
		d.vertex(W, y2);
		d.vertex(x0, y1);
		d.vertex(x0, y2);
	}

}

void graphics::opengl::drawH(Float W, Float H, Float t) {
	draw_rect(0.0f, 0.0f, t, H);
	draw_rect(t / 2.0f, (H - t) / 2.0f, W - t / 2.0f, (H + t) / 2.0f);
	draw_rect(W - t, 0.0f, W, H);
}

void graphics::opengl::drawI(Float W, Float H, Float t) {
	draw_rect((W - t) / 2.0f, 0.0f, (W + t) / 2.0f, H);
}

void graphics::opengl::drawJ(Float W, Float H, Float t) {

	Float r = W / 2.0f;
	
	draw_rect(W - t, r, W, H);

	{ matrix_push p;
		translate(r, r);
		draw_arc(SEGMENTS, 0.0f, -pi, r - t, r);
	}

}

void graphics::opengl::drawK(Float W, Float H, Float t) {

	draw_rect(0.0f, 0.0f, t, H);
	
	{ matrix_push p;
		translate(W, 0.0f);
		rotate(90.0f);
		draw_carat(carat_hint<flat, sharp>(H, W - t, t));
	}

}

void graphics::opengl::drawL(Float W, Float H, Float t) {

	{ drawing d(quad_strip);
		d.vertex(0.0f, H);
		d.vertex(t, H);
		d.vertex(0.0f, 0.0f);
		d.vertex(t, t);
		d.vertex(W, 0.0f);
		d.vertex(W, t);
	}

}

void graphics::opengl::drawM(Float W, Float H, Float t) {

	draw_rect(0.0f, 0.0f, t, H);
	
	{ matrix_push p;
		translate(W - t, H);
		rotate(180.0f);
		draw_carat(carat_hint<sharp, sharp>(W - t - t, H, t));
	}

	
	draw_rect(W - t, 0.0f, W, H);

}

void graphics::opengl::drawN(Float W, Float H, Float t) {

	draw_rect(0.0f, 0.0f, t, H);
	
	{ matrix_push p;
		translate(t, H);
		scale(1.0f, -1.0f);
		draw_slant(slant_hint<vert, vert>(W - t - t, H, t));
	}
	
	draw_rect(W - t, 0.0f, W, H);

}

void graphics::opengl::drawO(Float W, Float H, Float t) {
	Float rx = W / 2.0f;
	Float ry = H / 2.0f;
	{ matrix_push p;
		translate(rx, ry);
		draw_ring(SEGMENTS, rx, ry, t);
	}
}

void graphics::opengl::drawP(Float W, Float H, Float t) {
	Float r = (H + t) / 4.0f;
	drawF(W - r, H, t);
	{ matrix_push p;
		translate(W - r, H - r);
		draw_arc(SEGMENTS, -pi / 2.0f, pi / 2.0f, r - t, r);
	}
}

void graphics::opengl::drawQ(Float W, Float H, Float t) {
	Float rx = W / 2.0f, ry = H / 2.0f;
	drawO(W, H, t);
	{ matrix_push p;
		translate(rx, ry);
		rotate(-90.0f);
		draw_slant(slant_hint<vert, vert>(ry, rx, t));
	}
}

void graphics::opengl::drawR(Float W, Float H, Float t) {
	Float r = (H + t) / 4.0f;
	slant_hint<vert_outside, vert> hint((H - t) / 2.0f, r, t);
	drawP(W, H, t);
	{ matrix_push p;
		translate(W - r, (H - t) / 2.0f);
		rotate(-90.0f);
		draw_slant(hint);
	}
}

void graphics::opengl::drawS(Float W, Float H, Float t) {
	Float rx = W / 2.0f;
	Float ry = (H + t) / 4.0f;
	{ matrix_push p;
		translate(rx, ry);
		draw_arc(30, pi, 2.5 * pi, rx, ry, t);
	}
	{ matrix_push p;
		translate(rx, H - ry, 0.0f);
		draw_arc(30, -pi / 2.0f, -2.0f * pi, rx, ry, t);
	}
}

void graphics::opengl::drawT(Float W, Float H, Float t) {
	draw_rect(0.0f, H - t, W, H);
	draw_rect((W - t) / 2.0f, 0.0f, (W + t) / 2.0f, H - t / 2.0f);
}

void graphics::opengl::drawU(Float W, Float H, Float t) {
	Float r = W / 2.0f;
	draw_rect(0.0f, r, t, H);
	draw_rect(W - t, r, W, H);
	{ matrix_push p;
		translate(r, r);
		draw_arc(SEGMENTS, 0.0f, -pi, r - t, r);
	}
}

void graphics::opengl::drawV(Float W, Float H, Float t) {
	{ matrix_push p;
		translate(0.0f, H);
		scale(1.0f, -1.0f);
		draw_carat(carat_hint<flat, flat>(W, H, t));
	}
}

void graphics::opengl::drawW(Float W, Float H, Float t) {

	Float C1 = sqr(t / (2.0f * H));
	Float C2 = W / 2.0f;
	Float a = 1.0f - C1;
	Float b = 2.0f * C1 * C2;
	Float c = -sqr(t) - C1 * sqr(C2);
	Float x1 = quadratic_formula<Float>(a, b, c).soln_plus();

	Float w = (W + x1) / 2.0f;
	drawV(w, H, t);
	{ matrix_push p;
		translate(W - w, 0.0f);
		drawV(w, H, t);
	}

}

void graphics::opengl::drawX(Float W, Float H, Float t) {
	{ matrix_push p;
		translate(0.0f, H);
		rotate(-90.0f);
		slant_hint<vert, vert> hint(H, W, t);
		draw_slant(hint);
		translate(H, 0.0f);
		scale(-1.0f, 1.0f);
		draw_slant(hint);
	}
}

void graphics::opengl::drawY(Float W, Float H, Float t) {
	Float H_half = H / 2.0f;
	draw_rect((W - t) / 2.0f, 0.0f, (W + t) / 2.0f, H_half);
	{ matrix_push p;
		translate(0.0f, H);
		scale(1.0f, -1.0f);
		draw_carat(carat_hint<flat, flat>(W, H_half, t));
	}
}

void graphics::opengl::drawZ(Float W, Float H, Float t) {
	{ matrix_push p;
		translate(0.0f, H);
		rotate(-90.0f);
		drawN(H, W, t);
	}
}

