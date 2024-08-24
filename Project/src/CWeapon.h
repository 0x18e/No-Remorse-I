#pragma once
#include "CTexture.h"
#include "CEntity.h"
#include<vector>
#include "CBullet.h"
#include "CEnemies.h"
#include "Utilities.h"
#include "CSoundManager.h"


// Will do for now.
class CWeapon {

protected:
	std::vector<CBullet*> m_Bullets;
	Vector2 GetMousePosition();
	int m_MouseX = 0;
	int m_MouseY = 0;
	float m_fWeaponSpeed = 750.0f;
	float m_fWeaponAccuracy = 10;

public:
	const std::vector<CBullet*> GetBullets() { return m_Bullets; }
	virtual void Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position);
	void SetWeaponSpeed(float speed);
	void SetAccuracy(float accuracy);
	void Cleanup();
	void UpdateBullets(int windowx, int windowy, const float& dt);
	void RenderBullets(SDL_Renderer* renderer);
};


class CPistol : public CWeapon {

public:
	// Override shooting for a pistol
	void Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position) override;

};

class CShotgun : public CWeapon {
private:
	int m_nPelletCount = 5;
public:
	void Shoot(SDL_Renderer* renderer, double player_angle, Vector2 player_position) override;
};

enum WEAPONS {
	PISTOL,
	SHOTGUN
};
class CWeaponHandler {
private:
	CShotgun m_Shotgun;
	CPistol m_Pistol;
	CWeapon *arr[2];
	bool m_CurrentWeapon = PISTOL;


public:
	// This function will shoot whatever the current weapon that is held is
	CWeaponHandler();
	~CWeaponHandler();



	void Init();
	int GetCurrentWeapon();
	void ShootCurrentWeapon(SDL_Renderer *renderer, double player_angle, Vector2 player_position);
	void SwapWeapon();
	void RenderBullets(SDL_Renderer* renderer);
	void UpdateBullets(int windowx, int windowy, const float& dt);
	std::vector<CBullet*> GetBullets();
};



