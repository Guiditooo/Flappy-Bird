#include "paralax.h"

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
		back.height *= scale;
		back.width *= scale;

		middle.height *= scale;
		middle.width *= scale;

		front.height *= scale;
		front.width *= scale;
	}
	
	void updateParalax()
	{
		//scrollingBack -= 0.1f;
		//scrollingMid -= 0.5f;
		//scrollingFore -= 1.0f;

		scrollingBack -= 200.0f * GetFrameTime();
		scrollingMid -= 350.0f * GetFrameTime();
		scrollingFore -= 400.0f * GetFrameTime();

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
