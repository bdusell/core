#ifndef CONTROLLER_BUTTON_DUO_H
#define CONTROLLER_BUTTON_DUO_H

namespace controller {

/* A virtual button with two switches. The value of the button is either 1, 0,
or -1 depending on which switches are set true. */
class button_duo {

public:

	/* Both switches are initially set to false. */
	inline button_duo() : _pos(false), _neg(false) {}

	inline bool &pos() { return _pos; }
	inline bool &neg() { return _neg; }

	inline operator int() const { return (int) _pos - (int) _neg; }

private:

	bool _pos, _neg;

};

} // namespace controller

#endif

