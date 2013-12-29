/*
unittest.h
A simple unit testing framework for C++.
*/

#ifndef UNIT_TEST_UNIT_TEST_H
#define UNIT_TEST_UNIT_TEST_H

#include <iostream>
#include <cstring>
#include "ansi/color.h"

/* Macro functions which allow expressions' source code to be captured along
with their results. */
#define UNIT_TEST_TRUE( expr , name ) \
	test_true( #expr , expr , name , __FILE__ , __LINE__ )

#define UNIT_TEST_EQUAL( expr , expected , name ) \
	test_equal( #expr , expr , expected , name , __FILE__ , __LINE__ )

#define UNIT_TEST_PROGRAM( name ) \
int main(int argc, char **argv) { \
	name().run(__FILE__, argc, argv); \
}

#define UNIT_TEST( name ) \
class name ## _test : public unit_test { \
protected: \
	void run_tests(); \
}; \
UNIT_TEST_PROGRAM(name ## _test) \
void name ## _test::run_tests()

/* A base class for writing unit test classes. The protected run_tests function
should be overridden to perform a series of test cases conducted with the
helper functions and macros provided by this framework. */
class unit_test {

public:

	/* Public data members for setting the colors which are printed by the
	test. */
	ansi::color::color_code normal, success, failure;
	bool color_enabled;

	/* Default constructor. */
	unit_test() :
		normal(ansi::color::cyan),
		success(ansi::color::green),
		failure(ansi::color::red),
		color_enabled(true),
		_successes(0), _total(0) {}

	/* Run the unit test. The title of the unit test is passed as a
	parameter. */
	int run(const char *title, int argc, char **argv) {

		color_enabled = true;
		for(char **str = argv, **end = argv + argc; str != end; ++str) {
			if(strcmp(*str, "-n") == 0 || strcmp(*str, "--no-color") == 0) {
				color_enabled = false;
				break;
			}
		}

		_successes = _total = 0;
		make_color(normal);
		std::cout << "==== " << title << " ====";
		make_color(ansi::color::clear);
		std::cout << std::endl
			<< std::endl;

		run_tests();

		make_color(normal);
		std::cout << "==== TEST COMPLETE ====";
		make_color(ansi::color::clear);
		std::cout << std::endl
			<< std::endl
			<< "Total tests: " << _total << std::endl;
		if(failures()) make_color(failure);
		std::cout << "Failures:    " << failures();
		make_color(ansi::color::clear);
		std::cout << std::endl;
		if(successes()) make_color(success);
		std::cout << "Successes:   " << successes();
		make_color(ansi::color::clear);
		std::cout << std::endl
			<< std::endl;

		if(succeeded()) {
			make_color(success);
			std::cout << "SUCCESS";
		}
		else {
			make_color(failure);
			std::cout << "FAILURE";
		}

		make_color(ansi::color::clear);
		std::cout << std::endl
			<< std::endl;

		return !succeeded();

	}

	inline unsigned int successes() const {
		return _successes;
	}

	inline unsigned int failures() const {
		return _total - _successes;
	}

	inline unsigned int total() const {
		return _total;
	}

	inline bool succeeded() const {
		return _successes == _total;
	}

protected:

	virtual void run_tests() = 0;

	void test_true(
		const std::string &expr,
		bool actual,
		const std::string &name,
		const char *filename,
		unsigned int line
	)
	{
		begin_test(name);
		std::cout << expr << " is true" << std::endl;
		if(actual) pass();
		else fail(filename, line);
	}

	template <typename T>
	void test_equal(
		const std::string &expr,
		const T &actual,
		const T &expected,
		const std::string &name,
		const char *filename,
		unsigned int line
	)
	{
		begin_test(name);
		std::cout << expr << " == " << expected << std::endl;
		if(actual == expected) pass();
		else fail(filename, line);
	}

private:

	unsigned int _successes, _total;

	void begin_test(const std::string &name) {
		++_total;
		make_color(normal);
		std::cout << "== TEST #" << _total << ": " << name << " ==";
		make_color(ansi::color::clear);
		std::cout << std::endl;
	}

	void pass() {
		make_color(success);
		std::cout << "PASSED";
		make_color(ansi::color::clear);
		std::cout << std::endl
			<< std::endl;
		++_successes;
	}

	void fail(const char *filename, unsigned int line) const {
		make_color(failure);
		std::cout << "FAILED in " << filename << " at line " << line;
		make_color(ansi::color::clear);
		std::cout << std::endl
			<< std::endl;
	}

	template <typename T>
	inline void make_color(const T &c) const {
		if(color_enabled) std::cout << c;
	}

};

#endif

