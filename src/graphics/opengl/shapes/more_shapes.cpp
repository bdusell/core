#include "more_shapes.h"
#include "graphics/opengl/drawing.h"
#include "graphics/opengl/transform.h"

void graphics::hw03::draw_grid(uint x_cells, uint y_cells) {
	draw_grid_lines(y_cells, x_cells);
	{ matrix_push _;
		rotate<Float>(-90);
		scale<Float>(-1, 1);
		draw_grid_lines(x_cells, y_cells);
	}
}

void graphics::hw03::draw_grid_lines(uint spaces, Float width) {
	{ drawing d(lines);
		for(uint i = 0; i <= spaces; ++i) {
			Float y = i;
			d.vertex<Float>(0, y);
			d.vertex<Float>(width, y);
		}
	}
}

