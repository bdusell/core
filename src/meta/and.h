#ifndef META_AND_H
#define META_AND_H

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

template <bool A, bool B>
struct and_ : public false_ {};

template <>
struct and_<true, true> : public true_ {};

} // namespace meta

#endif

