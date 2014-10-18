#ifndef _META_IS_POD_H_
#define _META_IS_POD_H_

#include "meta/is_primitive.h"
#include "meta/is_pointer.h"

namespace meta {

/* A meta-value which tells whether `T` is a plain-old data type (i.e. a
 * primitive type or a pointer type). */
template <typename T>
struct is_pod {
	static const bool value = is_primitive<T>::value || is_pointer<T>::value;
};

}

#endif
