#include "CBasePlayer.h"


CBasePlayer::CBasePlayer() {
	
}
void CBasePlayer::Init(SDL_Renderer* renderer, const char* path_to_texture, Vector2 initial_position) {

	m_Position = initial_position;
	m_EntityTexture.LoadTexture(renderer, "sprites/girl_right.png", "girl_idle");
	m_EntityTexture.LoadTexture(renderer, "sprites/girl_idea.png", "girl_shoot");
	m_EntityTexture.SetScale(3);

	m_EntityTexture.SetCurrentTexture("girl_idle");
}

/*
void CBasePlayer::SetPosition(Vector2 offset, int windowx, int windowy) {


	float calcx = (offset.x * m_Position.x) / windowx;
	float calcy = (offset.y * m_Position.y) / windowy;

	this->m_Position.x = calcx;
	this->m_Position.y = calcy;
}
*/

void CBasePlayer::WeaponUpdate(int windowx, int windowy, const float& dt) {
	m_Gun.UpdateBullets(windowx, windowy, dt);
}
void CBasePlayer::WeaponRenderer(SDL_Renderer* renderer, int windowx, int windowy) {
	m_Gun.RenderBullets(renderer);
}


void CBasePlayer::InputHandler(const SDL_Event& event, SDL_Renderer* renderer) {
	switch (event.type) {
	case SDL_MOUSEMOTION:
		HandleRotation();
		break;
	case SDL_MOUSEBUTTONDOWN:
		m_EntityTexture.SetCurrentTexture("girl_shoot");
		
		//m_bIsShooting = true; 
		
		m_Gun.Shoot(renderer, m_dAngle, m_Position);
		//CSoundManager::Get().PlaySound("shoot");
		HandleRotation();
		
		break;
	case SDL_MOUSEBUTTONUP:
		//m_bIsShooting = false;
		m_EntityTexture.SetCurrentTexture("girl_idle");
		HandleRotation();
		break;

	case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				// Left
				case SDLK_a:
					m_MovementDirection.LEFT = 1;
					break;
				// Right
				case SDLK_d:
					m_MovementDirection.RIGHT = 1;
					break;
				// Up
				case SDLK_w:
					m_MovementDirection.UP = 1;
					break;
				// Down
				case SDLK_s:
					m_MovementDirection.DOWN = 1;
					break;
				default:
					break;
			}
			break;
		// Reset the velocities
	case SDL_KEYUP:
				switch (event.key.keysym.sym) {
					// Left
				case SDLK_a:
					m_MovementDirection.LEFT = 0;
					break;
					// Right
				case SDLK_d:
					m_MovementDirection.RIGHT = 0;
					break;
					// Up
				case SDLK_w:
					m_MovementDirection.UP = 0;
					break;
					// Down
				case SDLK_s:
					m_MovementDirection.DOWN = 0;
					break;
				default:
					break;
				}
				break;
			
		default:
			break;
	}
	
	
}

void CBasePlayer::HandleRotation() {

	// Capture local mouse state
	SDL_GetMouseState(&m_nMousePositionX, &m_nMousePositionY);


	/*
	* We calculate the angle here by taking the difference between the mouse position
	* and the player's position, this gives us the distance vector from the player to the mouse.
	* we then use the arctangent to get the required angle to rotate the player by.
	*/
	m_dAngle = atan2(long(m_nMousePositionY - m_Position.y), long(m_nMousePositionX - m_Position.x)) * long(180/M_PI);
}


void CBasePlayer::Move(float dt, Vector2 camera) {
	
	if (m_MovementDirection.LEFT > 0) {
		m_Velocity.x = -m_PlayerSpeed;
	}
	
	else if (m_MovementDirection.RIGHT > 0) {
		m_Velocity.x = m_PlayerSpeed;
	}
	else {
		m_Velocity.x = 0;
	}
	
	if (m_MovementDirection.UP > 0) {
		m_Velocity.y = -m_PlayerSpeed;
	}
	else if (m_MovementDirection.DOWN) {
		m_Velocity.y = m_PlayerSpeed;
	}
	else {
		m_Velocity.y = 0;
	}
	
	
	// Add our velocity to our position
	this->m_Position += this->m_Velocity * dt;
	
}



void CBasePlayer::Destroy() {
	m_EntityTexture.Cleanup();
	m_Position = Vector2(0, 0);
	m_Velocity = Vector2(0, 0);
	m_Gun.Cleanup();
	LOG("Player Destroyed");
}

CBasePlayer::~CBasePlayer() {

}
