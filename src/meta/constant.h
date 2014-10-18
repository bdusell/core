#ifndef _META_CONSTANT_H_
#define _META_CONSTANT_H_

namespace meta {

/* Returns a constant value of type `T` (metafunction). */
template <typename T, T V>
struct constant {
	static const T value = V;
};

}

#endif
