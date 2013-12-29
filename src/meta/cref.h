#ifndef META_CREF_H
#define META_CREF_H

#include "meta/minsize.h"
#include "meta/is_pod.h"
#include "meta/if.h"

namespace meta {

template <typename T>
struct cref;

namespace impl {
	template <typename T>
	struct _cref {
		typedef typename
		meta::if_<
			meta::is_pod<T>::value,
			typename meta::minsize<T>::type,
			const T &
		>::type
		type;
	};
}

/* Primitive, class, and pointer types, const and non-const. */
template <typename T>
struct cref {
	typedef typename impl::_cref<T>::type type;
};

/* Reference types, const and non-const. */
template <typename T>
struct cref<T &> {
	typedef const T &type;
};

/* Array types. */
template <typename T>
struct cref<T[]> {
	typedef const T type[];
};

/* Const types. */
template <typename T>
struct cref<const T> {
	typedef typename impl::_cref<T>::type type;
};

} // namespace meta

#endif

