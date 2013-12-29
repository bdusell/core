#ifndef CONTROLLER_INFINITE_ANGLE_H
#define CONTROLLER_INFINITE_ANGLE_H

#include "math/util.h"
#include "meta/param.h"
#include "meta/ref.h"
#include "meta/cref.h"

namespace controller {

///* Types *///

/* A value which increments periodically over a fixed range so as to avoid
overflow. */
template <typename T>
class infinite_angle;

/* An angle in radians. The period of the angle is automatically set to 2pi. */
template <typename T>
class infinite_radian_angle;

/* An angle in degrees. The period of the angle is automatically set to 360
degrees. */
template <typename T>
class infinite_degree_angle;

template <typename T>
class infinite_angle {

public:

	/* Initialize the period of the angle. */
	inline infinite_angle(typename meta::param<T>::type period)
		: _period(period), _value(0) {}

	/* Initialize the period and phase offset of the angle. */
	inline infinite_angle(
		typename meta::param<T>::type period,
		typename meta::param<T>::type offset
	)
		: _period(period), _value(offset) {}

	/* Set the value. */
	inline infinite_angle<T> &operator=(typename meta::param<T>::type value) {
		_value = value;
		return *this;
	}

	/* Increment the value. Negative values are acceptable. */
	inline infinite_angle<T> &operator+=(typename meta::param<T>::type value) {
		_value = math::strict_mod(_value + value, _period);
		return *this;
	}

	/* Decrement the values. */
	inline infinite_angle<T> &operator-=(typename meta::param<T>::type value) {
		_value = math::strict_mod(_value - value, _period);
		return *this;
	}

	/* Cast the value to its numerical quantity. */
	inline operator typename meta::ref<T>::type() {
		return _value;
	}

	inline operator typename meta::cref<T>::type() const {
		return _value;
	}

private:

	T _period, _value;

};

template <typename T>
class infinite_radian_angle : public infinite_angle<T> {

public:

	inline infinite_radian_angle()
		: infinite_angle<T>(2.0 * math::pi) {}

	/* Offset is in radians. */
	inline infinite_radian_angle(typename meta::param<T>::type offset)
		: infinite_angle<T>(2.0 * math::pi, offset) {}

};

template <typename T>
class infinite_degree_angle : public infinite_angle<T> {

public:

	inline infinite_degree_angle()
		: infinite_angle<T>(360.0) {}

	/* Offset is in degrees. */
	inline infinite_degree_angle(typename meta::param<T>::type offset)
		: infinite_angle<T>(360.0, offset) {}

};

} // namespace controller

#endif

