#pragma once
#include "CEnemy.h"

class CZombie : public CEnemy{
private:
	std::vector<const char*> anim_paths;

public:

	void InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position) {
		anim_paths.push_back("sprites/bishop-w.png");
		anim_paths.push_back("sprites/bunny-mage.png");

		this->Init(renderer, anim_paths, initial_position, "base_zombie");
		
		this->m_EntityTexture.SetCurrentTexture("base_zombie");
		this->SetEnemySpeed(100);
	}
	
	

};