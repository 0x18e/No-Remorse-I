#include "CEntity.h"
#include "CEngine.h"


CEntity::~CEntity() {


	// Deleting a derived class does not call this function
	m_EntityTexture.Cleanup();
}


void CEntity::Render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Point* center, SDL_RendererFlip fliptype){
	
	m_EntityTexture.RenderTexture(renderer, m_Position, nullptr, m_dAngle, center, fliptype);
}

void CEntity::AdjustForResolution(Vector2 newres, Vector2 oldres) {
	/*
	float calcx = (newres.x * m_Position.x) / oldres.x;
	float calcy = (newres.y * m_Position.y) / oldres.y;
	this->m_Position.x = calcx;
	this->m_Position.y = calcy;
	*/
	this->m_Position = (newres * m_Position) / oldres;
}


bool CEntity::IsCollided(CEntity &collider)
{
	// Check the m_CollisionBox with collider to see if they collided
	// We use SAT for simple collision
	Vector2 collider_dimensions = collider.GetDimensions();
	Vector2 collider_position = collider.GetPosition();
	return (m_Position.x < collider_position.x + collider_dimensions.x &&
		m_Position.x + this->GetDimensions().x > collider_position.x &&
		m_Position.y < collider_position.y + collider_dimensions.y &&
		m_Position.y + m_Position.y > collider_position.y);


}
