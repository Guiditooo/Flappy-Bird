#include "game.h"

#include "raylib.h"

#include <time.h>
#include <iostream>

#include "../../Menu/menu.h"
#include "../../Credits/credits.h"
#include "../gameplay.h"

namespace game
{

	static void init();
	static void update();
	static void draw();

	void execute()
	{
		init();

		do
		{
			update();
			draw();
		} while (playing && !WindowShouldClose());

		CloseWindow();
	}

	static void init()
	{
		InitWindow(FRAME_WIDTH, FRAME_HEIGHT, "Flappy Birds");

		InitExterns();

		srand(static_cast<unsigned int>(time(NULL)));

		currentScreen = Screen::MENU;

		initMenuScreen();
		initCreditsScreen();
	}

	static void update()
	{
		switch (currentScreen)
		{
		case Screen::MENU:
			updateMenuScreen();
			break;
		case Screen::GAMEPLAY:
			updateGameplayScreen();
			break;
		case Screen::CREDITS:
			updateCreditsScreen();
			break;
		case Screen::EXIT:
			playing = false;
			break;
		}
	}

	static void draw()
	{
		BeginDrawing();

		switch (currentScreen)
		{
		case Screen::MENU:
			drawMenuScreen();
			break;
		case Screen::GAMEPLAY:
			drawGameplayScreen();
			break;
		case Screen::CREDITS:
			drawCreditsScreen();
			break;
		}

		EndDrawing();
	}

}
