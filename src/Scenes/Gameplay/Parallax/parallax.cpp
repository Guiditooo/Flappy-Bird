#include "parallax.h"

#include "raylib.h"

namespace game
{
	Texture2D front;
	Texture2D middle;
	Texture2D back;

	float scrollingBack;
	float scrollingMid;
	float scrollingFore;

	void initParalax()
	{
		front = LoadTexture("res/paralax/front.png");
		
		middle = LoadTexture("res/paralax/middle.png");
		
		back = LoadTexture("res/paralax/back.png");

		float scale = 0.6f;
		back.height = static_cast<int>(back.height * scale);
		back.width = static_cast<int>(back.width * scale);

		middle.height = static_cast<int>(middle.height * scale);
		middle.width = static_cast<int>(middle.width * scale);

		front.height = static_cast<int>(front.height * scale);
		front.width = static_cast<int>(front.width * scale);
	}
	
	void updateParalax()
	{

		scrollingBack -= VELOCITY_BACK * GetFrameTime();
		scrollingMid -=  VELOCITY_MID * GetFrameTime();
		scrollingFore -= VELOCITY_FRONT * GetFrameTime();

		if (scrollingBack <= -back.width * 2)
		{
			scrollingBack = 0;
		}
		if (scrollingMid <= -middle.width * 2)
		{ 
			scrollingMid = 0;
		}
		if (scrollingFore <= -front.width * 2)
		{
			scrollingFore = 0; 
		}
	}
	void drawParalax()
	{
		ClearBackground(BLUE);

		DrawTextureEx(back, { scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(back, { back.width * 2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(middle, { scrollingMid, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(middle,  { middle.width * 2 + scrollingMid, 0 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(front, { scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(front, { front.width * 2 + scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
	}
	void unloadParalaxTextures()
	{
		UnloadTexture(front);
		UnloadTexture(middle);
		UnloadTexture(back);
	}

}
