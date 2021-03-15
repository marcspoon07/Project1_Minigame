#pragma once

#include "../Resources.h"
#include "../Renderer2D.h"
#include "../GameState.h"

#include "../math/Vector2i.h"

class HUD {
private:
	ResourceId m_ScoreTag;
	ResourceId m_NumberSheet;

	ResourceId m_HealthSheet;
	uint32 m_HealthSize;

	Vector2i m_ScorePosition;
	uint32 m_NumbersOffset;

	Vector2i m_HealthPosition;

	Resources* m_Resources;
	Renderer2D* m_Renderer2D;
	GameState* m_GameState;
public:
	HUD();
	~HUD();

	void Init();
	void Update();
	void Render();
};