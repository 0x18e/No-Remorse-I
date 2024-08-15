#include "CBullet.h"

void CBullet::Init(SDL_Renderer* renderer, const char* texture_path, double angle, Vector2 initial_pos) {
	m_EntityTexture.LoadTexture(renderer, texture_path, "m_bullet");
	m_EntityTexture.SetCurrentTexture("m_bullet");
	m_EntityTexture.SetScale(6);
	m_fImpactForce = 10;
	m_Position = initial_pos;
	m_dAngle = angle;
}

void CBullet::SetBulletVelocity(Vector2 vector) {
	m_Velocity = vector * m_BulletSpeed;
}

void  CBullet::SetImpactForce(float force) {
	this->m_fImpactForce = force;
	
}

void CBullet::SetSpeed(float bullet_speed) {
	this->m_BulletSpeed = bullet_speed;
}



void CBullet::SetDamage(float bullet_damage) {
	m_fBulletDamage = bullet_damage;
}

void CBullet::UpdatePosition(float dt) {
	m_Position += m_Velocity * dt;
}

void CBullet::SetKillFlag(bool is_dead) {
	m_KillFlag = true;
}

bool CBullet::IsOffScreen(int windowx, int windowy) {
	if (m_Position.x < 0 || m_Position.x > windowx || m_Position.y < 0 || m_Position.y > windowy) {
		return true;
	}
	return false;
}

// Inefficient, find a way to call CEntity's destructor
void CBullet::Cleanup() {
	this->m_EntityTexture.Cleanup();
}