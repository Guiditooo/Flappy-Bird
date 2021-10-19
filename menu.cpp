#include "menu.h"

#include "raylib.h"

namespace game
{
	static void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int height);
	void updateButtons(Rectangle& buttton1, Rectangle& buttton2, Rectangle& buttton3, Screen& currenScreen);

	static Rectangle button1;
	static Rectangle button2;
	static Rectangle button3;



	void initMenuScreen()
	{
		int sizeX = 150;
		int sizeY = 50;
		setButtons(button1, sizeX, sizeY, 150);
		setButtons(button2, sizeX, sizeY, 225);
		setButtons(button3, sizeX, sizeY, 300);
	}
	void updateMenuScreen(Screen& currentScreen)
	{
		updateButtons(button1, button2, button3, currentScreen);
		
	}

	void drawMenuScreen()
	{
		int fontSize = 30;
		ClearBackground(BLACK);

		DrawText("Flappy Birds", GetScreenWidth() / 2 - 200, 50, 60, YELLOW);

		DrawRectangleRec(button1, ORANGE);
		DrawText("PLAY", button1.x + button1.width / 2 - MeasureText("PLAY", fontSize) / 2, button1.y + fontSize / 2, fontSize, YELLOW);

		DrawRectangleRec(button2, ORANGE);
		DrawText("CREDITS", button2.x + button2.width / 2 - MeasureText("CREDITS", fontSize) / 2, button2.y + fontSize / 2, fontSize, YELLOW);

		DrawRectangleRec(button3, ORANGE);
		DrawText("EXIT", button3.x + button3.width / 2 - MeasureText("EXIT", fontSize) / 2, button3.y + fontSize / 2, fontSize, YELLOW);
	
		DrawText("Version 0.2", GetScreenWidth() - MeasureText("Version 0.2", 15), GetScreenHeight() - 30, 15, RED);
	}


	static void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int height)
	{
		rectangle.height = sizeY;
		rectangle.width = sizeX;
		rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2);
		rectangle.y = height;
	}
	static void updateButtons(Rectangle& buttton1, Rectangle& buttton2, Rectangle& buttton3, Screen& currentScreen)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(GetMousePosition(), button1))
			{
				currentScreen = gameplay;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), button2))
			{
				currentScreen = credits;
			}
			else if (CheckCollisionPointRec(GetMousePosition(), button3))
			{
				currentScreen = exit;
			}
		}
	}
}