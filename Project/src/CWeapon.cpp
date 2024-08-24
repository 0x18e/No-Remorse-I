#include "CWeapon.h"

void CWeapon::Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position) {
	// Default shooting
	CBullet* bullet = new CBullet;
	// make shooting both fire rate and spam, make spam rewarding :D
	bullet->Init(renderer, "sprites/small_gun_bullet.png", player_angle, player_position);

	Vector2 mouse_position = GetMousePosition();
	mouse_position += Vector2(GetRandomNumber(-m_fWeaponAccuracy, m_fWeaponAccuracy), GetRandomNumber(-m_fWeaponAccuracy, m_fWeaponAccuracy)); // add inacuraccy
	
	Vector2 direction_vector = UnitVector(mouse_position - player_position);
	bullet->SetSpeed(m_fWeaponSpeed);
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

void CWeapon::SetAccuracy(float accuracy) {
	this->m_fWeaponAccuracy = accuracy;
}


Vector2 CWeapon::GetMousePosition() {
	SDL_GetMouseState(&m_MouseX, &m_MouseY);
	return Vector2(m_MouseX, m_MouseY);
}

void CPistol::Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position) {
	CBullet* bullet = new CBullet;
	// make shooting both fire rate and spam, make spam rewarding :D
	bullet->Init(renderer, "sprites/small_gun_bullet.png", player_angle, player_position);

	Vector2 mouse_position = GetMousePosition();
	// add inacuraccy
	mouse_position += Vector2(GetRandomNumber(-m_fWeaponAccuracy, m_fWeaponAccuracy), GetRandomNumber(-m_fWeaponAccuracy, m_fWeaponAccuracy));

	Vector2 direction_vector = UnitVector(mouse_position - player_position);
	bullet->SetSpeed(m_fWeaponSpeed);
	bullet->SetBulletVelocity(direction_vector);

	m_Bullets.push_back(bullet);
}

void CShotgun::Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position) {
	for (int i = 0; i < m_nPelletCount; ++i) {
		SetAccuracy(70); // less is better
		CBullet* bullet = new CBullet;
		bullet->Init(renderer, "sprites/small_gun_bullet.png", player_angle, player_position);
		Vector2 mouse_position = GetMousePosition();
		// add inacuraccy
		mouse_position += Vector2(GetRandomNumber(-m_fWeaponAccuracy, m_fWeaponAccuracy), GetRandomNumber(-m_fWeaponAccuracy, m_fWeaponAccuracy));

		Vector2 direction_vector = UnitVector(mouse_position - player_position);
		bullet->SetSpeed(m_fWeaponSpeed);
		bullet->SetBulletVelocity(direction_vector);
		m_Bullets.push_back(bullet);
	}
	
}



CWeaponHandler::CWeaponHandler() {

}

CWeaponHandler::~CWeaponHandler() {
	for (int i = 0; i < 2; ++i) {
		arr[i]->Cleanup();
		arr[i] = nullptr;
	}
}

void CWeaponHandler::Init() {
	arr[0] = &m_Pistol;
	arr[1] = &m_Shotgun;
}

int CWeaponHandler::GetCurrentWeapon() {
	return m_CurrentWeapon;
}

void CWeaponHandler::ShootCurrentWeapon(SDL_Renderer* renderer, double player_angle, Vector2 player_position) {
	if (m_CurrentWeapon == PISTOL) {
		CSoundManager::Get().PlaySound("pistol_shoot");
	}
	if (m_CurrentWeapon == SHOTGUN) {
		CSoundManager::Get().PlaySound("shotgun_shoot");
	}
	arr[m_CurrentWeapon]->Shoot(renderer, player_angle, player_position);
}

void CWeaponHandler::SwapWeapon() {
	LOG("previous weapon index " << m_CurrentWeapon);
	CSoundManager::Get().PlaySound("weapon_swap");
	m_CurrentWeapon = !m_CurrentWeapon;
	LOG(m_CurrentWeapon);
}

void CWeaponHandler::RenderBullets(SDL_Renderer* renderer) {
	arr[m_CurrentWeapon]->RenderBullets(renderer);
}

void CWeaponHandler::UpdateBullets(int windowx, int windowy, const float& dt) {
	arr[m_CurrentWeapon]->UpdateBullets(windowx, windowy, dt);
}

std::vector<CBullet*> CWeaponHandler::GetBullets() {
	return arr[m_CurrentWeapon]->GetBullets();
}
