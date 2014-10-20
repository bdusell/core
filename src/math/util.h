#ifndef _MATH_UTIL_H_
#define _MATH_UTIL_H_

#include <cstdlib>
#include <cmath>
#include "meta/is_real.h"

namespace math {

///* Constants *///

/* Pi. */
static const double pi = M_PI;

/* e (Euler's number). */
static const double e = M_E;

///* Functions *///

#define _WRAPPER( NAME ) \
using ::std::NAME;

/* Square function. */
template <typename T>
inline T sqr(const T &x) {
	return x * x;
}

/* Square root function. */
_WRAPPER(sqrt)

/* Exponential function (base-e) */
_WRAPPER(exp)

/* Exponential function (any base). */
_WRAPPER(pow)

/* Natural logarithm. */
_WRAPPER(log)

/* Logarithm base-10. */
_WRAPPER(log10)

/* Logarithm, any base. */
template <typename T, typename U>
inline T log(const T &base, const U &x) {
	return math::log(x) / math::log(base);
}

// I prefer thinking to typing.

#define _TYPE_PARAM_LIST_1 typename T
#define _TYPE_PARAM_LIST_2 _TYPE_PARAM_LIST_1, typename U

#define _TYPE_LIST_1 T
#define _TYPE_LIST_2 _TYPE_LIST_1, U

#define _ARG_LIST_1 x
#define _ARG_LIST_2 _ARG_LIST_1, y

#define _PARAM_LIST_1 const T &x
#define _PARAM_LIST_2 _PARAM_LIST_1, const U &y

#define _DEFINE_REAL_AND_INT(NAME, N, REAL, INT) \
namespace impl { \
template <_TYPE_PARAM_LIST_ ## N, bool is_real = meta::is_real<T>::value> \
struct NAME; \
template <_TYPE_PARAM_LIST_ ## N> \
struct NAME<_TYPE_LIST_ ## N, true> { \
	static T call(_PARAM_LIST_ ## N) { \
		return REAL; \
	} \
}; \
template <_TYPE_PARAM_LIST_ ## N> \
struct NAME<_TYPE_LIST_ ## N, false> { \
	static T call(_PARAM_LIST_ ## N) { \
		return INT; \
	} \
}; \
} \
template <_TYPE_PARAM_LIST_ ## N> \
T NAME(_PARAM_LIST_ ## N) { \
	return impl::NAME<_TYPE_LIST_ ## N>::call(_ARG_LIST_ ## N); \
}

/* Floor function. */
_DEFINE_REAL_AND_INT(floor, 1, ::floor(x), x)

/* Ceiling function. */
_DEFINE_REAL_AND_INT(ceil, 1, ::ceil(x), x)

/* Floor of quotient. */
_DEFINE_REAL_AND_INT(
	floor_div, 2,
	math::floor(x / y),
	x / y
)

/* Ceiling of quotient. */
_DEFINE_REAL_AND_INT(
	ceil_div, 2,
	math::ceil(x / y),
	math::floor_div(x - 1, y) + 1
)

/* Modulus function. */
_DEFINE_REAL_AND_INT(
	mod, 2,
	::fmod(x, y),
	x % y
)

/* Modulus function with the expected mathematical behavior, whose result is
always between 0 and b even when a or b is negative. */
template <typename T>
inline T strict_mod(const T &a, const T &b) {
	return math::mod(math::mod(a, b) + b, b);
}

/* Maximum function. */
template <typename T>
inline T max(const T &a, const T &b) {
	return a < b ? b : a;
}

/* Minimum function. */
template <typename T>
inline T min(const T &a, const T &b) {
	return a < b ? a : b;
}

/* Clamp function. */
template <typename T>
inline T clamp(const T &value, const T &low, const T &high) {
	return value < low ? low : value > high ? high : value;
}

/* Absolute value function. */
_WRAPPER(abs)

/* Floating point copmarison. */
template <typename T>
bool real_equal(
	const T &a, const T &b,
	const T &absolute_tolerance, const T &relative_tolerance
)
{
	return math::abs(a - b) <= math::max(
		absolute_tolerance,
		relative_tolerance * math::max(math::abs(a), math::abs(b))
	);
}

template <typename T>
bool real_equal(const T &a, const T &b, const T &tolerance = 0.001) {
	return math::abs(a - b) <=
		tolerance * math::max(T(1), math::max(math::abs(a), math::abs(b)));
}

#undef _WRAPPER
#undef _TYPE_PARAM_LIST_1
#undef _TYPE_PARAM_LIST_2
#undef _TYPE_LIST_1
#undef _TYPE_LIST_2
#undef _ARG_LIST_1
#undef _ARG_LIST_2
#undef _PARAM_LIST_1
#undef _PARAM_LIST_2
#undef _DEFINE_REAL_AND_INT

}

#endif
