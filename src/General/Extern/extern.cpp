#include "extern.h"
namespace game
{
	Texture2D tubeUp;
	Texture2D tubeDown;

	int FRAME_WIDTH = 640;
	int FRAME_HEIGHT = 480;

	bool gameOver = false;
	bool paused = false;

	bool playing = true;

	bool multiplayer = true;
	bool playerOneWins = true;

	bool startedGameplay = false;

	Screen currentScreen = Screen::MENU;

	void InitExterns()
	{
		tubeUp = LoadTexture("res/TubeUp.png");
		tubeDown = LoadTexture("res/TubeDown.png");
	}
}