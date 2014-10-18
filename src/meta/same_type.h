#ifndef _META_SAME_TYPE_H_
#define _META_SAME_TYPE_H_

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

/* Tell if two types are the same (metafunction). */
template <typename T, typename U>
struct same_type;

template <typename T, typename U>
struct same_type : false_ {};

template <typename T>
struct same_type<T, T> : true_ {};

}

#endif
