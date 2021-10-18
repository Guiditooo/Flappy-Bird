#include "player.h"

#include "raylib.h"

namespace game
{
	Rectangle player;
	Texture2D character;
	Rectangle frameRec;
	Vector2 position;

	float birdForce = 170;
	float gravity = 59.8f;
	//float accel = 0.0f;

	int framesCounter = 0;
	int currentFrame = 0;
	int framesSpeed = 2;

	void initPlayer()
	{
		int size = 40;

		character = LoadTexture("res/birdSheet.png");
		character.height *= 0.2;
		character.width *= 0.2;
		frameRec = { 0.0f, 0.0f, (float)character.width / 4, (float)character.height };
		
		player.width = size; player.height = size;
		player.x = 20; player.y = GetScreenHeight() - 200;


	}
	void updatePlayer()
	{
		position.x = player.x;
		position.y = player.y;

		framesCounter++;

		if (framesCounter >= (1000 / framesSpeed))
		{
			framesCounter = 0;
			currentFrame++;

			if (currentFrame > 5)
			{
				currentFrame = 0;
			}
			frameRec.x = (float)currentFrame * (float)character.width / 4;
		}

		if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
				player.y -= birdForce;
		}
	
		player.y += gravity * GetFrameTime();

	}
	void drawPlayer()
	{
		ClearBackground(BLACK);

		//DrawRectangleRec(player, BLUE);
		DrawTextureRec(character, frameRec, position, WHITE);
	}
	void unloadPlayerTexture()
	{
		UnloadTexture(character);
	}
}