#ifndef _GRAPHICS_COLOR_RGB_H_
#define _GRAPHICS_COLOR_RGB_H_

#include "meta/param.h"
#include "meta/ref.h"
#include "meta/cref.h"
#include "meta/array_tuple.h"

namespace graphics {
namespace color {

///* Types *///

template <typename T, int N>
class rgb : public meta::array_tuple<T, N> {

	typedef array_tuple<T, N> super;

public:

	inline rgb();
	inline rgb(meta::param<T>::type r, meta::param<T>::type g, meta::param<T>::type b);
	inline rgb(meta::param<T>::type r, meta::param<T>::type g, meta::param<T>::type b, meta::param<T>::type a);

	template <typename U>
	inline rgb<T, N> &operator=(const rgb<T, N> &that) {
		super::operator=(this, that);
		return *this;
	}

#define _DEFINE_MEMBER( NAME , INDEX ) \
	inline meta::ref<T>::type NAME () { return this->template get< INDEX >(); } \
	inline meta::cref<T>::type NAME () const { return this->template get< INDEX >(); }

	_DEFINE_MEMBER(r)
	_DEFINE_MEMBER(g)
	_DEFINE_MEMBER(b)
	_DEFINE_MEMBER(a)

#undef _DEFINE_MEMBER

	inline rgb<T, N> operator*(meta::param<T>::type c) const;

};

///* Implementations *///

template <typename T, int N>
rgb<T, N>::rgb() {
}

template <typename T, int N>
rgb<T, N>::rgb(
	meta::param<T>::type r,
	meta::param<T>::type g,
	meta::param<T>::type b
)
	: super(r, g, b)
{}

template <typename T, int N>
rgb<T, N>::rgb(
	meta::param<T>::type r,
	meta::param<T>::type g,
	meta::param<T>::type b,
	meta::param<T>::type a
)
	: super(r, g, b, a)
{}

template <typename T, int N>
rgb<T, N> rgb<T, N>::operator*(T c) const {
	return this->template scale_op< color<T, N> >(c, multiply());
}

} // namespace color
} // namespace graphics

#endif
