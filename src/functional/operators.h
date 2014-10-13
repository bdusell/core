#ifndef _FUNCTIONAL_OPERATORS_H_
#define _FUNCTIONAL_OPERATORS_H_

namespace functional {

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

/* Functors corresponding to the binary arithmetic operators `+`, `-`, `*`,
 * and `/`. */
_DEFINE_ARITHMETIC_OP(add, +)
_DEFINE_ARITHMETIC_OP(subtract, -)
_DEFINE_ARITHMETIC_OP(multiply, *)
_DEFINE_ARITHMETIC_OP(divide, /)

/* Functors corresponding to the assignment operators `=`, `+=`, `-=`, `*=`,
 * and `/=`. */
_DEFINE_ASSIGN_OP(assign, =)
_DEFINE_ASSIGN_OP(add_assign, +=)
_DEFINE_ASSIGN_OP(subtract_assign, -=)
_DEFINE_ASSIGN_OP(multiply_assign, *=)
_DEFINE_ASSIGN_OP(divide_assign, /=)

/* Functors corresponding to the binary comparison operators `==`, `!=`, `<`,
 * `<=`, `>`, and `>=`. */
_DEFINE_COMP_OP(equals, ==);
_DEFINE_COMP_OP(not_equals, !=);
_DEFINE_COMP_OP(less, <);
_DEFINE_COMP_OP(less_equals, <=);
_DEFINE_COMP_OP(greater, >);
_DEFINE_COMP_OP(greater_equals, >=);

#undef _DEFINE_ARITHMETIC_OP
#undef _DEFINE_ASSIGN_OP

} // namespace functional

#endif
