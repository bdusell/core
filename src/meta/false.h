#ifndef _META_FALSE_H_
#define _META_FALSE_H_

#include "meta/bool.h"

namespace meta {

/* False constant (metafunction). */
struct false_ : public bool_<false> {};

}

#endif
