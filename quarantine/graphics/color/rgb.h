#ifndef _GRAPHICS_COLOR_RGB_H_
#define _GRAPHICS_COLOR_RGB_H_

#include "meta/param.h"
#include "meta/ref.h"
#include "meta/cref.h"
#include "functional/operators.h"
#include "data/array_tuple.h"

namespace graphics {
namespace color {

///* Types *///

template <typename T, int N>
class rgb : public data::array_tuple<T, N> {

	typedef data::array_tuple<T, N> super;

public:

	inline rgb();
	inline rgb(
		typename meta::param<T>::type r,
		typename meta::param<T>::type g,
		typename meta::param<T>::type b);
	inline rgb(
		typename meta::param<T>::type r,
		typename meta::param<T>::type g,
		typename meta::param<T>::type b,
		typename meta::param<T>::type a);

	template <typename U>
	inline rgb<T, N> &operator=(const rgb<T, N> &that) {
		super::operator=(this, that);
		return *this;
	}

#define _DEFINE_MEMBER( NAME , INDEX ) \
	inline typename meta::ref<T>::type NAME () { \
		return this->template get< INDEX >(); \
	} \
	inline typename meta::cref<T>::type NAME () const { \
		return this->template get< INDEX >(); \
	}

	_DEFINE_MEMBER(r, 0)
	_DEFINE_MEMBER(g, 1)
	_DEFINE_MEMBER(b, 2)
	_DEFINE_MEMBER(a, 3)

#undef _DEFINE_MEMBER

	inline rgb<T, N> operator*(typename meta::param<T>::type c) const;

};

///* Implementations *///

template <typename T, int N>
rgb<T, N>::rgb() {
}

template <typename T, int N>
rgb<T, N>::rgb(
	typename meta::param<T>::type r,
	typename meta::param<T>::type g,
	typename meta::param<T>::type b
)
	: super(r, g, b)
{}

template <typename T, int N>
rgb<T, N>::rgb(
	typename meta::param<T>::type r,
	typename meta::param<T>::type g,
	typename meta::param<T>::type b,
	typename meta::param<T>::type a
)
	: super(r, g, b, a)
{}

template <typename T, int N>
rgb<T, N> rgb<T, N>::operator*(typename meta::param<T>::type c) const {
	return this->template scale_op< rgb<T, N> >(c, functional::operators::multiply());
}

} // namespace color
} // namespace graphics

#endif
