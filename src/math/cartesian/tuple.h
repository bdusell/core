/*
File: cartesian.h
Author: Brian DuSell

An extension of the array tuple type adapted for use in a traditional
Cartesian xyz coordinate system.
*/

#ifndef MATH_CARTESIAN_TUPLE_H
#define MATH_CARTESIAN_TUPLE_H

#include "meta/array_tuple.h"

namespace math {
namespace cartesian {

template <typename T, int N>
class cartesian_tuple;

template <typename T, int N>
class cartesian_tuple : public meta::array_tuple<T, N> {

	typedef array_tuple<T, N> super;

public:

	inline cartesian_tuple() {}
	inline cartesian_tuple(T x, T y) : super(x, y) {}
	inline cartesian_tuple(T x, T y, T z) : super(x, y, z) {}
	inline cartesian_tuple(T x, T y, T z, T w) : super(x, y, z, w) {}

	inline T &x() { return this->template get<0>(); }
	inline T &y() { return this->template get<1>(); }
	inline T &z() { return this->template get<2>(); }
	inline T &w() { return this->template get<3>(); }

	inline T x() const { return this->template get<0>(); }
	inline T y() const { return this->template get<1>(); }
	inline T z() const { return this->template get<2>(); }
	inline T w() const { return this->template get<3>(); }

	template <typename U>
	inline cartesian_tuple<T, N> &operator=(const cartesian_tuple<U, N> &that) {
		super::operator=(this, that);
		return *this;
	}

};

} // namespace cartesian
} // namespace math

#endif

