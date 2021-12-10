#include "menu.h"

#include "raylib.h"

namespace game
{
	static void setButtons(Rectangle& rectangle, float sizeX, float sizeY, float height);
	static void updateButtons();

	static Rectangle button0;
	static Rectangle button1;
	static Rectangle button2;
	static Rectangle button3;

	void initMenuScreen()
	{
		float sizeX = 150;
		float sizeY = 50;
		setButtons(button0, sizeX, sizeY, 150);
		setButtons(button1, sizeX, sizeY, 225);
		setButtons(button2, sizeX, sizeY, 300);
		setButtons(button3, sizeX, sizeY, 375);
	}
	void updateMenuScreen()
	{
		updateButtons();
	}

	void drawMenuScreen()
	{
		int fontSize = 30;
		ClearBackground(BLACK);

		DrawText("Flappy Birds", GetScreenWidth() / 2 - 200, 50, 60, YELLOW);

		DrawRectangleRec(button0, ORANGE);
		DrawText("2 P", static_cast<int>(button0.x + static_cast<int>(button0.width / 2) - static_cast<float>(MeasureText("2 P", fontSize) / 2)), static_cast<int>(button0.y + static_cast<float>(fontSize) / 2), fontSize, YELLOW);

		DrawRectangleRec(button1, ORANGE);
		DrawText("1 P", static_cast<int>(button1.x + static_cast<int>(button1.width / 2) - static_cast<float>(MeasureText("1 P", fontSize) / 2)), static_cast<int>(button1.y + static_cast<float>(fontSize) / 2), fontSize, YELLOW);

		DrawRectangleRec(button2, ORANGE);
		DrawText("CREDITS", static_cast<int>(button2.x + static_cast<int>(button2.width / 2) - static_cast<float>(MeasureText("CREDITS", fontSize) / 2)), static_cast<int>(button2.y + static_cast<float>(fontSize) / 2), fontSize, YELLOW);

		DrawRectangleRec(button3, ORANGE);
		DrawText("EXIT", static_cast<int>(button3.x + static_cast<int>(button3.width / 2) - static_cast<float>(MeasureText("EXIT", fontSize) / 2)), static_cast<int>(button3.y + static_cast<float>(fontSize) / 2), fontSize, YELLOW);
	
		DrawText("Version 0.3", GetScreenWidth() - MeasureText("Version 0.3", 15), GetScreenHeight() - 30, 15, RED);
	}


	static void setButtons(Rectangle& rectangle, float sizeX, float sizeY, float height)
	{
		rectangle.height = sizeY;
		rectangle.width = sizeX;
		rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2);
		rectangle.y = height;
	}
	static void updateButtons()
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(GetMousePosition(), button0))
			{
				multiplayer = true;
				currentScreen = Screen::GAMEPLAY;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), button1))
			{
				multiplayer = false;
				currentScreen = Screen::GAMEPLAY;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), button2))
			{
				currentScreen = Screen::CREDITS;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), button3))
			{
				currentScreen = Screen::EXIT;
			}
		}
	}
}