#pragma once
#include<SDL.h>
#include "Utilities.h"


// This might be a singleton in order to pass the renderer all throughout the program
class CRenderer {

private:
	SDL_Renderer* m_pRenderer;
public:
	CRenderer();
	~CRenderer();
	bool Initialize(SDL_Window *window);
	SDL_Renderer* GetRenderer() { return m_pRenderer; };
	void Cleanup();
};