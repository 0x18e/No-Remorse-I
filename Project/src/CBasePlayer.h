#pragma once
#include<SDL.h>
#include "Utilities.h"
#include "CEntity.h"
#include "CWeapon.h"
#include <map>

class CBasePlayer : public CEntity {
private:
	float m_PlayerSpeed = 2;
	int m_nMousePositionX = 0;
	int m_nMousePositionY = 0;
	CWeapon m_Gun;
	


	
	struct DIRECTIONS {
		int UP = 0;
		int DOWN = 0;
		int LEFT = 0;
		int RIGHT = 0;
	} m_MovementDirection;

public:
	CBasePlayer();
	~CBasePlayer();

	void Init(SDL_Renderer* renderer, const char* path_to_texture, Vector2 initial_position);
	

	

	void WeaponHandler(SDL_Renderer* renderer, int windowx, int windowy);
	void InputHandler(const SDL_Event& key, SDL_Renderer* renderer);
	void Move();
	void HandleRotation();
	void Destroy();

};