#include "raylib.h"
#include "game.h"
#include "Menu.h"
#include "Gameplay.h"

namespace game
{
	enum Screen
	{
		menu,
		gameplay
	};

	static Screen currentScreen;

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
		InitWindow(640, 480, "Asteroid");

		currentScreen = menu;

		initMenuScreen();
		initGameplayScreen();
	}

	static void update()
	{
		switch (currentScreen)
		{
		case menu:
			updateMenuScreen();
			break;
		case gameplay:
			updateGameplayScreen();
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
		}

		EndDrawing();
	}

	static void close()
	{
		CloseWindow();
	}
}
