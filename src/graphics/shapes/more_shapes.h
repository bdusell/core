/*
File: more_shapes.h
Author: Brian DuSell

More shape drawing utilities.
*/

#include "graphics/hw01/types.h"

namespace graphics {
namespace hw03 {

using namespace graphics::hw01;
//using namespace graphics::hw02;

/* Draws a grid in the xy plane using line primitives. Draws a certain number
of cells along each axis, where each cell is square and is one unit in side
length. The grid is not centered at the z axis but starts at the origin and
expands along the positive x and y axes. */
void draw_grid(uint x_cells, uint y_cells);

/* Draws a series of lines marching in the xy plane along the positive y axis,
spaced 1 unit apart. The number of spaces to draw and the width of the strip of
line segments are given. */
void draw_grid_lines(uint spaces, Float width);

} // namespace hw03
} // namespace graphics

