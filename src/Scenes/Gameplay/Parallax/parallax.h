#ifndef PARALLAX_H
#define PARALLAX_H

namespace game
{

	const int VELOCITY_BACK = 60;
	const int VELOCITY_MID = 80;
	const int VELOCITY_FRONT = 100;

	void initParalax();
	void updateParalax();
	void drawParalax();
	void unloadParalaxTextures();

}

#endif // !PARALLAX_H