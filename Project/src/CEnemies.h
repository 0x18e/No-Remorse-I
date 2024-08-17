#pragma once
#include "CEnemy.h"

class CZombie : public CEnemy{
private:
public:
	void InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position);
};

class CMediumZombie : public CEnemy {
private:
public:

	void InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position);

};