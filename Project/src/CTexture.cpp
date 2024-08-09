#include "CTexture.h"



bool CTextureHandler::LoadTexture(SDL_Renderer* renderer, const char* path, std::string id) {
	//this->Cleanup();
	SDL_Texture* tmp_texture = IMG_LoadTexture(renderer, path);
	if (tmp_texture == nullptr) {
		LOG("SDL could not create texture from IMG: " << IMG_GetError());
		return false;
	}
	else {
		SDL_QueryTexture(tmp_texture, nullptr, nullptr, &m_nWidth, &m_nHeight);
		m_nWidth *= m_nScale;
		m_nHeight *= m_nScale;
		LOG("Texture width and height : " << m_nWidth << ", " << m_nHeight);
	}
	m_Textures[id] = tmp_texture;
	return m_Textures[id] != nullptr;
	
}

void CTextureHandler::RenderTexture(SDL_Renderer* renderer, Vector2 point, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip fliptype) {
	// We subtract the 2 points with their texture widths in order to center them
	SDL_Rect Rendering_Area { (int)point.x - m_nWidth/2, (int)point.y - m_nHeight/2, m_nWidth, m_nHeight};
	if (clip != nullptr) {
		Rendering_Area.h = clip->h;
		Rendering_Area.w = clip->w;
	}
	SDL_RenderCopyEx(renderer, m_CurrentTexture, nullptr, &Rendering_Area, angle, center, fliptype);
}

void CTextureHandler::SetCurrentTexture(std::string id) {
	m_CurrentTexture = m_Textures[id];
	SDL_QueryTexture(m_CurrentTexture, nullptr, nullptr, &m_nWidth, &m_nHeight);
	m_nWidth *= m_nScale;
	m_nHeight *= m_nScale;
}







void CTextureHandler::SetScale(int scale) {
	m_nScale = scale;
	m_nWidth *= m_nScale;
	m_nHeight *= m_nScale;
}

void CTextureHandler::Cleanup() {
	for (auto value : m_Textures) {
		if (value.second != nullptr) {
			SDL_DestroyTexture(value.second);
			LOG("Destroyed " << value.first);
			value.second = nullptr;
		}
	}
	m_Textures.clear();
	if (m_CurrentTexture != nullptr) {
		SDL_DestroyTexture(m_CurrentTexture);
		m_CurrentTexture = nullptr;
		m_nWidth = 0;
		m_nHeight = 0;
	}

}

CTextureHandler::~CTextureHandler() {

}
