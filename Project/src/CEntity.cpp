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
	if (this->m_Position.x + this->GetDimensions().x < collider.GetPosition().x ||
		this->m_Position.x > collider.GetPosition().x + collider.GetDimensions().x ||
		this->GetPosition().y + this->GetDimensions().y < collider.GetPosition().y ||
		this->GetPosition().y > collider.GetPosition().y + collider.GetDimensions().y) {

		return false;
	}
	return true;
}

void CEntity::SetScale(int scale){
    this->m_nScale = scale;
    m_EntityTexture.SetScale(m_nScale);
}

float CEntity::GetScale() {
    return m_nScale;
}


