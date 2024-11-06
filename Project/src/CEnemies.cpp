#include "CEnemies.h"

void CZombie::InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position) {
	
	m_AnimPaths["base_zombie"] = "sprites/small_zom.png";
	m_AnimPaths["enemy_dead"] = "sprites/lil_zom_ded.png";
	this->Init(renderer, initial_position);
	this->m_EntityTexture.SetCurrentTexture("base_zombie");
	this->SetEnemySpeed(225);
}

void CMediumZombie::InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position) {
	m_AnimPaths["medium_zombie"] = "sprites/blue_zombie.png";
	m_AnimPaths["enemy_dead"] = "sprites/blue_dead.png";
	this->Init(renderer, initial_position);
	this->m_EntityTexture.SetCurrentTexture("medium_zombie");
	this->SetEnemySpeed(125);
}

void CBigZombie::InitializeZombie(SDL_Renderer* renderer, Vector2 initial_position) {
	m_AnimPaths["big_zombie"] = "sprites/big_zombie.png";
	m_AnimPaths["enemy_dead"] = "sprites/big_zom_dead.png";
	this->Init(renderer, initial_position);
	this->m_EntityTexture.SetCurrentTexture("big_zombie");
	this->SetEnemySpeed(80);

}
