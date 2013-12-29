#ifndef META_INT_H
#define META_INT_H

#include "meta/constant.h"

namespace meta {

template <int X>
struct int_ : public constant<int, X> {};

} // namespace meta

#endif

