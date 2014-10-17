#ifndef _MATH_CARTESIAN_rectangle_H_
#define _MATH_CARTESIAN_rectangle_H_

#include "math/util.h"

namespace math {
namespace cartesian {

template <typename T>
class rectangle {

public:

	typedef point<T, 2> point_type;

	inline rectangle(T x1, T y1, T x2, T y2);
	inline rectangle(const point_type &p1, const point_type &p2);

	inline void set(T x1, T y1, T x2, T y2);

	template <typename U>
	inline void clamp(point<U, 2> &p) const;

	inline point_type center() const;
	inline T xrange() const;
	inline T yrange() const;

	point_type p1, p2;

};

template <typename T>
rectangle<T>::rectangle(T x1, T y1, T x2, T y2) : p1(x1, y1), p2(x2, y2) {}

template <typename T>
rectangle<T>::rectangle(const point_type &p1_, const point_type &p2_) : p1(p1_), p2(p2_) {}

template <typename T>
void rectangle<T>::set(T x1, T y1, T x2, T y2) {
	p1.set(x1, y1);
	p2.set(x2, y2);
}

template <typename T>	
typename rectangle<T>::point_type rectangle<T>::center() const {
	return p1 + (p2 - p1) / 2;
}

template <typename T>
template <typename U>
void rectangle<T>::clamp(point<U, 2> &p) const {
	p.set(
		math::clamp<T>(p.x(), p1.x(), p2.x()),
		math::clamp<T>(p.y(), p1.y(), p2.y())
	);
}

template <typename T>
T rectangle<T>::xrange() const {
	return p2.x() - p1.x();
}

template <typename T>
T rectangle<T>::yrange() const {
	return p2.y() - p1.y();
}

}
}

#endif
