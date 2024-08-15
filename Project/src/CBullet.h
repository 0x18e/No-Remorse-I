#pragma once
#include "CEntity.h"

class CBullet : public CEntity {
private:
	float m_BulletSpeed=1000.0f;
	bool m_KillFlag = false; // Tells the bullet whether its dead or not
	float m_fImpactForce = 0;
	float m_fBulletDamage = 15;
	
public:
	void Init(SDL_Renderer* renderer, const char* texture_path, double angle, Vector2 initial_pos);
	
	void SetBulletVelocity(Vector2 vector);
	float GetImpactForce() { return m_fImpactForce; }
	void SetImpactForce(float force);
	void SetSpeed(float bullet_speed);
	void SetDamage(float bullet_damage);
	float GetDamage() { return m_fBulletDamage; }
	bool IsOffScreen(int windowx, int windowy);
	void UpdatePosition(float dt);
	void SetKillFlag(bool is_dead);
	bool GetKillFlag() { return m_KillFlag; }
	void Cleanup();
	
};