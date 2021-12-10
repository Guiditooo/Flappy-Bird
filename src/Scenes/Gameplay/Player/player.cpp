#include "player.h"

#include "PlayerStruct/playerStruct.h"

#include "raylib.h"

namespace game
{
	PlayerStruct player1;

	PlayerStruct player2;


	void initPlayers()
	{

		player1.initPlayer();

		player1.accel = 0.0f;
		player1.velocity = 0.0f;

		if (multiplayer)
		{
			float size = 40;

			player2.initPlayer();

			player1.character = LoadTexture("res/birdSheet.png");
			player1.character.height = static_cast<int>(player1.character.height * 0.1f);
			player1.character.width = static_cast<int>(player1.character.width * 0.1f);
			player1.frameRec = { 0.0f, 0.0f, static_cast<float>(player1.character.width / 4), static_cast<float>(player1.character.height) };
			player1.player.width = size;
			player1.player.height = size;
			player1.player.x = 0;
			player1.player.y = static_cast<float>(FRAME_HEIGHT * 1 / 4 - size / 2);

			player2.character = LoadTexture("res/birdSheet.png");
			player2.character.height = static_cast<int>(player2.character.height * 0.1f);
			player2.character.width = static_cast<int>(player2.character.width * 0.1f);
			player2.frameRec = { 0.0f, 0.0f, static_cast<float>(player2.character.width / 4), static_cast<float>(player2.character.height) };
			player2.player.width = size;
			player2.player.height = size;
			player2.player.x = 0;
			player2.player.y = static_cast<float>(FRAME_HEIGHT * 3 / 4 - size / 2);

			player2.accel = 0.0f;
			player2.velocity = 0.0f;

		}
			
	}

	void updatePlayers()
	{
		player1.updatePlayer();
		if (IsKeyPressed(KEY_SPACE))
		{
			player1.velocity = -player1.gravity * 2 / 3;
		}
		if (multiplayer)
		{
			player2.updatePlayer();
			if (IsKeyPressed(KEY_UP))
			{
				player2.velocity = -player2.gravity * 2 / 3;
			}
		}
	}

	void drawPlayers()
	{
		player1.drawPlayer(RED);
		if (multiplayer)
			player2.drawPlayer(BLUE);
	}

	void unloadPlayerTextures()
	{
		player1.unloadPlayerTexture();
		if (multiplayer)
			player2.unloadPlayerTexture();
	}

	bool checkCol(Obstacle obstacle)
	{
		bool ret = false;
		if (multiplayer)
		{
			ret = player1.checkCollisions(obstacle) || player2.checkCollisions(obstacle);
		}
		else
		{
			ret = player1.checkCollisions(obstacle);
		}
		
		return ret;
	}

}