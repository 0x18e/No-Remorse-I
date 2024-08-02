#include "CLogic.h"

CLogic::CLogic() : m_pRenderer(nullptr), m_nWindowHeight(0), m_nWindowWidth(0){

}

CLogic::~CLogic() { 
	
}

void CLogic::Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight) {
	SetRenderer(renderer);
	m_nWindowWidth = WindowWidth;
	m_nWindowHeight = WindowHeight;
	
	
	// Explicit conversion to avoid compiler warnings barking at me
	m_Player.Init(m_pRenderer, "sprites/girl_right.png", Vector2((float)(m_nWindowWidth / 2), (float)(m_nWindowHeight / 2)));
}

void CLogic::SetRenderer( SDL_Renderer* renderer) {

	m_pRenderer = renderer;
}

void CLogic::Update() {
	// more will be added here

	m_Player.Move();
	

	Render();
}

void CLogic::Render(){

	// Clear the background with all white
	SDL_SetRenderDrawColor(m_pRenderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_pRenderer);

	// Rendering entities
	
	m_Player.WeaponHandler(m_pRenderer, m_nWindowWidth, m_nWindowHeight);
	
	m_Player.Render(m_pRenderer);
	
	// Presenting entities
	SDL_RenderPresent(m_pRenderer);
}

// Main games input handler
void CLogic::InputHandler(const SDL_Event& key) {



	// Pass input wherever it is required

	m_Player.InputHandler(key, m_pRenderer);
}





void CLogic::Cleanup()
{
	// Set m_pRenderer to nullptr to avoid dangling pointers
	m_Player.Destroy();
	m_pRenderer = nullptr;
}


