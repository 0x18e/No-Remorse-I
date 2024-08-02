#pragma once
#include "Utilities.h"
#include "CSDLManager.h"
#include "CWindowHandler.h"
#include "CRenderer.h"
#include "CLogic.h"

class CEngine {
private:
	bool b_isRunning = true;
	
	CSDLManager m_SDLManager;
	CRenderer m_Renderer;
	CWindowHandler m_Window;
	CLogic m_GameLogic;

	int m_nWindowWidth = 1280;
	int m_nWindowHeight = 800;
	
public:
	CEngine();
	~CEngine();
	bool Initialize();
	void Run();
	void Shutdown();



};