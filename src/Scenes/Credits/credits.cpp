#include "credits.h"

#include "raylib.h"

namespace game
{
	Rectangle button;

	void initCreditsScreen()
	{
		button.height = 30;
		button.width = static_cast<float>(MeasureText("Back", 25) + 5);
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
		DrawText("Back", static_cast<int>(button.x + button.width / 2 - MeasureText("Back", fontSize) / 2), static_cast<int>(button.y + 4), fontSize, BLACK);

		DrawText("Credits", GetScreenWidth() / 2 - 100, 50, 60, YELLOW);

		DrawText("Developed by:", 0, 150, 35, YELLOW);
		DrawText("GUZMAN, Ramiro (ORIGINAL)", 100, 200, fontSize, BLUE);
		DrawText("TELLO, Guido (FORKED)", 100, 230, fontSize, BLUE);

		DrawText("Art by:", 0, 270, 35, YELLOW);
		DrawText("LARRIVEY, Agostina (Tubes)", 100, 320, fontSize, BLUE);
		DrawText("Unknown (Parallax & Bird)", 100, 350, fontSize, BLUE);

		DrawText("Version 1.0", GetScreenWidth() - MeasureText("Version 1.0", fontSize), GetScreenHeight() - 40, fontSize, RED);
	}
}
