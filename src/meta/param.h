#ifndef _META_PARAM_H_
#define _META_PARAM_H_

#include "meta/cref.h"

namespace meta {

/* A metafunction which produces a type appropriate for being used as an
 * immutable function parameter. This is generally the same as `cref<T>`
 * except that non-const references are left non-const. */
template <typename T>
struct param;

template <typename T>
struct param : public cref<T> {};

template <typename T>
struct param<T &> {
	typedef T &type;
};

}

#endif
