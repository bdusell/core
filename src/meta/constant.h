#ifndef META_CONSTANT_H
#define META_CONSTANT_H

namespace meta {

template <typename T, T V>
struct constant {
	static const T value = V;
};

} // namespace meta

#endif

