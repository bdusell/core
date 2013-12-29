#ifndef MATH_CARTESIAN_VECTOR_H
#define MATH_CARTESIAN_VECTOR_H

#include "math/cartesian/tuple.h"

namespace math {
namespace cartesian {

template <typename T, int N>
class vector;

template <typename T, int N>
class point;

/* An N-dimensional vector. */
template <typename T, int N>
class vector : public math::cartesian::tuple<T, N> {

	typedef math::cartesian::tuple<T, N> super;

public:

	inline vector() {}
	inline vector(T x, T y) : super(x, y) {}
	inline vector(T x, T y, T z) : super(x, y, z) {}
	inline vector(T x, T y, T z, T w) : super(x, y, z, w) {}

	template <typename U>
	inline vector<T, N> &operator=(const vector<U, N> &that) {
		super::operator=(this, that);
		return *this;
	}

	/* Vector addition. */
	template <typename U>
	inline vector<T, N> operator+(const vector<U, N> &v) const {
		return this->template arithmetic_op< vector<T, N> >(v, add());
	}

	template <typename U>
	inline point<T, N> operator+(const point<U, N> &p) const {
		return this->template arithmetic_op< point<T, N> >(p, add());
	}
	
	/* Vector subtraction. */
	template <typename U>
	inline vector<T, N> operator-(const vector<U, N> &v) const {
		return this->template arithmetic_op< vector<T, N> >(v, subtract());
	}
	
	/* Vector scaling. */
	template <typename U>
	inline vector<T, N> operator*(U c) const {
		return this->template scale_op< vector<T, N> >(c, multiply());
	}
	
	template <typename U>
	inline vector<T, N> operator/(U c) const {
		return this->template scale_op< vector<T, N> >(c, divide());
	}

};

} // namespace cartesian
} // namespace math

#endif

