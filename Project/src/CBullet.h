#pragma once
#include "CEntity.h"

class CBullet : public CEntity {
private:
	float m_BulletSpeed=1000.0f;
	bool m_KillFlag = false; // Tells the bullet whether its dead or not
	
public:
	void Init(SDL_Renderer* renderer, const char* texture_path, double angle, Vector2 initial_pos);
	
	void SetBulletVelocity(Vector2 vector);
	void SetBulletSpeed(float bullet_speed);
	bool IsOffScreen(int windowx, int windowy);
	void UpdatePosition(float dt);
	void SetKillFlag(bool is_dead);
	bool GetKillFlag() { return m_KillFlag; }
	void Cleanup();
	
};