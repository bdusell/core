#ifndef META_IF_H
#define META_IF_H

namespace meta {

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

} // namespace meta

#endif

