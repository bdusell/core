#ifndef META_SAME_TYPE_H
#define META_SAME_TYPE_H

#include "meta/true.h"
#include "meta/false.h"

namespace meta {

template <typename T, typename U>
struct same_type;

template <typename T, typename U>
struct same_type : false_ {};

template <typename T>
struct same_type<T, T> : true_ {};

} // namespace meta

#endif

