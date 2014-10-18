#ifndef _META_INT_H_
#define _META_INT_H_

#include "meta/constant.h"

namespace meta {

/* Integer constant (metafunction). */
template <int X>
struct int_ : public constant<int, X> {};

}

#endif
