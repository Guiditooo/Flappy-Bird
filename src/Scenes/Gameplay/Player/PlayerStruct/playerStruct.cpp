#include "playerStruct.h"

namespace game
{

	void PlayerStruct::initPlayer()
	{
		float size = 60;

		character = LoadTexture("res/birdSheet.png");
		character.height = static_cast<int>(character.height * 0.15f);
		character.width = static_cast<int>(character.width * 0.15f);
		frameRec = { 0.0f, 0.0f, static_cast<float>(character.width / 4), static_cast<float>(character.height) };

		player.width = size;
		player.height = size;
		player.x = 0;
		player.y = static_cast<float>(FRAME_HEIGHT / 2 - size / 2);
	}

	void PlayerStruct::updatePlayer()
	{
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

		velocity += gravity * 4 / 3 * GetFrameTime();

		player.y += velocity * GetFrameTime();

		if (player.y < 0)
		{
			gameOver = true;
		}

		if (player.y + player.height > FRAME_HEIGHT)
		{
			gameOver = true;
		}



		position.x = player.x;
		position.y = player.y;
	}

	void PlayerStruct::drawPlayer(Color color)
	{
		ClearBackground(BLACK);
		DrawTextureRec(character, frameRec, position, WHITE);
		DrawRectangleRec(player, color);
	}

	void PlayerStruct::unloadPlayerTexture()
	{
		UnloadTexture(character);
	}

	bool PlayerStruct::checkCollisions(Obstacle obstacle)
	{
		Rectangle top = { obstacle.top.pos.x,obstacle.top.pos.y,static_cast<float>(obstacle.top.tex.width),static_cast<float>(obstacle.top.tex.height) };
		Rectangle bot = { obstacle.bot.pos.x,obstacle.bot.pos.y,static_cast<float>(obstacle.bot.tex.width),static_cast<float>(obstacle.bot.tex.height) };
		return (CheckCollisionRecs(player, top) || CheckCollisionRecs(player, bot));
	}

}