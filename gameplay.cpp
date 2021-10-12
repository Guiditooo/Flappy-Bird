#include "gameplay.h"
#include "raylib.h"



namespace game
{
	Rectangle player;
	Rectangle enemy;

	void initGameplayScreen()
	{
		int size = 40;
		
		player.width = size; player.height = size; 
		player.x = 10; player.y = GetScreenHeight() - 200;

		enemy.width = size; enemy.height = size;
		enemy.x = GetScreenWidth() ; enemy.y = GetRandomValue(0, GetScreenHeight());

	}

	void updateGameplayScreen()
	{
		int velocityEnemy = 50;
		int velocityPlayer = 8500;

		enemy.x -= velocityEnemy * GetFrameTime();

		if (IsKeyPressed(KEY_S))
		{
			player.y += velocityPlayer * GetFrameTime();
		}
		if (IsKeyPressed(KEY_W))
		{
			player.y -= velocityPlayer * GetFrameTime();
		}

		if (CheckCollisionRecs(player, enemy) || enemy.x == 0)
		{
			player.x = 10; player.y = GetScreenHeight() - 200;

			enemy.x = GetScreenWidth(); enemy.y = GetRandomValue(0, GetScreenHeight());

		}
	}

	void drawGameplayScreen()
	{
		ClearBackground(BLACK);
	
		DrawRectangleRec(player, BLUE);
		DrawRectangleRec(enemy, RED);

	}

}
