#include "menu.h"

#include "raylib.h"

static void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int height);
static bool updateButtons(Rectangle& rectangle);

namespace game
{
	static Rectangle button1;
	static Rectangle button2;
	static Rectangle button3;
	static Rectangle button4;


	void initMenuScreen()
	{
		int sizeX = 150;
		int sizeY = 50;
		setButtons(button1, sizeX, sizeY, 150);
		setButtons(button2, sizeX, sizeY, 225);
		setButtons(button3, sizeX, sizeY, 300);
		setButtons(button4, sizeX, sizeY, 375);
	}

	void updateMenuScreen()
	{
		if (updateButtons(button1))
		{
			//Llamar al play

		}
		if (updateButtons(button2))
		{
			// LLAmar creditos.

		}
		if (updateButtons(button3))
		{
			//Close Windows

		}


	}

	void drawMenuScreen()
	{

		int fontSize = 30;
		ClearBackground(BLACK);
		DrawText("ASTEROID", GetScreenWidth() / 2 - 150, 50, 60, YELLOW);
		DrawRectangleRec(button1, ORANGE);
		DrawText("PLAY", button1.x + button1.width / 2 - MeasureText("PLAY", fontSize) / 2, button1.y + fontSize / 2, fontSize, YELLOW);
		DrawRectangleRec(button2, ORANGE);
		DrawText("CREDITS", button2.x + button2.width / 2 - MeasureText("CREDITS", fontSize) / 2, button2.y + fontSize / 2, fontSize, YELLOW);
		DrawRectangleRec(button3, ORANGE);
		DrawText("EXIT", button3.x + button3.width / 2 - MeasureText("EXIT", fontSize) / 2, button3.y + fontSize / 2, fontSize, YELLOW);
		DrawRectangleRec(button4, ORANGE);

	}
}

static void setButtons(Rectangle& rectangle, int sizeX, int sizeY, int height)
{
	rectangle.height = sizeY;
	rectangle.width = sizeX;
	rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2);
	rectangle.y = height;
}
static bool updateButtons(Rectangle& rectangle)
{
	if (GetMousePosition().x > rectangle.x && GetMousePosition().x < rectangle.x + rectangle.width)
	{
		if (GetMousePosition().y > rectangle.y && GetMousePosition().y < rectangle.y + rectangle.height)
		{
			if (IsMouseButtonPressed(3))
			{
				return true;
			}
		}

	}
}