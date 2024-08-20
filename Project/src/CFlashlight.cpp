#include "CFlashlight.h"

void CFlashlight::Init(SDL_Renderer* renderer, Vector2 initial_pos, Vector2 player_dimensions, int player_scale) {
	this->m_EntityTexture.LoadTexture(renderer, "sprites/consee.png", "flashlight");
	
	// Set the initial position
	this->m_PlayerDimensions = player_dimensions;
	this->m_Position.x = initial_pos.x + player_dimensions.x;
	this->SetScale(3);
	this->m_Position.y = initial_pos.y;
	this->m_EntityTexture.SetCurrentTexture("flashlight");
	this->m_FlashlightTexture = m_EntityTexture.GetCurrentTexture();
	m_fRatioScale = player_scale / this->GetScale();
	LOG(player_scale << ", " << this->GetScale());
	LOG(m_fRatioScale);
}

void CFlashlight::RenderFlashlight(SDL_Renderer* renderer, Vector2 player_position, Vector2 player_dimensions, float angle) {
		// Assuming you have player_position, player_dimensions, and angle defined
	float angleRadians = angle * (M_PI / 180.0f);

	// Define the local offset from the player’s center to where the object should be
	float offsetX = m_PlayerDimensions.x * m_fRatioScale;  // right side of the player
	float offsetY = 0;                    // No vertical offset

	// Rotate the offset by the player's angle
	float rotatedX = (offsetX * cos(angleRadians) - offsetY * sin(angleRadians));
	float rotatedY = (offsetX * sin(angleRadians) + offsetY * cos(angleRadians));

	// Calculate the final position of the object relative to the player's position
	int finalX = player_position.x + rotatedX;
	int finalY = player_position.y + rotatedY;

	

	// Render the object with the same rotation angle as the player
	
	m_Position.x = finalX;
	m_Position.y = finalY;
	m_dAngle = angle;

	
	this->Render(renderer);
	//SDL_RenderCopyEx(renderer, m_FlashlightTexture, nullptr, &render_area, angle, nullptr, SDL_FLIP_NONE);
}