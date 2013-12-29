#ifndef MATH_TRIG_H
#define MATH_TRIG_H

#include <cmath>

namespace math {

#define _WRAPPER( NAME ) \
template <typename T> \
T NAME (const T &x) { \
	return  :: NAME (x); \
}

/* Sine. */
_WRAPPER(sin)

/* Cosine. */
_WRAPPER(cos)

/* Tangent. */
_WRAPPER(tan)

/* Arc sine. */
_WRAPPER(asin)

/* Arc cosine. */
_WRAPPER(acos)

/* Arc tangent. */
_WRAPPER(atan)

/* Arc tangent, taking two arguments representing a fraction and using their
signs to determine the correct quadrant of the result. */
template <typename T>
T atan(const T &a, const T &b) {
	return ::atan2(a, b);
}

#undef _WRAPPER

#endif

