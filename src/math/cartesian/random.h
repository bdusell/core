#ifndef GRAPHICS_SHAPES_RANDOM_H
#define GRAPHICS_SHAPES_RANDOM_H

#include "math/random.h"

namespace graphics {
namespace shapes {

template <typename T>
typename math::cartesian::rectangle<T>::point_type rand_coord(const math::cartesian::rectangle<T> &r);

template <typename T>
typename math::cartesian::rectangle<T>::point_type rand_coord(const math::cartesian::rectangle<T> &r) {
	return typename math::cartesian::rectangle<T>::point_type(
		math::rand(r.p1.x(), r.p2.x()),
		math::rand(r.p1.y(), r.p2.y())
	);
}

} // namespace shapes
} // namespace graphics

#endif

