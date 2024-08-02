#pragma once
#include "CTexture.h"
#include "CEntity.h"
#include<vector>
#include "CBullet.h"


// Will do for now.
class CWeapon {

private:
	std::vector<CBullet*> m_Bullets;
	Vector2 GetMousePosition();
	int m_MouseX = 0;
	int m_MouseY = 0;
	float m_BulletSpeed = 6.0f;
public:


	void Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position);
	void Cleanup();
	void UpdateBullets(SDL_Renderer* renderer, int windowx, int windowy);
};






