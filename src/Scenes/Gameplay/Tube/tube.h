#ifndef TUBES_H
#define TUBES_H

#include "General/Extern/extern.h"
#include "General/TextureX/textureX.h"

namespace game
{

	const int SPACE_BETWEEN_TUBES = 140;
	const int MIN_TUBE_Y = -400;
	const int MAX_TUBE_Y = -200;

	const int TUBE_WIDTH = 100;
	const int TUBE_HEIGHT = 450;

	const int OBSTACLE_COUNT = 3;

	static float tubeVelocity = 200.0f;

	struct Obstacle
	{
		TextureX top;
		TextureX bot;
		Obstacle();
		void SetPosY(float newY);
		void SetPosX(float newX);
		float GetPosX();
		void SetRandomY();
		void Draw();
		void UnloadTextures();
	};

	void initTubes();
	void updateTubes();
	void drawTubes();
	void unloadTubesTexture();
	Obstacle getObstecle();

}

#endif // !TUBES_H
