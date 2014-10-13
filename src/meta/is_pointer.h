#ifndef META_IS_POINTER_H
#define META_IS_POINTER_H

namespace meta {

/* A meta-value which tells whether `T` is a pointer type. */
template <typename T>
struct is_pointer {
	static const bool value = false;
};

template <typename T>
struct is_pointer<T *> {
	static const bool value = true;
};

} // namespace meta

#endif

