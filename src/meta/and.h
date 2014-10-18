#ifndef _META_AND_H_
#define _META_AND_H_

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

/* Compute logical and of two boolean values (metafunction). */
template <bool A, bool B>
struct and_ : public false_ {};

template <>
struct and_<true, true> : public true_ {};

}

#endif
