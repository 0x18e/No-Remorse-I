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
    // Define a scale factor for the collision box (e.g., 0.8 for 80% size)
    float scaleFactor = 0.6f;

    // Get the dimensions and position of this entity and the collider
    Vector2 collider_dimensions = collider.GetDimensions();
    Vector2 collider_position = collider.GetPosition();

    // Calculate the reduced dimensions of the collision boxes
    Vector2 reducedDimensions = GetDimensions() * scaleFactor;
    Vector2 collider_reducedDimensions = collider_dimensions * scaleFactor;

    // Calculate the position offset to center the smaller collision box within the entity
    Vector2 positionOffset = (GetDimensions() - reducedDimensions) / 2.0f;
    Vector2 collider_positionOffset = (collider_dimensions - collider_reducedDimensions) / 2.0f;

    // Calculate the new positions for the smaller collision boxes
    Vector2 this_reducedPosition = m_Position + positionOffset;
    Vector2 collider_reducedPosition = collider_position + collider_positionOffset;

    // Check if the reduced bounding boxes overlap
    return (this_reducedPosition.x < collider_reducedPosition.x + collider_reducedDimensions.x &&
        this_reducedPosition.x + reducedDimensions.x > collider_reducedPosition.x &&
        this_reducedPosition.y < collider_reducedPosition.y + collider_reducedDimensions.y &&
        this_reducedPosition.y + reducedDimensions.y > collider_reducedPosition.y);

}

void CEntity::SetScale(int scale){
    this->m_nScale = scale;
    m_EntityTexture.SetScale(m_nScale);
}

float CEntity::GetScale() {
    return m_nScale;
}


