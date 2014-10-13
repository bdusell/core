#ifndef _DATA_TUPLE_H_
#define _DATA_TUPLE_H_

#include "meta/param.h"
#include "meta/ref.h"
#include "meta/cref.h"
#include "meta/int.h"
#include "meta/choose.h"

namespace data {

/* A tuple with elements of heterogeneous type. */
template <typename T0, typename T1, typename T2 = void, typename T3 = void>
class tuple;

template <typename T0, typename T1>
class tuple<T0, T1, void, void> {

public:

	/* Default constructor. */
	inline tuple() {}

	/* Member-wise constructor. */
	inline tuple(
		typename meta::param<T0>::type t0,
		typename meta::param<T1>::type t1
	) : _0(t0), _1(t1) {}

	/* Copy constructor. */

	template <typename U>
	inline tuple(U &copy) : _0(copy.get<0>()), _1(copy.get<1>()) {}

	template <typename U>
	inline tuple(const U &copy) : _0(copy.get<0>()), _1(copy.get<1>()) {}

	/* Member accessor. */
	template <unsigned int I>
	typename meta::ref<typename meta::choose<I, T0, T1>::type>::type get() {
		return get_impl(meta::int_<I>());
	}

	template <unsigned int I>
	typename meta::cref<typename meta::choose<I, T0, T1>::type>::type get() const {
		return get_impl(meta::int_<I>());
	}

	/* Member-wise setter. */
	inline void set(
		typename meta::param<T0>::type t0,
		typename meta::param<T1>::type t1
	) { get<0>() = t0; get<1>() = t1; }

private:

	typename meta::ref<T0>::type get_impl(meta::int_<0> _) { return _0; }
	typename meta::ref<T1>::type get_impl(meta::int_<1> _) { return _1; }

	typename meta::cref<T0>::type get_impl(meta::int_<0> _) const { return _0; }
	typename meta::cref<T1>::type get_impl(meta::int_<1> _) const { return _1; }

	T0 _0;
	T1 _1;

};

template <typename T0, typename T1, typename T2>
class tuple<T0, T1, T2, void> {

public:

	inline tuple() {}

	inline tuple(
		typename meta::param<T0>::type t0,
		typename meta::param<T1>::type t1,
		typename meta::param<T2>::type t2
	) : _0(t0), _1(t1), _2(t2) {}

	template <typename U>
	inline tuple(U &copy) : _0(copy.get<0>()), _1(copy.get<1>()), _2(copy.get<2>()) {}

	template <unsigned int I>
	typename meta::ref<typename meta::choose<I, T0, T1, T2>::type>::type get() {
		return get_impl(meta::int_<I>());
	}

	template <unsigned int I>
	typename meta::cref<typename meta::choose<I, T0, T1, T2,>::type>::type get() const {
		return get_impl(meta::int_<I>());
	}

	inline void set(
		typename meta::param<T0>::type t0,
		typename meta::param<T1>::type t1,
		typename meta::param<T2>::type t2
	) { get<0>() = t0; get<1>() = t1; get<2>() = t2; }

private:

	typename meta::ref<T0>::type get_impl(meta::int_<0> _) { return _0; }
	typename meta::ref<T1>::type get_impl(meta::int_<1> _) { return _1; }
	typename meta::ref<T2>::type get_impl(meta::int_<2> _) { return _2; }

	typename meta::cref<T0>::type get_impl(meta::int_<0> _) const { return _0; }
	typename meta::cref<T1>::type get_impl(meta::int_<1> _) const { return _1; }
	typename meta::cref<T2>::type get_impl(meta::int_<2> _) const { return _2; }

	T0 _0;
	T1 _1;
	T2 _2;

};

/*
template <typename T0, typename T1, typename T2>
class tuple<T0, T1, T2, void> {

public:

	inline tuple() {}

	inline tuple(
		typename meta::param<T0>::type t0,
		typename meta::param<T1>::type t1,
		typename meta::param<T2>::type t2
	) : _0(t0), _1(t1), _2(t2) {}

	template <typename U>
	inline tuple(const U &copy)
		: _0(copy.get<0>()), _1(copy.get<1>()), _2(copy.get<2>()) {}

	template <unsigned int I>
	typename meta::ref<typename meta::choose<I, T0, T1, T2>::type get() {
		return get_impl(meta::int_<I>());
	}

private:

	typename meta::ref<T0>::type get_impl(meta::int_<0> _) { return _0; }
	typename meta::ref<T1>::type get_impl(meta::int_<1> _) { return _1; }
	typename meta::ref<T2>::type get_impl(meta::int_<2> _) { return _2; }

	T0 _0;
	T1 _1;
	T2 _2;

};
*/
/*
template <typename T1, typename T2, typename T3>
class tuple<T1, T2, T3, void> {

public:

	inline tuple() {}
	inline tuple(
		typename meta::param<T1>::type t1,
		typename meta::param<T2>::type t2,
		typename meta::param<T3>::type t3
	) : _1(t1), _2(t2), _3(t3) {}
	template <typename U> inline tuple(const U &copy) :
		_1(copy.get<0>()), _2(copy.get<1>()), _3(copy.get<2>()) {}

	_ACCESSOR_PROTO

	inline void set(
		typename meta::param<T1>::type t1,
		typename meta::param<T2>::type t2,
		typename meta::param<T3>::type t3
	) { get<0>() = t1; get<1>() = t2; get<2>() = t3; }

private:

	T1 _1;
	T2 _2;
	T3 _3;

};

template <typename T1, typename T2, typename T3, typename T4>
class tuple {

public:

	inline tuple() {}
	inline tuple(
		typename meta::param<T1>::type t1,
		typename meta::param<T2>::type t2,
		typename meta::param<T3>::type t3,
		typename meta::param<T4>::type t4
	) : _1(t1), _2(t2), _3(t3), _4(t4) {}
	template <typename U> inline tuple(const U &copy)
		: _1(copy.get<0>())
		, _2(copy.get<1>())
		, _3(copy.get<2>())
		, _4(copy.get<3>())
	{}

	_ACCESSOR_PROTO

	inline void set(
		typename meta::param<T1>::type t1,
		typename meta::param<T2>::type t2,
		typename meta::param<T3>::type t3,
		typename meta::param<T4>::type t4
	) { get<0>() = t1; get<1>() = t2; get<2>() = t3; get<3>() = t4; }

private:

	T1 _1;
	T2 _2;
	T3 _3;
	T4 _4;

};
*/

} // namespace data

#endif
