#ifndef _META_BOOL_H_
#define _META_BOOL_H_

#include "meta/constant.h"

namespace meta {

/* A boolean constant (metafunction). */
template <bool X>
struct bool_ : public constant<bool, X> {};

}

#endif
