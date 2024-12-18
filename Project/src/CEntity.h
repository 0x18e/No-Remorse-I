#pragma once
#include "CTexture.h"
#include "Utilities.h"

class CEntity {
protected:
	CTextureHandler m_EntityTexture;
	Vector2 m_Position;
	Vector2 m_Velocity;
	Vector2 m_CollisionBox; // maybe remove
	std::string id;
	double m_dAngle;
	float m_nScale;
public:
	CEntity() : m_Position(0, 0), m_Velocity(0, 0), m_nScale(1), m_dAngle(0.0) {} ;
	~CEntity();

	void Render(SDL_Renderer* renderer, SDL_Rect* clip = nullptr, SDL_Point* center = nullptr, SDL_RendererFlip fliptype = SDL_RendererFlip::SDL_FLIP_NONE);
	void AdjustForResolution(Vector2 newres, Vector2 oldres);
	
	bool IsCollided(CEntity &collider);
	void SetScale(float scale);
	float GetScale();
	
	
	// Define in .cpp later
	Vector2 GetPosition() { return m_Position; };
	Vector2 GetDimensions() { return Vector2(m_EntityTexture.GetWidth(), m_EntityTexture.GetHeight()); };

	
};