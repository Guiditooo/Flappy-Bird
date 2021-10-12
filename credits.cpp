#include "credits.h"

#include "raylib.h"

namespace game
{
	Rectangle button;

	void initCreditsScreen()
	{
		button.height = 20;
		button.width = MeasureText("Back", 15) + 5;
		button.x = 0;
		button.y = 0;
	}
	void updateCreditsScreen(Screen& currentScreen)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(GetMousePosition(), button))
			{
				currentScreen = menu;
			}
		}
	}	
	void drawCreditsScreen()
	{
		int fontSize = 25;
		ClearBackground(BLACK);

		DrawRectangleRec(button, BLUE);
		DrawRectangleLinesEx(button, 1, YELLOW);
		DrawText("Back", button.x + button.width / 2 - MeasureText("Back", 15) / 2, button.y + 4, 15, BLACK);

		DrawText("Credits", GetScreenWidth() / 2 - 100, 50, 60, YELLOW);

		DrawText("Created by: ", 0, 150, 35, YELLOW);
		DrawText("Ramiro Guzman ", 0, 225, fontSize, BLUE);


		DrawText("Version 0.1", GetScreenWidth() - MeasureText("Version 0.1", fontSize), GetScreenHeight() - fontSize, fontSize, RED);
	}
}
