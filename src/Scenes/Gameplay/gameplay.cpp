#include "gameplay.h"

#include "raylib.h"

#include <iostream>
#include <string>

#include "Player/player.h"
#include "Parallax/parallax.h"
#include "Tube/tube.h"


namespace game
{	

	int timer = 0;
	float frameCounter = 0;

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
			frameCounter += GetFrameTime();
			timer = static_cast<int>(frameCounter);
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

		DrawText("Press P to pause/unpause", FRAME_WIDTH / 2 - MeasureText("Press P to pause/unpause",20) / 2, 0, 20, GREEN);
		
		if(!multiplayer)
			DrawText(&std::to_string(timer)[0], FRAME_WIDTH - MeasureText(&std::to_string(timer)[0], 25), 0, 25, GREEN);

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

			if (multiplayer)
			{
				if (playerOneWins)
				{
					DrawText("WINNER: RED", FRAME_WIDTH / 2 - MeasureText("WINNER: RED", 40) / 2, FRAME_HEIGHT / 3 + 20, 40, RAYWHITE);
				}
				else
				{
					DrawText("WINNER: BLUE", FRAME_WIDTH / 2 - MeasureText("WINNER: BLUE", 40) / 2, FRAME_HEIGHT / 3 + 20, 40, RAYWHITE);
				}
			}
			else
			{
				std::string text = "You leasted " + std::to_string(timer) + " s.";
				DrawText(&text[0], FRAME_WIDTH / 2 - MeasureText(&text[0], 36) / 2, FRAME_HEIGHT / 3 + 20, 36, RAYWHITE);
			}

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
		timer = 0;
		frameCounter = 0.0f;
	}

	
}
//Praralax = https://opengameart.org/content/forest-parallax
//Posible animacion = https://opengameart.org/content/bird-and-explosion
//   ""      ""     = https://opengameart.org/content/bird-cute-bird