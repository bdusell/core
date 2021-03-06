#ifndef _META_OR_H_
#define _META_OR_H_

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

/* Logical or metafunction. */
template <bool A, bool B>
struct or_ : public true_ {};

template <>
struct or_<false, false> : public false_ {};

}

#endif
