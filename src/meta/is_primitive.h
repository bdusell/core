#ifndef META_IS_PRIMITIVE_H
#define META_IS_PRIMITIVE_H

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

/* is_primitive<T>
Test if T is a primitive C++ type. */
template <typename T>
struct is_primitive : public false_ {};

#define _DEFINE_PRIMITIVE( NAME ) \
template <> struct is_primitive< NAME > : public true_ {};

_DEFINE_PRIMITIVE(char)
_DEFINE_PRIMITIVE(signed char)
_DEFINE_PRIMITIVE(short int)
_DEFINE_PRIMITIVE(int)
_DEFINE_PRIMITIVE(long int)
_DEFINE_PRIMITIVE(unsigned char)
_DEFINE_PRIMITIVE(unsigned short int)
_DEFINE_PRIMITIVE(unsigned int)
_DEFINE_PRIMITIVE(unsigned long int)
_DEFINE_PRIMITIVE(wchar_t)
_DEFINE_PRIMITIVE(bool)
_DEFINE_PRIMITIVE(float)
_DEFINE_PRIMITIVE(double)
_DEFINE_PRIMITIVE(long double)

#undef _DEFINE_PRIMITIVE

} // namespace meta

#endif

