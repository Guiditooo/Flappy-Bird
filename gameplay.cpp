#include "gameplay.h"

#include "raylib.h"

#include "player.h"
#include "paralax.h"


namespace game
{

	void initGameplayScreen()
	{
		initPlayer();
		initParalax();
	}

	void updateGameplayScreen()
	{
		
		updatePlayer();
		updateParalax();
	}

	void drawGameplayScreen()
	{
		ClearBackground(BLACK);
	
		drawParalax();
		drawPlayer();
	}
	void unloadTextures()
	{
		unloadPlayerTexture();
		unloadParalaxTextures();
	}
}
//Praralax = https://opengameart.org/content/forest-parallax
//Posible animacion = https://opengameart.org/content/bird-and-explosion
//   ""      ""     = https://opengameart.org/content/bird-cute-bird