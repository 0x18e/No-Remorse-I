#include "CWeapon.h"

void CWeapon::Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position) {
	CBullet* bullet = new CBullet;
	
	bullet->Init(renderer, "sprites/small_gun_bullet.png", player_angle, player_position);

	
	Vector2 mouse_position = GetMousePosition();
	mouse_position += Vector2(GetRandomNumber(-20, 20), GetRandomNumber(-20, 20)); // add inacuraccy
	
	Vector2 direction_vector = UnitVector(mouse_position - player_position);
	bullet->SetBulletSpeed(m_fWeaponSpeed);
	bullet->SetBulletVelocity(direction_vector);
	
	m_Bullets.push_back(bullet);
}

void CWeapon::Cleanup() {
	for (size_t i = 0; i < m_Bullets.size(); ++i) {
		m_Bullets[i]->Cleanup();
		delete m_Bullets[i];
	}
}

void CWeapon::UpdateBullets(int windowx, int windowy, const float& dt) {
	for (size_t bullet = 0; bullet < m_Bullets.size(); ++bullet) {
		m_Bullets[bullet]->UpdatePosition(dt);
		/*
		for (size_t enem = 0; enem < enemies.size(); ++enem) {
			if (m_Bullets[bullet]->IsCollided(*enemies[bullet])){ // enemies[enem]->IsCollided(*m_Bullets[bullet] {

				
				enemies[enem]->Cleanup();
				std::vector<CEnemy*>::iterator enemy_iterator = enemies.begin();
				std::advance(enemy_iterator, enem);
				enemies.erase(enemy_iterator);


				m_Bullets[bullet]->SetKillFlag(true);
				
			}

		}
		*/
		if (m_Bullets[bullet]->IsOffScreen(windowx, windowy) || m_Bullets[bullet]->GetKillFlag()) {
			m_Bullets[bullet]->Cleanup();
			std::vector<CBullet*>::iterator it = m_Bullets.begin();
			std::advance(it, bullet);
			m_Bullets.erase(it);
			
		}
	}
}
void CWeapon::RenderBullets(SDL_Renderer* renderer) {
	for (size_t bullet = 0; bullet < m_Bullets.size(); ++bullet) {
		m_Bullets[bullet]->Render(renderer);
	}
}

void CWeapon::SetWeaponSpeed(float speed) {
	m_fWeaponSpeed = speed;
}


Vector2 CWeapon::GetMousePosition() {
	SDL_GetMouseState(&m_MouseX, &m_MouseY);
	return Vector2(m_MouseX, m_MouseY);
}
