#ifndef META_MINSIZE_H
#define META_MINSIZE_H

#include "meta/if.h"

namespace meta {

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

} // namespace meta

#endif

