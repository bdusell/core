#ifndef _MATH_RANDOM_H_
#define _MATH_RANDOM_H_

#include <cstdlib>
#include <ctime>

namespace math {

/* Seed the PRG with the current timestamp. */
inline void srand();

/* Generate a random real number in the range [`low`, `high`]. */
template <typename T>
T rand_real(T low, T high);

/* Generate a random integer in the range [`low`, `high`]. */
template <typename T>
T rand_int(T low, T high);

/* Generate a random integer in the range [0, `high`). */
template <typename T>
inline T rand_int_exclusive(T high);

/* Generate a random integer in the range [`low`, `high`). */
template <typename T>
T rand_int_exclusive(T low, T high);

/* Generate a random number in the range [`low`, `high`] (overloaded
 * appropriately for real vs. integral types). */
template <typename T>
inline T rand(T low, T high);

void srand() {
	::srand(::time(NULL));
}

template <typename T>
T rand_real(T low, T high) {
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
	return rand_real(low, high);
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

}

#endif
