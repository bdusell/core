#ifndef _FUNCTIONAL_OPERATORS_H_
#define _FUNCTIONAL_OPERATORS_H_

namespace functional {
namespace operators {

#define _DEFINE_ARITHMETIC_OP( NAME , OP ) \
struct NAME { \
	template <typename T, typename U> \
	inline T operator()(const T &a, const U &b) const { \
		return a OP b; \
	} \
};

#define _DEFINE_ASSIGN_OP( NAME , OP ) \
struct NAME { \
	template <typename A, typename B> \
	inline A &operator()(A &a, const B &b) const { \
		return a OP b; \
	} \
};

#define _DEFINE_COMP_OP( NAME , OP ) \
struct NAME { \
	template <typename A, typename B> \
	inline bool operator()(const A &a, const B &b) const { \
		return a OP b; \
	} \
};

/* Functor for operator `+`. */
_DEFINE_ARITHMETIC_OP(add, +)

/* Functor for operator `-`. */
_DEFINE_ARITHMETIC_OP(subtract, -)

/* Functor for operator `*`. */
_DEFINE_ARITHMETIC_OP(multiply, *)

/* Functor for operator `/`. */
_DEFINE_ARITHMETIC_OP(divide, /)

/* Functor for operator `=`. */
_DEFINE_ASSIGN_OP(assign, =)

/* Functor for operator `+=`. */
_DEFINE_ASSIGN_OP(add_assign, +=)

/* Functor for operator `-=`. */
_DEFINE_ASSIGN_OP(subtract_assign, -=)

/* Functor for operator `*=`. */
_DEFINE_ASSIGN_OP(multiply_assign, *=)

/* Functor for operator `/=`. */
_DEFINE_ASSIGN_OP(divide_assign, /=)

/* Functor for operator `==`. */
_DEFINE_COMP_OP(equals, ==);

/* Functor for operator `!=`. */
_DEFINE_COMP_OP(not_equals, !=);

/* Functor for operator `<`. */
_DEFINE_COMP_OP(less, <);

/* Functor for operator `<=`. */
_DEFINE_COMP_OP(less_equals, <=);

/* Functor for operator `>`. */
_DEFINE_COMP_OP(greater, >);

/* Functor for operator `>=`. */
_DEFINE_COMP_OP(greater_equals, >=);

#undef _DEFINE_ARITHMETIC_OP
#undef _DEFINE_ASSIGN_OP

}
}

#endif
