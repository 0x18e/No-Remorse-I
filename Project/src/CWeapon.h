#pragma once
#include "CTexture.h"
#include "CEntity.h"
#include<vector>
#include "CBullet.h"
#include "CEnemies.h"
#include "Utilities.h"


// Will do for now.
class CWeapon {

private:
	std::vector<CBullet*> m_Bullets;
	Vector2 GetMousePosition();
	int m_MouseX = 0;
	int m_MouseY = 0;
	float m_fWeaponSpeed = 750.0f;
public:

	std::vector<CBullet*> GetBullets() { return m_Bullets; }
	void Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position);
	void SetWeaponSpeed(float speed);
	void Cleanup();
	void UpdateBullets(int windowx, int windowy, const float& dt);
	void RenderBullets(SDL_Renderer* renderer);
};


class CPistol : public CWeapon {

};

class CShotgun : public CWeapon {

};



