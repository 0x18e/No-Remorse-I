#pragma once
#include "CEnemy.h"

class CZombie : public CEnemy{
private:
	std::vector<const char*> anim_paths;

public:

	void InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position) {
		anim_paths.push_back("sprites/voidguy.png");

		// The scale of this sprite is inaccurate because it is NOT setting its scale in the init function
		//this->m_EntityTexture.LoadTexture(renderer, "sprites/girl_idea.png", "enemy_dead");
		
		this->Init(renderer, anim_paths, initial_position, "base_zombie");
		this->m_EntityTexture.LoadTexture(renderer, "sprites/dead_stickman.png", "enemy_dead");

		this->m_EntityTexture.SetCurrentTexture("base_zombie");
		

		this->SetEnemySpeed(100);
	}
	
	

};