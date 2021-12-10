#ifndef PLAYER_STRUCT_H
#define PLAYER_STRUCT_H

#include "General/Extern/extern.h"
#include "Scenes\Gameplay\Tube\tube.h"
#include "raylib.h"

namespace game
{

	struct PlayerStruct
	{
		Rectangle player = Rectangle();
		Texture2D character = Texture2D();
		Rectangle frameRec = Rectangle();
		Vector2 position = Vector2();

		float gravity = 275;
		float velocity = 0.0f;
		float accel = 0.0f;

		int framesCounter = 0;
		int currentFrame = 0;
		int framesSpeed = 2;

		void initPlayer();
		void updatePlayer();
		void drawPlayer(Color color);
		void unloadPlayerTexture();
		bool checkCollisions(Obstacle obstacle);

	};

}

#endif // !PLAYER_STRUCT_H
