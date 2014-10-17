#ifndef _GAME_CONTROLLER_CLAMPED_H_
#ifndef _GAME_CONTROLLER_CLAMPED_H_

#include "math/util.h"
#include "meta/param.h"
#include "meta/cref.h"
#include "meta/ref.h"

namespace game {
namespace controller {

/* A value which remains clamped to a given range. */
template <typename T>
class clamped {

public:

	clamped(
		typename meta::param<T>::type value,
		typename meta::param<T>::type min,
		typename meta::param<T>::type max
	)
		: _value(value)
		, _min(min)
		, _max(max)
	{
		clamp();
	}

#define _OVERLOAD( OP ) \
	template <typename U> \
	inline clamped<T> &operator OP (const U &value) { \
		_value OP value; \
		clamp(); \
		return *this; \
	}

	_OVERLOAD(=)
	_OVERLOAD(+=)
	_OVERLOAD(-=)

#undef _OVERLOAD

	operator typename meta::ref<T>::type() {
		return _value;
	}

	operator typename meta::cref<T>::type() const {
		return _value;
	}

private:

	T _value, _min, _max;

	inline void clamp() {
		_value = math::clamp(_value, _min, _max);
	}

};

} // namespace controller
} // namespace game

#endif
