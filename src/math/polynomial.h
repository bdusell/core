#ifndef MATH_POLYNOMIAL_H
#define MATH_POLYNOMIAL_H

namespace math {

template <typename T>
class quadratic_formula;

template <typename T>
class scalar_function;

template <typename T>
class linear_function;

template <typename T>
class quadratic_function;

template <typename T>
class quadratic_formula {

public:

	quadratic_formula(T a, T b, T c);
	T soln_plus() const;
	T soln_minus() const;

private:

	T _oppb;
	T _sqrt;
	T _2a;

};

template <typename T>
class scalar_function {

public:

	inline scalar_function();
	inline scalar_function(T c);
	inline T operator()(T x) const;
	inline T inv(T x) const;

	T c;

};

template <typename T>
class linear_function {

public:

	inline linear_function(T m, T b);
	inline T operator()(T x) const;

	T m, b;

};

template <typename T>
class quadratic_function {

public:

	inline quadratic_function(T a, T b, T c);
	inline T operator()(T x) const;

	T a, b, c;

};

template <typename T>
T quadratic_formula_plus(T a, T b, T c);

template <typename T>
T quadratic_formula_minus(T a, T b, T c);

template <typename T>
inline T linear(T m, T b, T x);

///* Implementations *///

template <typename T>
quadratic_formula<T>::quadratic_formula(T a, T b, T c) :
	_oppb(-b),
	_sqrt(sqrt(sqr(b) - 4 * a * c)),
	_2a(2 * a)
{}

template <typename T>
T quadratic_formula<T>::soln_plus() const {
	return (_oppb + _sqrt) / _2a;
}

template <typename T>	
T quadratic_formula<T>::soln_minus() const {
	return (_oppb - _sqrt) / _2a;
}

template <typename T>
scalar_function<T>::scalar_function() {}

template <typename T>
scalar_function<T>::scalar_function(T c) : c(c) {}

template <typename T>
T scalar_function<T>::operator()(T x) const {
	return c * x;
}

template <typename T>	
T scalar_function<T>::inv(T x) const {
	return x / c;
}

template <typename T>
linear_function<T>::linear_function(T m, T b) : m(m), b(b) {}

template <typename T>
T linear_function<T>::operator()(T x) const {
	return m * x + b;
}

template <typename T>
quadratic_function<T>::quadratic_function(T a, T b, T c) : a(a), b(b), c(c) {}

template <typename T>
T quadratic_function<T>::operator()(T x) const {
	return x * (x * a + b) + c;
}

template <typename T>
T quadratic_formula_plus(T a, T b, T c) {
	return (-b + sqrt(sqr(b) - 4 * a * c)) / (2 * a);
}

template <typename T>
T quadratic_formula_minus(T a, T b, T c) {
	return (-b - sqrt(sqr(b) - 4 * a * c)) / (2 * a);
}

template <typename T>
inline T linear(T m, T b, T x) {
	return m * x + b;
}

} // namespace math

#endif

