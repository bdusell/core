#ifndef _META_IS_REAL_H_
#define _META_IS_REAL_H_

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

/* Test if T is a floating-point (real-valued) type (metafunction). */
template <typename T>
struct is_real : public false_ {};

#define _DEFINE_REAL( NAME ) \
template <> struct is_real<NAME> : public true_ {};

_DEFINE_REAL(float)
_DEFINE_REAL(double)
_DEFINE_REAL(long double)

#undef _DEFINE_REAL

template <typename T>
struct is_real<const T> : public is_real<T> {};

}

#endif
