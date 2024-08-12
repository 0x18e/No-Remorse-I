#pragma once
#include "Utilities.h"
#include<SDL.h>
#include "CBasePlayer.h"
#include "CEnemies.h"

class CLogic {
	
private:
	
	SDL_Renderer* m_pRenderer;
	CBasePlayer m_Player;
	Vector2 m_Camera;
	

	// Create a vector that will store all the entities
	std::vector<CEntity*> m_pEntities;
	std::vector<CEnemy*> m_pEnemies;
	// Set local window widths and heights
	int m_nWindowWidth;
	int m_nWindowHeight;
public:
	CLogic();
	~CLogic();
	
	void Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight);


	// Will set the class renderer that will be continuously passed around
	void SetRenderer(SDL_Renderer *renderer);
	void AdjustResolution(int x, int y);


	

	// Core functions
	void Update(float dt);
	void Render();
	void Cleanup();
	void InputHandler(const SDL_Event &key);
};