#include "CEntity.h"
#include "CEngine.h"


CEntity::~CEntity() {

	m_EntityTexture.Cleanup();
	LOG("Entity Cleaned");
}


void CEntity::Render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Point* center, SDL_RendererFlip fliptype){
	
	m_EntityTexture.RenderTexture(renderer, m_Position, nullptr, m_dAngle, center, fliptype);
}
