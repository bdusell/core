/*
File: random.h
Author: Brian DuSell

Random value generation utilities.
*/

#ifndef MATH_RANDOM_H
#define MATH_RANDOM_H

#include <cstdlib>
#include <ctime>

namespace math {

///* Functions *///

inline void srand();

template <typename T>
T rand_float(T low, T high);

template <typename T>
T rand_int(T low, T high);

template <typename T>
inline T rand_int_exclusive(T high);

template <typename T>
T rand_int_exclusive(T low, T high);

template <typename T>
inline T rand(T low, T high);

///* Implementations *///

void srand() {
	::srand(time(NULL));
}

template <typename T>
T rand_float(T low, T high) {
	return (T(::rand()) / T(RAND_MAX)) * (high - low) + low;
}

template <typename T>
T rand_int(T low, T high) {
	return ::rand() % (high - low + 1) + low;
}

template <typename T>
T rand_int_exclusive(T high) {
	return ::rand() % high;
}

template <typename T>
T rand_int_exclusive(T low, T high) {
	return ::rand() % (high - low) + low;
}

template <typename T>
inline T rand(T low, T high) {
	return rand_float(low, high);
}

template <>
inline char rand<char>(char low, char high) {
	return rand_int(low, high);
}

template <>
inline short rand<short>(short low, short high) {
	return rand_int(low, high);
}

template <>
inline int rand<int>(int low, int high) {
	return rand_int(low, high);
}

template <>
inline long rand<long>(long low, long high) {
	return rand_int(low, high);
}

} // namespace math

#endif

