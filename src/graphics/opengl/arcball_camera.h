#ifndef GRAPHICS_HW03_ARCBALL_CAMERA_H
#define GRAPHICS_HW03_ARCBALL_CAMERA_H

// TODO

#include <GL/glu.h>
#include "graphics/hw01/point.h"
#include "graphics/hw01/math.h"
#include "graphics/hw02/controller.h"
#include "spherical.h"

namespace graphics {
namespace hw03 {

using namespace graphics::hw01;
using namespace graphics::hw02;

/* OPerates in units of radians. */
template <typename T>
class controlled_spherical_coordinate : public spherical_coordinate< controlled_radian_angle<T> > {

	typedef spherical_coordinate< controlled_radian_angle<T> > super;

public:

	controlled_spherical_coordinate() {}
	controlled_spherical_coordinate(T r, T theta, T phi) : super(r, theta, phi) {}

	/* Convenient aliases for the control switches. */
	inline bool &left() { return this->theta().neg(); }
	inline bool &right() { return this->theta().pos(); }
	inline bool &up() { return this->phi().pos(); }
	inline bool &down() { return this->phi().neg(); }
	inline bool &in() { return this->r().neg(); }
	inline bool &out() { return this->r().pos(); }

	/* zoomspeed is in units per second, thetaspeed and phispeed are in
	radians per second. */
	inline void update(T dt, T zoomspeed, Float thetaspeed, Float phispeed) {
		this->theta().update(dt, -thetaspeed);
		this->phi().update(dt, -phispeed);
		this->r().update(dt, -zoomspeed);
	}

private:

};

class arcball_camera {

public:

	arcball_camera(Float r, Float theta, Float phi) : _pos(r, theta, phi) {}

	void update(Float dt, Float zoomspeed, Float thetaspeed, Float phispeed) {
		_pos.update(dt, zoomspeed, thetaspeed, phispeed);
	}

	template <typename T>
	void look(const T &focus) const {
		point3f pos = _pos.to_cartesian<vector3f>() + focus;
		vector3f up = up_vector();
		gluLookAt(
			pos.x(), pos.y(), pos.z(),
			focus.x(), focus.y(), focus.z(),
			up.x(), up.y(), up.z()
		);
	}

	inline controlled_spherical_coordinate<Float> &pos() {
		return _pos;
	}

private:

	controlled_spherical_coordinate<Float> _pos;

	vector3f up_vector() const {
		sphericalf up = _pos;
		up.phi() -= 0.5f * pi;
		return up.to_cartesian<vector3f>();
	}

};

} // namespace hw03
} // namespace graphics

#endif

