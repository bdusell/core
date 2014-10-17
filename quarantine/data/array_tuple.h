#ifndef _DATA_ARRAY_TUPLE_H_
#define _DATA_ARRAY_TUPLE_H_

#include "meta/param.h"
#include "meta/ref.h"
#include "meta/cref.h"
#include "functional/operators.h"

namespace data {

///* Types *///

template <typename T, unsigned int N>
class array_tuple;

/* An `N`-tuple of heterogeneously-typed elements implemented with an
 * underlying array. */
template <typename T, unsigned int N>
class array_tuple {

public:

	/* Create a tuple without initializing elements. */
	inline array_tuple() {}

	/* Create a tuple and initialize its first two elements. */
	inline array_tuple(
		typename meta::param<T>::type a1,
		typename meta::param<T>::type a2
	)
	{ set(a1, a2); }

	/* Create a tuple and initialize its first three elements. */
	inline array_tuple(
		typename meta::param<T>::type a1,
		typename meta::param<T>::type a2,
		typename meta::param<T>::type a3
	)
	{ set(a1, a2, a3); }

	/* Create a tuple and initialize its first four elements. */
	inline array_tuple(
		typename meta::param<T>::type a1,
		typename meta::param<T>::type a2,
		typename meta::param<T>::type a3,
		typename meta::param<T>::type a4
	)
	{ set(a1, a2, a3, a4); }

	/* Copy constructor. */
	template <typename U>
	inline array_tuple(typename meta::param<U>::type copy) { *this = copy; }

	/* Assignment operator. */
	template <typename U>
	inline array_tuple<T, N> &operator=(const U &copy) {
		return assign_op(copy, functional::operators::assign());
	}

	/* Equality operator. */
	template <typename U>
	inline bool operator==(const U &that) const {
		return all_op(that, functional::operators::equals());
	}

	/* Inequality operator. */
	template <typename U>
	inline bool operator!=(const U &that) const {
		return any_op(that, functional::operators::not_equals());
	}

	/* Access the underlying array. */
	inline T *array() { return _array; }
	inline const T *array() const { return _array; }

	/* Get the `I`th element, where `I` is some compile-time value. */
	template <unsigned int I>
	inline typename meta::ref<T>::type get() { return get(I); }

	template <unsigned int I>
	inline typename meta::cref<T>::type get() const { return get(I); }

	/* Get the `i`th element, where `i` can be a dynamic value. */
	inline typename meta::ref<T>::type get(unsigned int i) { return _array[i]; }
	inline typename meta::cref<T>::type get(unsigned int i) const { return _array[i]; }

	/* Subscript operator. Alias for `get(i)`. */
	inline typename meta::ref<T>::type operator[](unsigned int i) { return get(i); }
	inline typename meta::cref<T>::type operator[](unsigned int i) const { return get(i); }

	/* Set the first two elements of the tuple. */
	template <typename U>
	inline void set(
		const U &a1,
		const U &a2
	)
	{ get<0>() = a1; get<1>() = a2; }

	/* Set the first three elements of the tuple. */
	template <typename U>
	inline void set(
		const U &a1,
		const U &a2,
		const U &a3
	)
	{ set(a1, a2); get<2>() = a3; }

	/* Set the first four elements of the tuple. */
	template <typename U>
	inline void set(
		const U &a1,
		const U &a2,
		const U &a3,
		const U &a4
	)
	{ set(a1, a2, a3); get<3>() = a4; }

protected:

	/* Apply some binary, assignment-like function `f` element-wise from
	 * `that` to `*this`. Return `*this`. */
	template <typename U, typename F>
	inline array_tuple<T, N> &assign_op(const U &that, const F &f) {
		for(unsigned int i = 0; i < N; ++i) f(get(i), that[i]);
		return *this;
	}

	/* Apply some binary arithmetic function element-wise on `*this` and
	 * `that` and return the result in a tuple-like object of type `Result`.
	 * Return `*this`. */
	template <typename Result, typename U, typename F>
	inline Result arithmetic_op(const U &that, const F &f) const {
		Result result;
		for(unsigned int i = 0; i < N; ++i) result[i] = f(get(i), that[i]);
		return result;
	}

	/* Apply some unary function `f` on the elements of `*this` and return
	 * the result in a tuple-like object of type `Result`. */
	template <typename Result, typename C, typename F>
	inline Result scale_op(const C &c, const F &f) const {
		Result result;
		for(unsigned int i = 0; i < N; ++i) result[i] = f(get(i), c);
		return result;
	}

	/* Test whether some predicate function `f` holds true for all elements
	 * in `*this`. */
	template <typename U, typename F>
	inline bool all_op(const U &that, const F &f) const {
		for(unsigned int i = 0; i < N; ++i) if(!f(get(i), that[i])) return false;
		return true;
	}

	/* Test whether some predicate function `f` holds true for any elements
	 * in `*this`. */
	template <typename U, typename F>
	inline bool any_op(const U &that, const F &f) const {
		for(unsigned int i = 0; i < N; ++i) if(f(get(i), that[i])) return true;
		return false;
	}

private:

	T _array[N];

};

} // namespace data

#endif

