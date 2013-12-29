#ifndef DATASTRUCT_ARRAY_TUPLE_H
#define DATASTRUCT_ARRAY_TUPLE_H

#include "meta/param.h"
#include "meta/ref.h"
#include "meta/cref.h"
#include "functional/operators.h"

namespace datastruct {

///* Types *///

template <typename T, unsigned int N>
class array_tuple;

template <typename T, unsigned int N>
class array_tuple {

public:

	inline array_tuple() {}

	inline array_tuple(
		typename meta::param<T>::type a1,
		typename meta::param<T>::type a2
	)
	{ set(a1, a2); }

	inline array_tuple(
		typename meta::param<T>::type a1,
		typename meta::param<T>::type a2,
		typename meta::param<T>::type a3
	)
	{ set(a1, a2, a3); }

	inline array_tuple(
		typename meta::param<T>::type a1,
		typename meta::param<T>::type a2,
		typename meta::param<T>::type a3,
		typename meta::param<T>::type a4
	)
	{ set(a1, a2, a3, a4); }

	template <typename U>
	inline array_tuple(typename meta::param<U>::type copy) { *this = copy; }

	template <typename U>
	inline array_tuple<T, N> &operator=(const U &copy) {
		return assign_op(copy, functional::assign());
	}

	template <typename U>
	inline bool operator==(const U &that) const {
		return all_op(that, functional::equals());
	}

	template <typename U>
	inline bool operator!=(const U &that) const {
		return any_op(that, functional::not_equals());
	}

	inline T *array() { return _array; }
	inline const T *array() const { return _array; }
	
	template <unsigned int I>
	inline typename meta::ref<T>::type get() { return get(I); }

	template <unsigned int I>
	inline typename meta::cref<T>::type get() const { return get(I); }
	
	inline typename meta::ref<T>::type get(unsigned int i) { return _array[i]; }
	inline typename meta::cref<T>::type get(unsigned int i) const { return _array[i]; }

	inline typename meta::ref<T>::type operator[](unsigned int i) { return get(i); }
	inline typename meta::cref<T>::type operator[](unsigned int i) const { return get(i); }

	template <typename U>
	inline void set(
		const U &a1,
		const U &a2
	)
	{ get<0>() = a1; get<1>() = a2; }

	template <typename U>
	inline void set(
		const U &a1,
		const U &a2,
		const U &a3
	)
	{ set(a1, a2); get<2>() = a3; }

	template <typename U>
	inline void set(
		const U &a1,
		const U &a2,
		const U &a3,
		const U &a4
	)
	{ set(a1, a2, a3); get<3>() = a4; }

protected:

	template <typename U, typename F>
	inline array_tuple<T, N> &assign_op(const U &that, const F &f) {
		for(unsigned int i = 0; i < N; ++i) f(get(i), that[i]);
		return *this;
	}

	template <typename Result, typename U, typename F>
	inline Result arithmetic_op(const U &that, const F &f) const {
		Result result;
		for(unsigned int i = 0; i < N; ++i) result[i] = f(get(i), that[i]);
		return result;
	}

	template <typename Result, typename C, typename F>
	inline Result scale_op(const C &c, const F &f) const {
		Result result;
		for(unsigned int i = 0; i < N; ++i) result[i] = f(get(i), c);
		return result;
	}

	template <typename U, typename F>
	inline bool all_op(const U &that, const F &f) const {
		for(unsigned int i = 0; i < N; ++i) if(!f(get(i), that[i])) return false;
		return true;
	}

	template <typename U, typename F>
	inline bool any_op(const U &that, const F &f) const {
		for(unsigned int i = 0; i < N; ++i) if(f(get(i), that[i])) return true;
		return false;
	}

private:

	T _array[N];

};

} // namespace datastruct

#endif

