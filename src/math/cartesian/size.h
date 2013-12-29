#ifndef MATH_CARTESIAN_SIZE_H
#define MATH_CARTESIAN_SIZE_H

#include "meta/array_tuple.h"

namespace math {
namespace cartesian {

template <typename T, int N>
class size;

/* A two-dimensional size. */
template <typename T, int N, typename Tuple = meta::array_tuple<T, N> >
class size : public Tuple {

	typedef Tuple super;

public:

	inline size() {}

	/* Initialize with a width and height. */
	inline size(T width, T height) : super(width, height) {}
	
	inline T &width() { return this->template get<0>(); }
	inline T &height() { return this->template get<1>(); }
	
	inline T width() const { return this->template get<0>(); }
	inline T height() const { return this->template get<1>(); }

	template <typename U>
	inline size<T, N> operator=(const size<U, N> &that) {
		super::operator=(this, that);
		return *this;
	}

};

} // namespace cartesian
} // namespace math

#endif

