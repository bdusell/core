#ifndef META_OR_H
#define META_OR_H

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

template <bool A, bool B>
struct or_ : public true_ {};

template <>
struct or_<false, false> : public false_ {};

} // namespace meta

#endif

