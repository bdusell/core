#ifndef META_IS_POD_H
#define META_IS_POD_H

#include "meta/is_primitive.h"
#include "meta/is_pointer.h"

namespace meta {

template <typename T>
struct is_pod {
	static const bool value = is_primitive<T>::value || is_pointer<T>::value;
};

} // namespace meta

#endif

