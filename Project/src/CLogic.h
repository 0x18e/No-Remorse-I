#pragma once
#include "Utilities.h"
#include<SDL.h>
#include "CBasePlayer.h"


class CLogic {
	
private:
	
	SDL_Renderer* m_pRenderer;
	CBasePlayer m_Player;

	// Set local window widths and heights
	int m_nWindowWidth;
	int m_nWindowHeight;
public:
	CLogic();
	~CLogic();
	
	void Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight);


	// Will set the class renderer that will be continuously passed around
	void SetRenderer(SDL_Renderer *renderer);

	

	// Core functions
	void Update();
	void Render();
	void Cleanup();
	void InputHandler(const SDL_Event &key);
};