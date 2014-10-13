#ifndef CONTROLLER_SWITCHER_H
#define CONTROLLER_SWITCHER_H

#include "meta/param.h"
#include "meta/ref.h"
#include "meta/cref.h"

namespace controller {

/* A value which switches between two values based on a boolean switch. */
template <typename Bool, typename T>
class switcher {

public:

	inline switcher(
		typename meta::param<Bool>::type control,
		typename meta::param<T>::type    false_value,
		typename meta::param<T>::type    true_value
	)
		: _control(control)
		, _false_value(false_value)
		, _true_value(true_value)
	{}

	typename meta::ref<Bool>::type cond() {
		return _control;
	}

	typename meta::cref<Bool>::type cond() const {
		return _control;
	}

	operator typename meta::cref<T>::type() const {
		return _control ? _true_value : _false_value;
	}

private:

	Bool _control;
	T _false_value, _true_value;

};

} // namespace controller

#endif

