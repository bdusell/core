#ifndef _META_MINSIZE_H_
#define _META_MINSIZE_H_

#include "meta/if.h"

namespace meta {

/* A metafunction which produces `const T &` if `T` is larger than a reference
 * to itself, and otherwise `T`. */
template <typename T>
struct minsize;

template <typename T>
struct minsize {
	typedef typename
	meta::if_<
		(sizeof(T) > sizeof(T *)),
		const T &,
		T
	>::type
	type;
};

template <typename T>
struct minsize<T &> {
	typedef T &type;
};

}

#endif
