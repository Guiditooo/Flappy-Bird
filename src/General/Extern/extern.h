#ifndef EXTERN_H
#define EXTERN_H

#include "raylib.h"
#include "General/Enums/enums.h"

namespace game
{
	extern Texture2D tubeUp;
	extern Texture2D tubeDown;

	extern Screen currentScreen;

	extern int FRAME_WIDTH;
	extern int FRAME_HEIGHT;

	extern bool gameOver;
	extern bool paused;
	extern bool playing;

	extern bool multiplayer;
	extern bool playerOneWins;

	extern bool startedGameplay;

	void InitExterns();
}
#endif // !EXTERN_H
