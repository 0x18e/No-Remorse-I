#pragma once
#include "CEntity.h"

class CBullet : public CEntity {
private:
	float m_BulletSpeed=2.0f;
	
public:
	void Init(SDL_Renderer* renderer, const char* texture_path, double angle, Vector2 initial_pos);
	
	void SetBulletVelocity(Vector2 vector);
	void SetBulletSpeed(float bullet_speed);
	bool IsOffScreen(int windowx, int windowy);
	void UpdatePosition();
	void Cleanup();
	
};