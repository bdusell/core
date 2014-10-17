#include "graphics/color/rgb.h"
#include "unit_test.h"

UNIT_TEST(rgb_color) {

	typedef graphics::color::rgb<unsigned char, 3> irgb;
	typedef graphics::color::rgb<unsigned char, 4> irgba;

	{
		irgb a;
		UNIT_TEST_COMPILES("default constructible");
	}

	{
		irgba a(0, 127, 255, 200);
		UNIT_TEST_EQUAL(a.r(), 0, "has red member");
		UNIT_TEST_EQUAL(a.g(), 127, "has green member");
		UNIT_TEST_EQUAL(a.b(), 255, "has blue member");
		UNIT_TEST_EQUAL(a.a(), 200, "has alpha member");
	}
}
