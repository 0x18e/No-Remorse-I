#pragma once
#include "Utilities.h"
#include "CSDLManager.h"
#include "CWindowHandler.h"
#include "CRenderer.h"
#include "CLogic.h"
#include "Clock.h"

class CEngine {
private:
	bool b_isRunning = true;
	
	CSDLManager m_SDLManager;
	CRenderer m_Renderer;
	CWindowHandler m_Window;
	// All of the games logic will be stored here
	CLogic m_GameLogic;

	// Main games clock
	Clock m_MainClock;
	// Variable to hold time elapsed between each frame
	float m_fDeltaTime;

	int m_nWindowWidth = 1280;
	int m_nWindowHeight = 800;
	
public:
	CEngine();
	~CEngine();
	bool Initialize();
	void Run();
	void Shutdown();



};