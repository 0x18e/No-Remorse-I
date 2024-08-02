#include "CEngine.h"

CEngine::CEngine() {
	
}

bool CEngine::Initialize(){
	// This is where all the initializing happens
	// Initializations such as renderer creations, SDL, SDL_IMG initializations, etc
	
	

	bool SDLCheck = m_SDLManager.InitSDL();
	bool WindowCheck = m_Window.CreateWindow("Lorem Ipsum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_nWindowWidth, m_nWindowHeight, SDL_WINDOW_SHOWN);
	bool RendererCheck = m_Renderer.Initialize(m_Window.GetWindow());
	m_GameLogic.Init(m_Renderer.GetRenderer(), m_nWindowWidth, m_nWindowHeight);
	
	return SDLCheck && WindowCheck && RendererCheck;
}

void CEngine::Run() {
	
	SDL_Event event;
	// Main game loop
	while (b_isRunning) {

		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				b_isRunning = false;
				
				break;
			

			default:
				break;
			}
			m_GameLogic.InputHandler(event);
		}
		
		m_GameLogic.Update();

	}
}

void CEngine::Shutdown() {
	m_GameLogic.Cleanup();
	m_Renderer.Cleanup();
	m_Window.Cleanup();
	m_SDLManager.Quit();
}

CEngine::~CEngine(){
	
}
