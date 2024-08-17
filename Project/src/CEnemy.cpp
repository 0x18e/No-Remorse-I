#include "CEnemy.h"


void CEnemy::Init(SDL_Renderer* renderer, Vector2 initial_position) {
	this->m_Position = initial_position;
	m_EntityTexture.SetScale(2);
	/*
	for (size_t i = 0; i < m_AnimPaths.size(); ++i) {
		m_EntityTexture.LoadTexture(renderer, anim_paths[i], ids[i]);
	}
	*/
	// Setup initial animations
	for (auto value : m_AnimPaths) {
		if (value.first == "enemy_dead") {
			path_to_death_sprite = value.second;
		}
		m_EntityTexture.LoadTexture(renderer, value.second, value.first);
	}

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
	// this might be very costly
	m_dAngle = atan2(long(player_position.y - m_Position.y), long(player_position.x- m_Position.x)) * long(180 / M_PI) - 90;

	
}

void CEnemy::TakeDamage(int damage) {
	this->m_nHealth -= damage;
}

void CEnemy::SetEnemySpeed(float speed) {
	this->m_fEnemySpeed = speed;
}

void CEnemy::KnockBack(Vector2 impact_force) {
	// Get the unit vector of our current velocity
	Vector2 unit_vec = UnitVector(this->m_Velocity);
	unit_vec.x = -unit_vec.x;
	unit_vec.y = -unit_vec.y;
	this->m_Position += unit_vec*impact_force;
}



void CEnemy::Die(){
	// LAZY
	if (m_bIsAlive == true) {
		m_bIsAlive = false;
		this->m_EntityTexture.SetCurrentTexture("enemy_dead");
		CSoundManager::Get().PlaySound("enemy_death");
	}
}

void CEnemy::Update(float dt) {
	m_Position += m_Velocity * dt;
	if (m_nHealth <= 0) {
		this->Die();
	}
}


void CEnemy::Cleanup() {
	// I seem to only be cleaning up textures... maybe this could be simplified
	this->m_EntityTexture.Cleanup();
}

void CEnemy::SetScale(int scale) {
	this->m_EntityTexture.SetScale(scale);
}
