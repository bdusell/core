#ifndef META_PARAM_H
#define META_PARAM_H

#include "meta/cref.h"

namespace meta {

template <typename T>
struct param;

template <typename T>
struct param : public cref<T> {};

template <typename T>
struct param<T &> {
	typedef T &type;
};

} // namespace meta

#endif

