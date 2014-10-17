#ifndef MATH_SPHERICAL_POINT_H
#define MATH_SPHERICAL_POINT_H

#include <cmath>
#include "meta/array_tuple.h"

namespace math {
namespace spherical {

template <typename T>
class vector;

/*
A spherical coordinate.

According to the convention used here, the xz plane is horizontal, and the y
axis is vertical. r is the distance from the origin. theta is an angle in
radians in the horizontal plane, starting at the positive z axis and passing
through the positive x-axis at 90 degrees. phi is a vertical angle in radians
and starts at the positive y axis, passing through the xz plane at 90 degrees.

x = r sin(theta) sin(phi)
y = r cos(phi)
z = r cos(theta) sin(phi)
*/
template <typename T>
class vector : public meta::array_tuple<T, 3> {

	typedef meta::array_tuple<T, 3> super;

public:

	inline vector() {}
	inline vector(T r, T theta, T phi) :
		super(r, theta, phi) {}

	template <typename U> vector(const U &copy) : super(copy) {}

	inline T &r() { return this->template get<0>(); }
	inline T &theta() { return this->template get<1>(); }
	inline T &phi() { return this->template get<2>(); }

	inline T r() const { return this->template get<0>(); }
	inline T theta() const { return this->template get<1>(); }
	inline T phi() const { return this->template get<2>(); }

	template <typename U>
	U to_cartesian() const {
		T rsinphi = r() * sin(phi());
		return U(
			rsinphi * sin(theta()),
			r() * cos(phi()),
			rsinphi * cos(theta())
		);
	}

};

} // namespace spherical
} // namespace math

#endif

