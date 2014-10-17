#ifndef _MATH_tuple_H_
#define _MATH_tuple_H_

#include "data/array_tuple.h"

namespace math {
namespace cartesian {

template <typename T, int N>
class tuple;

template <typename T, int N>
class tuple : public data::array_tuple<T, N> {

	typedef data::array_tuple<T, N> super;

public:

	inline tuple() {}
	inline tuple(T x, T y) : super(x, y) {}
	inline tuple(T x, T y, T z) : super(x, y, z) {}
	inline tuple(T x, T y, T z, T w) : super(x, y, z, w) {}

	inline T &x() { return this->template get<0>(); }
	inline T &y() { return this->template get<1>(); }
	inline T &z() { return this->template get<2>(); }
	inline T &w() { return this->template get<3>(); }

	inline T x() const { return this->template get<0>(); }
	inline T y() const { return this->template get<1>(); }
	inline T z() const { return this->template get<2>(); }
	inline T w() const { return this->template get<3>(); }

	template <typename U>
	inline tuple<T, N> &operator=(const tuple<U, N> &that) {
		super::operator=(this, that);
		return *this;
	}

};

} // namespace cartesian
} // namespace math

#endif
