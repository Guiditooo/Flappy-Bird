#include "gameplay.h"

#include "raylib.h"

#include <iostream>

#include "Player/player.h"
#include "Parallax/parallax.h"
#include "Tube/tube.h"


namespace game
{

	

	void initGameplayScreen()
	{
		initPlayers();
		initParalax();
		initTubes();
	}

	void updateGameplayScreen()
	{
		if (!startedGameplay)
		{
			initGameplayScreen();
			startedGameplay = true;
		}
		if (!gameOver)
		{
			if (!paused)
			{
				updatePlayers();
				updateParalax();
				updateTubes();
				if (checkCol(getObstecle()))
				{
					gameOver = true;
				}
			}
			if (IsKeyPressed(KEY_P))
			{
				paused = !paused;
			}
		}
		else
		{
			if (IsKeyPressed(KEY_M)) 
			{
				restart();
				currentScreen = Screen::MENU;
				startedGameplay = false;
			}
			if (IsKeyPressed(KEY_R))
			{
				restart();
				startedGameplay = false;
			}
		}
	}

	void drawGameplayScreen()
	{
		ClearBackground(BLACK);
	
		drawParalax();
		drawTubes();
		drawPlayers();

		if (paused) 
		{
			//std::cout << "ENTREE";
			DrawRectangle(FRAME_WIDTH / 4, FRAME_HEIGHT / 4, FRAME_WIDTH / 2, FRAME_HEIGHT / 2, BROWN);
			DrawText("PAUSED", FRAME_WIDTH / 2 - MeasureText("PAUSED", 52) / 2, FRAME_HEIGHT / 2 - 26, 52, RAYWHITE);
		}
		if (gameOver)
		{
			DrawRectangle(FRAME_WIDTH / 4, FRAME_HEIGHT / 4, FRAME_WIDTH / 2, FRAME_HEIGHT / 2, BROWN);
			DrawText("GAME OVER", FRAME_WIDTH / 2 - MeasureText("GAME OVER", 52) / 2, FRAME_HEIGHT / 4, 52, RAYWHITE);
			DrawText("R - RETRY", FRAME_WIDTH / 2 - MeasureText("R - RETRY", 52) / 2, FRAME_HEIGHT / 2, 52, RAYWHITE);
			DrawText("M - MENU", FRAME_WIDTH / 2 - MeasureText("M - MENU", 52) / 2, FRAME_HEIGHT * 3 / 4 - 52, 52, RAYWHITE);
		}

	}
	void unloadTextures()
	{
		unloadPlayerTextures();
		unloadParalaxTextures();
		unloadTubesTexture();
	}
	void restart()
	{
		gameOver = false;
		paused = false;
		initGameplayScreen();
	}

	
}
//Praralax = https://opengameart.org/content/forest-parallax
//Posible animacion = https://opengameart.org/content/bird-and-explosion
//   ""      ""     = https://opengameart.org/content/bird-cute-bird