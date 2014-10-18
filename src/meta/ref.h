#ifndef _META_REF_H_
#define _META_REF_H_

#include "meta/if.h"

namespace meta {

/* Map any type to a reference type (metafunction). */
template <typename T>
struct ref {
	typedef T &type;
};

template <typename T>
struct ref<T &> {
	typedef T &type;
};

}

#endif
