#ifndef _UNIT_TEST_H_
#define _UNIT_TEST_H_

#include <iostream>
#include <cstring>
#include <vector>
#include "terminal/color.h"

/* Assert that an expression is true. */
#define UNIT_TEST_TRUE( expr , name ) \
	test_true( #expr , expr , name , __FILE__ , __LINE__ )

/* Assert that an expression if false. */
#define UNIT_TEST_FALSE( expr , name ) \
	test_false( #expr, expr, name , __FILE__ , __LINE__ )

/* Assert that two expressions are equal according to `==`. */
#define UNIT_TEST_EQUAL( expr , expected , name ) \
	test_equal( #expr , expr , expected , name , __FILE__ , __LINE__ )

/* Assert that a namespace contains a certain constant. */
#define UNIT_TEST_HAS_CONSTANT( namesp , member , name ) \
	{ (void) namesp::member; } \
	test_has_constant(#namesp "::" #member, name )

/* Run an assertion which always passes. This indicates successful
 * compilation. */
#define UNIT_TEST_COMPILES( name ) \
	test_compiles( name )

#define UNIT_TEST_PROGRAM( name ) \
int main(int argc, char **argv) { \
	return name().run(__FILE__, argc, argv); \
}

/* Shorthand for defining a unit test program. Simply define the unit test body
 * in a code block following this macro, and it will define the unit test class
 * and main function for you. */
#define UNIT_TEST( name ) \
class name ## _test : public unit_test { \
protected: \
	void run_tests(); \
}; \
UNIT_TEST_PROGRAM(name ## _test) \
void name ## _test::run_tests()

/* A base class for writing unit test classes. The protected `run_tests`
 * function should be overridden to perform a series of assertions made
 * with the helper functions and macros provided. */
class unit_test {

public:

	/* The terminal color used for printing normal output. */
	terminal::color::color_code normal;

	/* The terminal color used for indicating success. */
	terminal::color::color_code success;

	/* The terminal color used for indicating failure. */
	terminal::color::color_code failure;

	/* Whether colored terminal output is enabled. */
	bool color_enabled;

	/* Whether quiet mode is enabled. */
	bool quiet_mode;

	/* Whether assertions are abbreviated with dots. */
	bool dot_mode;

	/* Default constructor. */
	unit_test() :
		normal(terminal::color::cyan),
		success(terminal::color::green),
		failure(terminal::color::red),
		color_enabled(true),
		quiet_mode(false),
		dot_mode(false),
		_successes(0),
		_total(0)
	{
	}

	/* Run the unit test. Accepts a set of command line arguments.
	 * @param title The name of the unit test.
	 * @param argc The number of arguments.
	 * @param argv The array of arguments.
	 * */
	int run(const char *title, int argc, char **argv) {

		for(char **str = argv + 1, **end = argv + argc; str != end; ++str) {
			if(strcmp(*str, "-h") == 0 || strcmp(*str, "--help") == 0) {
				print_usage(std::cout, argv[0]);
				return 0;
			}
			else if(strcmp(*str, "-n") == 0 || strcmp(*str, "--no-color") == 0) {
				color_enabled = false;
			}
			else if(strcmp(*str, "-s") == 0 || strcmp(*str, "--silent") == 0) {
				quiet_mode = true;
			}
			else if(strcmp(*str, "-d") == 0 || strcmp(*str, "--dots") == 0) {
				dot_mode = true;
			}
			else {
				print_usage(std::cerr, argv[0]);
				return 1;
			}
		}

		_successes = _total = 0;
		if(!quiet_mode) {
			make_color(normal);
			if(dot_mode) std::cout << title;
			else std::cout << "==== " << title << " ====";
			make_color(terminal::color::clear);
			std::cout << std::endl;
			if(!dot_mode) std::cout << std::endl;
		}

		run_tests();

		if(!quiet_mode) {
			make_color(normal);
			if(dot_mode) {
				std::cout << std::endl;
				if(failures()) make_color(failure);
				else if(successes()) make_color(success);
				std::cout << successes() << '/' << total() << " tests passed";
				if(!succeeded()) {
					std::cout
						<< " (" << failures()
						<< " failure" << (failures() == 1 ? "" : "s")
						<< ')' << std::endl;
				}
				make_color(terminal::color::clear);
				for(std::vector<failure_location>::const_iterator
					i = _deferred_messages.begin(), n = _deferred_messages.end(); i != n; ++i)
				{
					make_color(failure);
					std::cout << "failed at ";
					make_color(normal);
					std::cout << i->filename << ':' << i->line;
					make_color(terminal::color::clear);
					std::cout << std::endl;
				}
				std::cout << std::endl;
			} else {
				std::cout << "==== TEST COMPLETE ====";
				make_color(terminal::color::clear);
				std::cout
					<< std::endl
					<< std::endl
					<< "Total tests: " << _total << std::endl;
				if(failures()) make_color(failure);
				std::cout << "Failures:    " << failures();
				make_color(terminal::color::clear);
				std::cout << std::endl;
				if(successes()) make_color(success);
				std::cout << "Successes:   " << successes();
				make_color(terminal::color::clear);
				std::cout
					<< std::endl
					<< std::endl;

				if(succeeded()) {
					make_color(success);
					std::cout << "SUCCESS";
				}
				else {
					make_color(failure);
					std::cout << "FAILURE";
				}

				make_color(terminal::color::clear);
				std::cout << std::endl
					<< std::endl;
			}
		}

		return !succeeded();

	}

	/* @return the number of successful assertions. */
	inline unsigned int successes() const {
		return _successes;
	}

	/* @return the number of failed assertions. */
	inline unsigned int failures() const {
		return _total - _successes;
	}

	/* @return the total number of assertions run. */
	inline unsigned int total() const {
		return _total;
	}

	/* @return whether the unit test succeeded.  */
	inline bool succeeded() const {
		return _successes == _total;
	}

protected:

	/* Run the unit test's assertions. */
	virtual void run_tests() = 0;

	/* Assert that `actual` is true. This is usually called through the
	 * `UNIT_TEST_TRUE` macro. */
	void test_true(
		const char *expr,
		bool actual,
		const char *name,
		const char *filename,
		unsigned int line
	)
	{
		begin_test(name);
		if(!quiet_mode && !dot_mode) {
			std::cout << expr << " is true" << std::endl;
		}
		if(actual) pass();
		else fail(filename, line);
	}

	/* Assert that `actual` is false. This is usually called through the
	 * `UNIT_TEST_FALSE` macro. */
	void test_false(
		const char *expr,
		bool actual,
		const char *name,
		const char *filename,
		unsigned int line
	)
	{
		begin_test(name);
		if(!quiet_mode && !dot_mode) {
			std::cout << expr << " is false" << std::endl;
		}
		if(!actual) pass();
		else fail(filename, line);
	}

	/* Assert that `actual == expected`. This is usually called through
	 * the `UNIT_TEST_EQUAL` macro. */
	template <typename T, typename U>
	void test_equal(
		const char *expr,
		const T &actual,
		const U &expected,
		const char *name,
		const char *filename,
		unsigned int line
	)
	{
		begin_test(name);
		if(show_assertions()) {
			std::cout << expr << " == " << expected << std::endl;
		}
		if(actual == expected) pass();
		else fail(filename, line);
	}

	/* Run a passing assertion which indicates that some expression
	 * exists at compile-time. This is usually called through the
	 * `UNIT_TEST_HAS_CONSTANT` macro. */
	void test_has_constant(
		const char *expr,
		const char *name
	)
	{
		begin_test(name);
		if(show_assertions()) {
			std::cout << expr << " exists" << std::endl;
		}
		pass();
	}

	/* Run a passing assertion which indicates that the program compiled.
	 * This is usually called through the `UNIT_TEST_COMPILES` macro. */
	void test_compiles(
		const char *name
	)
	{
		begin_test(name);
		if(show_assertions()) {
			std::cout << "This compiles" << std::endl;
		}
		pass();
	}

private:

	unsigned int _successes, _total;

	struct failure_location {
		const char *filename;
		unsigned int line;
	};

	std::vector<failure_location> _deferred_messages;

	void print_usage(std::ostream &out, const char *progname) {
		out
			<< progname << " [options]" << std::endl
			<< "    options:" << std::endl
			<< "        -h --help      Show this help message." << std::endl
			<< "        -n --no-color  Do not color the terminal output." << std::endl
			<< "        -s --silent    Do not print any output when running the test." << std::endl
			<< "        -d --dots      Abbreviate assertions as dots." << std::endl
			;
	}

	void begin_test(const char *name) {
		++_total;
		if(show_assertions()) {
			make_color(normal);
			std::cout << "== TEST #" << _total << ": " << name << " ==";
			make_color(terminal::color::clear);
			std::cout << std::endl;
		}
	}

	void pass() {
		if(!quiet_mode) {
			make_color(success);
			if(dot_mode) {
				std::cout << '.';
				make_color(terminal::color::clear);
				std::cout.flush();
			} else {
				std::cout << "PASSED";
				make_color(terminal::color::clear);
				std::cout << std::endl
					<< std::endl;
			}
		}
		++_successes;
	}

	void fail(const char *filename, unsigned int line) {
		if(!quiet_mode) {
			make_color(failure);
			if(dot_mode) {
				std::cout << 'x';
				make_color(terminal::color::clear);
				std::cout.flush();
				_deferred_messages.push_back(failure_location());
				failure_location &loc = _deferred_messages.back();
				loc.filename = filename;
				loc.line = line;
			} else {
				std::cout << "FAILED in " << filename << " at line " << line;
				make_color(terminal::color::clear);
				std::cout << std::endl
					<< std::endl;
			}
		}
	}

	template <typename T>
	inline void make_color(const T &c) const {
		if(color_enabled && !quiet_mode) {
			std::cout << c;
		}
	}

	inline bool show_assertions() const {
		return !quiet_mode && !dot_mode;
	}
};

#endif
