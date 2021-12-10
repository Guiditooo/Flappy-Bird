#include "credits.h"

#include "raylib.h"

namespace game
{
	Rectangle button;

	void initCreditsScreen()
	{
		button.height = 20;
		button.width = static_cast<float>(MeasureText("Back", 15) + 5);
		button.x = 0;
		button.y = 0;
	}
	void updateCreditsScreen()
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(GetMousePosition(), button))
			{
				currentScreen = Screen::MENU;
			}
		}
	}	
	void drawCreditsScreen()
	{
		int fontSize = 25;
		ClearBackground(BLACK);

		DrawRectangleRec(button, BLUE);
		DrawRectangleLinesEx(button, 1, YELLOW);
		DrawText("Back", static_cast<int>(button.x + button.width / 2 - MeasureText("Back", 15) / 2), static_cast<int>(button.y + 4), 15, BLACK);

		DrawText("Credits", GetScreenWidth() / 2 - 100, 50, 60, YELLOW);

		DrawText("Created by:", 0, 150, 35, YELLOW);
		DrawText("GUZMAN, Ramiro (ORIGINAL)", 100, 225, fontSize, BLUE);
		DrawText("TELLO, Guido (FORKED)", 100, 270, fontSize, BLUE);


		DrawText("Version 0.3", GetScreenWidth() - MeasureText("Version 0.3", fontSize), GetScreenHeight() - 40, fontSize, RED);
	}
}
