#include "CLogic.h"

CLogic::CLogic() : m_pRenderer(nullptr), m_nWindowHeight(0), m_nWindowWidth(0) {

}

CLogic::~CLogic() { 
	
}

void CLogic::Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight) {
	SetRenderer(renderer);
	m_nWindowWidth = WindowWidth;
	m_nWindowHeight = WindowHeight;

	// Explicit conversion to avoid compiler warnings barking at me
	m_Player.Init(m_pRenderer, "sprites/girl_right.png", Vector2((float)(m_nWindowWidth / 2), (float)(m_nWindowHeight / 2)));
	
	// Create initial enemies
	CZombie* zombie = new CZombie;
	zombie->InitializeZombie(m_pRenderer, Vector2(m_nWindowWidth / 4, m_nWindowHeight / 4));
	for (int i = 0; i < 5; ++i) {
		CMediumZombie* z = new CMediumZombie;
		z->InitializeZombie(m_pRenderer, Vector2(GetRandomNumber(0, m_nWindowWidth), GetRandomNumber(0, m_nWindowHeight)));
		m_pEnemies.push_back(z);
		m_pEntities.push_back(z);
		//z->SetScale(1.5);
	}
	m_pEntities.push_back(zombie);
	m_pEnemies.push_back(zombie);
	
}

void CLogic::SetRenderer( SDL_Renderer* renderer) {
	m_pRenderer = renderer;
}

void CLogic::Update(float dt) {
	// more will be added here

	m_Player.Move(dt, m_Camera);
	
	m_Player.WeaponUpdate(m_nWindowWidth, m_nWindowHeight, dt);

	for (size_t it = 0; it < m_pEnemies.size(); ++it) {
		
	
		if (m_pEnemies[it]->IsAlive()) {
			m_pEnemies[it]->ChasePlayer(m_Player.GetPosition());
			m_pEnemies[it]->Update(dt);
		}
		else {
			// LAZY CODE FIX LATER
			m_pEnemies[it]->Die();
		}
		if (m_pEnemies[it]->IsCollided(m_Player)) {
			LOG("hit player");
		}
		// use flashlight function to check for collision with enemies
		if (m_Player.CheckFlashlightVisibility(*m_pEnemies[it])) {
			m_pEnemies[it]->SetVisibility(true);
		}
		else {
			m_pEnemies[it]->SetVisibility(false);
		}
	}

	// Collision Checks will be changed later on to use quadtrees instead
	if (m_Player.GetWeaponBullets().size() > 0) {
		for (CBullet* bullet : m_Player.GetWeaponBullets()) {
			bullet->SetScale(1.1);
			for (CEnemy* enemy : m_pEnemies) {
				if (enemy->IsAlive() != false) {
					if (bullet->IsCollided(*enemy)) {
						LOG("Hit");
						enemy->TakeDamage(bullet->GetDamage()); // arbitrary random number i chose, this will be replaced with bullet damage
						enemy->KnockBack(Vector2(bullet->GetImpactForce(), bullet->GetImpactForce())); // Arbitrary random numbers for impact force
						CSoundManager::Get().PlaySound("enemy_hit");
						enemy->SetVisibility(true);
						bullet->SetKillFlag(true);
					}
				}
			}
		}
	}
}

void CLogic::Render(){


	SDL_SetRenderDrawColor(m_pRenderer, 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(m_pRenderer);
	
	m_Player.WeaponRenderer(m_pRenderer, m_nWindowWidth, m_nWindowHeight);
	
	m_Player.Render(m_pRenderer);

	for (size_t i = 0; i < m_pEnemies.size(); ++i) {
		if (m_pEnemies[i]->GetVisibility()) {
			m_pEnemies[i]->Render(m_pRenderer);
		}
	}

	
	SDL_RenderPresent(m_pRenderer);
}


void CLogic::AdjustResolution(int x, int y) {
	
	for (size_t it = 0; it < m_pEntities.size(); ++it) {
		m_pEntities[it]->AdjustForResolution(Vector2(x, y), Vector2(m_nWindowWidth, m_nWindowHeight));
	}
	m_nWindowWidth = x;
	m_nWindowHeight = y;
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
	for (size_t it = 0; it < m_pEntities.size(); ++it) {
		delete m_pEntities[it];
		m_pEntities[it] = nullptr;
	}
	for (size_t it = 0; it < m_pEnemies.size(); ++it) {
		m_pEnemies[it] = nullptr;
	}
	m_pEntities.clear();
	m_pRenderer = nullptr;
}


