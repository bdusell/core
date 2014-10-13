#ifndef _GRAPHICS_SHAPES_ALPHABET_H_
#define _GRAPHICS_SHAPES_ALPHABET_H_

#include "graphics/types.h"

namespace graphics {
namespace shapes {

/* Draw a string of characters with a certain width, height, and thickness for
each and a certain spacing between them. The lower left corner of the first
letter is drawn at the origin. */
void draw_string(const char *s, Float width, Float height, Float thickness,
	Float spacing);
Float draw_string_width(unsigned int length, Float width, Float spacing);

/* Draw a character with a certain width, height, and thickness, if supported.
The lower left corner of the letter is drawn at the origin. */
void draw_letter(char c, Float width, Float height, Float thickness);

/* Draw one of the capital Latin letters with a certain height, width, and
thickness. */
void drawA(Float W, Float H, Float t);
void drawB(Float W, Float H, Float t);
void drawC(Float W, Float H, Float t);
void drawD(Float W, Float H, Float t);
void drawE(Float W, Float H, Float t);
void drawF(Float W, Float H, Float t);
void drawG(Float W, Float H, Float t);
void drawH(Float W, Float H, Float t);
void drawI(Float W, Float H, Float t);
void drawJ(Float W, Float H, Float t);
void drawK(Float W, Float H, Float t);
void drawL(Float W, Float H, Float t);
void drawM(Float W, Float H, Float t);
void drawN(Float W, Float H, Float t);
void drawO(Float W, Float H, Float t);
void drawP(Float W, Float H, Float t);
void drawQ(Float W, Float H, Float t);
void drawR(Float W, Float H, Float t);
void drawS(Float W, Float H, Float t);
void drawT(Float W, Float H, Float t);
void drawU(Float W, Float H, Float t);
void drawV(Float W, Float H, Float t);
void drawW(Float W, Float H, Float t);
void drawX(Float W, Float H, Float t);
void drawY(Float W, Float H, Float t);
void drawZ(Float W, Float H, Float t);

} // namespace shapes
} // namespace graphics

#endif
