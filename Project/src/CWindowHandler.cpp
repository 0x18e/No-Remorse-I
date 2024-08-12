#include "CWindowHandler.h"




CWindowHandler::~CWindowHandler() {
	// Nothing here
}

void CWindowHandler::Cleanup(){
	// If m_pWindow is not null, we destroy it, and then make sure m_pWindow doesn't point to anything
	
	LOG("Destroying window");
	SDL_DestroyWindow(this->m_pWindow);
	this->m_pWindow = nullptr;
	
}


void CWindowHandler::ChangeWindowSize(int x, int y) {
	// In the case where the window's size changes, we adjust the window size
	SDL_SetWindowSize(m_pWindow, x, y);
}

bool CWindowHandler::CreateWindow(const char* window_title, int x, int y, int w, int h, int SDL_Flags) {
	bool b_Flag = true;
	m_pWindow = SDL_CreateWindow(window_title, x, y, w, h, SDL_Flags);
	m_nWindowWidth = w;
	m_nWindowHeight = h;
	if (m_pWindow == nullptr) {
		LOG("Could not create SDL_Window " << SDL_GetError());
		b_Flag = false;
	}

	return b_Flag;
}

