#include "CEngine.h"

CEngine::CEngine() {
	
}

bool CEngine::Initialize(){
	// This is where all the initializing happens
	// Initializations such as renderer creations, SDL, SDL_IMG initializations, etc
	
	

	bool SDLCheck = m_SDLManager.InitSDL();
	bool WindowCheck = m_Window.CreateWindow("Lorem Ipsum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_nWindowWidth, m_nWindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	bool RendererCheck = m_Renderer.Initialize(m_Window.GetWindow());
	m_GameLogic.Init(m_Renderer.GetRenderer(), m_nWindowWidth, m_nWindowHeight);
	
	return SDLCheck && WindowCheck && RendererCheck;
}

void CEngine::Run() {
	
	SDL_Event event;
	m_MainClock.Start();
	// temp code
	Clock fps_timer;
	fps_timer.Start();
	int counted_frames = 0;
	float avgFps = 0;
	// Main game loop
	while (b_isRunning) {

		m_fDeltaTime = m_MainClock.GetTicks() / 1000.f; // Time in seconds
		

		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				b_isRunning = false;
				
				break;
			// Debug Keys
			
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_f) {
					std::cout << avgFps << "\n";
				}
				break;
			
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
					SDL_GetWindowSize(m_Window.GetWindow(), &m_nWindowWidth, &m_nWindowHeight);
					m_Window.ChangeWindowSize(m_nWindowWidth, m_nWindowHeight);
					m_GameLogic.AdjustResolution(m_nWindowWidth, m_nWindowHeight);
					LOG("Changing resolution");
				}
				break;
			default:
				break;
			}
			m_GameLogic.InputHandler(event);
		}
		// temp code
		avgFps = counted_frames / (fps_timer.GetTicks() / 1000.f);
		if (avgFps > 2000000)
		{
			avgFps = 0;
		}


		// end of temp
		m_GameLogic.Update(m_fDeltaTime);
		
		// Reset clock to account for delta time, might change this clock to be game clock.
		m_MainClock.Start();

		m_GameLogic.Render();
		
		// temp
		++counted_frames;
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
