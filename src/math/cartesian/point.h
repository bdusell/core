#ifndef MATH_CARTESIAN_POINT_H
#define MATH_CARTESIAN_POINT_H

#include "math/cartesian/tuple.h"

namespace graphics {
namespace cartesian {

template <typename T, int N>
class point;

template <typename T, int N>
class vector;

/* An N-dimensional point. */
template <typename T, int N>
class point : public math::cartesian::tuple<T, N> {

	typedef math::cartesian::tuple<T, N> super;

public:

	/* Default constructor. */
	inline point() {}
	inline point(T x, T y) : super(x, y) {}
	inline point(T x, T y, T z) : super(x, y, z) {}
	inline point(T x, T y, T z, T w) : super(x, y, z, w) {}

	template <typename U>
	inline point<T, N> &operator=(const point<U, N> &that) {
		super::operator=(this, that);
		return *this;
	}

	/* Vector addition. */
	template <typename U>
	inline point<T, N> operator+(const vector<U, N> &v) const {
		return this->template arithmetic_op< point<T, N> >(v, add());
	}

	/* Point subtraction. */
	template <typename U>
	inline vector<T, N> operator-(const point<U, N> &p) const {
		return this->template arithmetic_op< vector<T, N> >(p, subtract());
	}

};

} // namespace cartesian
} // namespace graphics

#endif

