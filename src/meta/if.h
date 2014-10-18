#ifndef _META_IF_H_
#define _META_IF_H_

namespace meta {

/* A metafunction which produces `A` if `Cond` is true and `B` otherwise. */
template <bool Cond, typename A, typename B>
struct if_;

template <typename A, typename B>
struct if_<true, A, B> {
	typedef A type;
};

template <typename A, typename B>
struct if_<false, A, B> {
	typedef B type;
};

}

#endif
