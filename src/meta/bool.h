#ifndef META_BOOL_H
#define META_BOOL_H

#include "meta/constant.h"

namespace meta {

template <bool X>
struct bool_ : public constant<bool, X> {};

} // namespace meta

#endif

