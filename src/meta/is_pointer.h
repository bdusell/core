#ifndef _META_IS_POINTER_H_
#define _META_IS_POINTER_H_

namespace meta {

/* A metafunction which tells whether `T` is a pointer type. */
template <typename T>
struct is_pointer {
	static const bool value = false;
};

template <typename T>
struct is_pointer<T *> {
	static const bool value = true;
};

}

#endif
