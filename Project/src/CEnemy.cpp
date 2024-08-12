#include "CEnemy.h"


void CEnemy::Init(SDL_Renderer* renderer, std::vector<const char*> anim_paths, Vector2 initial_position, std::string id) {
	this->m_Position = initial_position;
	for (size_t i = 0; i < anim_paths.size(); ++i) {
		m_EntityTexture.LoadTexture(renderer, anim_paths[i], id);
	}
	m_EntityTexture.SetScale(1);
	m_Velocity.x = m_fEnemySpeed;
	m_Velocity.y = m_fEnemySpeed;
}

void CEnemy::ChasePlayer(Vector2 player_position) {
	
	// Calculate distance vector from zombie to player. pf - zi
	// Multiply zombie velocity with unit vector of distance vector.

	Vector2 distance_vector = player_position - m_Position;
	Vector2 unit_vec = UnitVector(distance_vector);

	// Lets the zombie move towards the player with its base speed
	if (Magnitude(distance_vector) < 10) {
		m_Velocity.x = 0;
		m_Velocity.y = 0;
	}
	else {
		m_Velocity = unit_vec * m_fEnemySpeed;
	}
	
}

void CEnemy::TakeDamage(int damage) {
	this->m_nHealth -= damage;
}

void CEnemy::SetEnemySpeed(float speed) {
	this->m_fEnemySpeed = speed;
}

void CEnemy::Die(){
	this->m_EntityTexture.SetCurrentTexture("enemy_dead");
}

void CEnemy::Update(float dt) {
	m_Position += m_Velocity * dt;
}


void CEnemy::Cleanup() {
	// I seem to only be cleaning up textures... maybe this could be simplified
	this->m_EntityTexture.Cleanup();
}

void CEnemy::SetScale(int scale) {
	this->m_EntityTexture.SetScale(scale);
}
