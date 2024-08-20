#pragma once
#include "CEntity.h"
class CFlashlight : public CEntity {
private:
	SDL_Texture* m_FlashlightTexture;
	Vector2 m_LightOffset;
	Vector2 m_PlayerDimensions;
	float m_fRatioScale;
public:
	void Init(SDL_Renderer* renderer, Vector2 initial_pos, Vector2 player_dimensions, int player_scale);
	void RenderFlashlight(SDL_Renderer* renderer, Vector2 player_position, Vector2 player_dimensions, float angle);
	CEntity& GetCollider() { return *this; }

};