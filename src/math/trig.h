#ifndef _MATH_TRIG_H_
#define _MATH_TRIG_H_

#include <cmath>

namespace math {

#define _WRAPPER( NAME ) \
using ::std::NAME;

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
 * signs to determine the correct quadrant of the result. It is an error to
 * call this with both arguments equal to 0. The result is in the interval
 * [-pi, pi]. */
template <typename T>
T atan(const T &a, const T &b) {
	return ::atan2(a, b);
}

#undef _WRAPPER

}

#endif
