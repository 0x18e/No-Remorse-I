#include "CSoundManager.h"


CSoundManager CSoundManager::m_sInstance;

bool CSoundManager::Init() {
	bool flag = true;

	// Load audio files

	m_pShoot = Mix_LoadWAV("sound/shootsound.wav");
	if (m_pShoot == nullptr) {
		LOG("Failed to load shootsound audio effect " << Mix_GetError());
		flag = false;
	}
	m_pSounds["shoot"] = m_pShoot;

	m_pEnemyHit = Mix_LoadWAV("sound/hitsoundenemy.wav");

	if (m_pEnemyHit == nullptr) {
		LOG("Failed to load hitsoundenemy audio effect " << Mix_GetError());
		flag = false;
	}
	m_pSounds["enemy_hit"] = m_pEnemyHit;

	m_pEnemyDie = Mix_LoadWAV("sound/enemydeathsound.wav");
	if (m_pEnemyDie == nullptr) {
		LOG("Failed to load enemydeathsound.wav " << Mix_GetError());
		flag = false;
	}
	m_pSounds["enemy_death"] = m_pEnemyDie;

	return flag;
}

void CSoundManager::PlaySound(std::string sound) {
	Mix_PlayChannel(-1, m_pSounds[sound], 0);
}

CSoundManager::~CSoundManager() {
	// Destroy all loaded sounds
	for (auto sound : m_pSounds) {
		if (sound.second != nullptr) {
			Mix_FreeChunk(sound.second);
			//LOG("Destroyed " << value.first << " animation");
			sound.second = nullptr;
		}
	}
	m_pSounds.clear();

}
