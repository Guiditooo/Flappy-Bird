#include "raylib.h"
#include "game.h"
#include "Menu.h"
#include "credits.h"
#include "Gameplay.h"
#include "enums.h"

namespace game
{
	Screen currentScreen;

	static void init();
	static void update();
	static void draw();
	static void close();

	void execute()
	{
		init();
		currentScreen = menu;

		while (!WindowShouldClose())
		{
			update();
			draw();
		}

		close();
	}

	static void init()
	{
		InitWindow(640, 480, "Flappy Birds");

		currentScreen = menu;

		initMenuScreen();
		initCreditsScreen();
		initGameplayScreen();
	}

	static void update()
	{
		switch (currentScreen)
		{
		case menu:
			updateMenuScreen(currentScreen);
			break;
		case gameplay:
			updateGameplayScreen();
			break;
		case credits:
			updateCreditsScreen(currentScreen);
			break;
		case exit:
		
			break;
		}
	}

	static void draw()
	{
		BeginDrawing();

		switch (currentScreen)
		{
		case menu:
			drawMenuScreen();
			break;
		case gameplay:
			drawGameplayScreen();
			break;
		case credits:
			drawCreditsScreen();
			break;
		case exit:
			close(); //Modificar por alguna variable que termine el while
			break;
		}

		EndDrawing();
	}

	static void close()
	{
		CloseWindow();
	}
}
