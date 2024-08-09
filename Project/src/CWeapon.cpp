#include "CWeapon.h"

void CWeapon::Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position) {
	CBullet* bullet = new CBullet;
	
	bullet->Init(renderer, "sprites/small_gun_bullet.png", player_angle, player_position);

	
	Vector2 mouse_position = GetMousePosition();

	Vector2 direction_vector = UnitVector(mouse_position - player_position);
	bullet->SetBulletSpeed(m_BulletSpeed);
	bullet->SetBulletVelocity(direction_vector);
	
	m_Bullets.push_back(bullet);
}

void CWeapon::Cleanup() {
	for (size_t i = 0; i < m_Bullets.size(); ++i) {
		m_Bullets[i]->Cleanup();
		delete m_Bullets[i];
	}

}

void CWeapon::UpdateBullets(SDL_Renderer *renderer, int windowx, int windowy) {
	for (size_t bullet = 0; bullet < m_Bullets.size(); ++bullet) {
		m_Bullets[bullet]->UpdatePosition();
		m_Bullets[bullet]->Render(renderer);
		if (m_Bullets[bullet]->IsOffScreen(windowx, windowy)) {
			m_Bullets[bullet]->Cleanup();
			std::vector<CBullet*>::iterator it = m_Bullets.begin();
			std::advance(it, bullet);
			m_Bullets.erase(it);
			
		}
	}
}
Vector2 CWeapon::GetMousePosition() {
	SDL_GetMouseState(&m_MouseX, &m_MouseY);
	return Vector2(m_MouseX, m_MouseY);
}
