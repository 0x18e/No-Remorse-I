#pragma once
#include "CEntity.h"
#include <vector>
#include "CSoundManager.h"

class CEnemy : public CEntity{
private:
	int m_nHealth = 150;
	float m_fEnemySpeed = 600;
	bool m_bIsAlive = true;
	std::string path_to_death_sprite; // Ensure that every enemy that is created has a death sprite
	bool m_bIsVisible = false;
protected:
	void Init(SDL_Renderer* renderer, Vector2 initial_position);
	std::map<const char*, const char*> m_AnimPaths;
public:
	void ChasePlayer(Vector2 player_position);
	bool IsAlive() { return m_bIsAlive; }
	void TakeDamage(int damage);
	void SetEnemySpeed(float speed);
	int GetHealth() { return m_nHealth; }
	void SetVisibility(bool visibility);
	bool GetVisibility();
	void KnockBack(Vector2 impact_force);
	void Die();
	void Update(float dt);
	void Cleanup();
};