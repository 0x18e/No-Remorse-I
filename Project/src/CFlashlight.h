#pragma once
#include "Utilities.h"
#include <SDL.h>
#include <vector>
class Flashlight {

private:
	std::vector<SDL_Vertex> m_Vertices;
	float m_Scale = 200.0f;
public:
	
	void Init(Vector2 initial_pos) {
		m_Vertices =
		{
			// Point a - Top vertex of the triangle
				{ SDL_FPoint{ initial_pos.x, initial_pos.y }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } },
				// Point b - Bottom-left vertex
				{ SDL_FPoint{ initial_pos.x - m_Scale, initial_pos.y + m_Scale}, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } },
				// Point c - Bottom-right vertex
				{ SDL_FPoint{ initial_pos.x + m_Scale, initial_pos.y + m_Scale }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } },

			/*
			{ SDL_FPoint{ 400, 150 }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{ 200, 450 }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{ 600, 450 }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0 }, },
			*/
		};
	}
	void SetPosition(Vector2 vec) {
		
	}
	Vector2 RotatePoints(const Vector2& point, const Vector2 &pivot,float angle) {

		float translatedX = pivot.x;
		float translatedY = pivot.y;


		float rotatedX = translatedX * cos(angle) - translatedY * sin(angle);
		float rotatedY = translatedX * sin(angle) + translatedY * cos(angle);

		Vector2 rotatedPoint;
		rotatedPoint.x = rotatedX + pivot.x;
		rotatedPoint.y = rotatedY + pivot.y;

		return rotatedPoint;
		
	}
	void RenderFlashlight(SDL_Renderer* renderer, Vector2 vec, float angle) {
		m_Vertices[0] = { SDL_FPoint{ vec.x, vec.y }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } };
			// Point b - Bottom-left vertex
		m_Vertices[1] = { SDL_FPoint{ vec.x - m_Scale, vec.y + m_Scale}, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } };
			// Point c - Bottom-right vertex
		m_Vertices[2] = { SDL_FPoint{ vec.x + m_Scale, vec.y + m_Scale }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } };
		
		Vector2 a = Vector2(m_Vertices[0].position.x, m_Vertices[0].position.y);
		Vector2 b = Vector2(m_Vertices[1].position.x, m_Vertices[1].position.y);
		Vector2 c = Vector2(m_Vertices[2].position.x, m_Vertices[2].position.y);
		b = RotatePoints(b, a, angle);
		c = RotatePoints(c, a, angle);
		m_Vertices[1] = { SDL_FPoint{ b.x - m_Scale, b.y + m_Scale}, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } };
		m_Vertices[2] = { SDL_FPoint{ c.x + m_Scale, c.y + m_Scale }, SDL_Color{ 255, 255, 255, 255 }, SDL_FPoint{ 0, 0 } };

		SDL_RenderGeometry(renderer, nullptr, m_Vertices.data(), m_Vertices.size(), nullptr, 0);
		//SDL_RenderGeometry(m_pRenderer, nullptr, .data(), verts.size(), nullptr, 0);

	}

	
	
};