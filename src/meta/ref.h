#ifndef META_REF_H
#define META_REF_H

#include "meta/if.h"

namespace meta {

template <typename T>
struct ref {
	typedef T &type;
};

template <typename T>
struct ref<T &> {
	typedef T &type;
};

} // namespace meta

#endif

