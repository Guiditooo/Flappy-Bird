#include "tube.h"

#include <iostream>

namespace game
{	

	Obstacle obstacle;

	float velCoef = 0.0005f;

	void initTubes()
	{
		obstacle = Obstacle();
	}

	void updateTubes()
	{
		obstacle.SetPosX(obstacle.GetPosX() - GetFrameTime() * tubeVelocity);
		tubeVelocity = tubeVelocity + velCoef;

		if (obstacle.GetPosX() < 0 - TUBE_WIDTH)
		{
			obstacle.SetPosX(static_cast<float>(FRAME_WIDTH));
			obstacle.SetRandomY();
		}

	}

	void drawTubes()
	{
		obstacle.Draw();
	}

	void unloadTubesTexture()
	{
		obstacle.UnloadTextures();
	}

	Obstacle getObstecle()
	{
		return obstacle;
	}

	Obstacle::Obstacle()
	{	
		top.tex = tubeUp;
		bot.tex = tubeDown;

		top.tex.width = TUBE_WIDTH;
		bot.tex.width = TUBE_WIDTH;

		top.tex.height = TUBE_HEIGHT;
		bot.tex.height = TUBE_HEIGHT;

		top.pos.x = static_cast<float>(FRAME_WIDTH);
		bot.pos.x = static_cast<float>(FRAME_WIDTH);

		top.pos.y = -200;
		bot.pos.y = top.pos.y + SPACE_BETWEEN_TUBES + bot.tex.height;
	}

	void Obstacle::SetPosY(float newY)
	{
		top.pos.y = newY;
		bot.pos.y = top.pos.y + SPACE_BETWEEN_TUBES + bot.tex.height;
	}

	void Obstacle::SetPosX(float newX)
	{
		top.pos.x = newX;
		bot.pos.x = newX;
	}

	float Obstacle::GetPosX()
	{
		return top.pos.x;
	}

	void Obstacle::SetRandomY()
	{
		SetPosY(static_cast<float>(MIN_TUBE_Y + (rand() % (MAX_TUBE_Y - MIN_TUBE_Y))));
	}

	void Obstacle::Draw()
	{
		DrawTexture(top.tex, static_cast<int>(top.pos.x), static_cast<int>(top.pos.y), WHITE);
		DrawTexture(bot.tex, static_cast<int>(bot.pos.x), static_cast<int>(bot.pos.y), WHITE);
	}

	void Obstacle::UnloadTextures()
	{
		UnloadTexture(top.tex);
		UnloadTexture(bot.tex);
	}

}