#include "CSDLManager.h"


CSDLManager::CSDLManager() {
	
}

bool CSDLManager::InitSDL(){

	bool bFlag = true;
	int SDL_InitFlags = SDL_INIT_VIDEO | SDL_INIT_AUDIO;
	int IMG_InitFlags = IMG_INIT_PNG;
	if (SDL_Init(SDL_InitFlags) == -1) {
		
		LOG("Could not initialize SDL " << SDL_GetError());
		return false;
	}
	else {
		LOG("SDL initialized");
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0")) {
			LOG("Nearest texture filtering is not enabled!");
		}
		if (!IMG_Init(IMG_InitFlags)) {
			LOG("Could not initialize SDL_Image: " << IMG_GetError());
			return false;
		}
		else {
			LOG("SDL_Image initialized");
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			LOG("Could not initialize SDL_mixer: " << Mix_GetError());
			return false;
		}
		else {
			LOG("SDL_mixer.h initialized");
		}
	}

	return bFlag;

}

void CSDLManager::Quit(){
	
	Mix_Quit();
	LOG("SDL_Mixer Quit");
	IMG_Quit();
	LOG("SDL_IMG Quit");
	SDL_Quit();
	LOG("SDL Quit");
}

CSDLManager::~CSDLManager(){
	
}


