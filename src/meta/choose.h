#ifndef _META_CHOOSE_H_
#define _META_CHOOSE_H_

namespace meta {

/* Choose the `I`th type in a list of types (metafunction). */
template <
	unsigned int I,
	typename T0 = void,
	typename T1 = void,
	typename T2 = void,
	typename T3 = void
>
struct choose;

#define _CHOICE(N) \
template < \
	typename T0, \
	typename T1, \
	typename T2, \
	typename T3 \
> \
struct choose<N, T0, T1, T2, T3> { \
	typedef T ## N type; \
};

_CHOICE(0)
_CHOICE(1)
_CHOICE(2)
_CHOICE(3)

#undef _CHOICE

}

#endif
