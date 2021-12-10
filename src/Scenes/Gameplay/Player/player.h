#ifndef PLAYER_H
#define PLAYER_H

#include "Scenes/Gameplay/Tube/tube.h"

namespace game 
{
	void initPlayers();
	void updatePlayers();
	void drawPlayers();
	void unloadPlayerTextures();
	bool checkCol(Obstacle obstacle);
}

#endif // !PLAYER_H

