#pragma once
#include<SDL_mixer.h>
#include "Utilities.h"
#include <map>
#include <string>

// This will be a singleton
class CSoundManager {
public:
	static CSoundManager& Get() {
		return m_sInstance;
	}
	Mix_Chunk* m_pShoot;
	Mix_Chunk* m_pEnemyDie;
	Mix_Chunk* m_pEnemyHit;
	Mix_Chunk* m_pShootShotgun;
	Mix_Chunk* m_pWeaponSwap;
	std::map<std::string, Mix_Chunk*> m_pSounds;

	bool Init();
	void PlaySound(std::string sound);
private:
	CSoundManager() : m_pShoot(nullptr), m_pEnemyDie(nullptr), m_pEnemyHit(nullptr) {}
	~CSoundManager();
	static CSoundManager m_sInstance;

};