#include "CSoundManager.h"


CSoundManager CSoundManager::m_sInstance;

bool CSoundManager::Init() {
	bool flag = true;

	// Load audio files

	m_pShoot = Mix_LoadWAV("sound/shootsound.wav");
	m_pShoot->volume = 30;
	if (m_pShoot == nullptr) {
		LOG("Failed to load shootsound audio effect " << Mix_GetError());
		flag = false;
	}
	m_pSounds["pistol_shoot"] = m_pShoot;
	
	m_pEnemyHit = Mix_LoadWAV("sound/hitsoundenemy.wav");
	m_pEnemyHit->volume = 30;
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
	
	m_pShootShotgun = Mix_LoadWAV("sound/shotgunsound.wav");
	m_pShootShotgun->volume = 30;
	if (m_pShootShotgun == nullptr) {
		LOG("Failed to load shotgunsound.wav " << Mix_GetError());
		flag = false;
	}
	m_pSounds["shotgun_shoot"] = m_pShootShotgun;
	

	m_pWeaponSwap = Mix_LoadWAV("sound/swap1.wav");

	if (m_pWeaponSwap == nullptr) {
		LOG("Failed to load weapon swap sound " << Mix_GetError());
		flag = false;
	}
	m_pSounds["weapon_swap"] = m_pWeaponSwap;

	return flag;
}

void CSoundManager::PlaySound(std::string sound) {
	int check = Mix_PlayChannel(-1, m_pSounds[sound], 0);
	if (check < 0) {
		LOG("Could not play " << sound);
	}
}

CSoundManager::~CSoundManager() {
	// Destroy all loaded sounds
	for (auto sound : m_pSounds) {
		if (sound.second != nullptr) {
			Mix_FreeChunk(sound.second);
			sound.second = nullptr;
		}
	}
	m_pSounds.clear();
}
