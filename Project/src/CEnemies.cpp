#include "CEnemies.h"

void CZombie::InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position) {
	
	m_AnimPaths["base_zombie"] = "sprites/voidguy.png";
	m_AnimPaths["enemy_dead"] = "sprites/bishop-w.png";
	this->Init(renderer, initial_position);
	this->m_EntityTexture.SetCurrentTexture("base_zombie");
	this->SetEnemySpeed(225);
}

void CMediumZombie::InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position) {
	m_AnimPaths["medium_zombie"] = "sprites/girl_idea.png";
	m_AnimPaths["enemy_dead"] = "sprites/dead_stickman.png";
	this->Init(renderer, initial_position);
	this->m_EntityTexture.SetCurrentTexture("medium_zombie");
	this->SetEnemySpeed(125);
}
