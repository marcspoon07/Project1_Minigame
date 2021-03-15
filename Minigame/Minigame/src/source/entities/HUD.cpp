#include "../../headers/entities/HUD.h"

HUD::HUD()
{
	m_Resources = Resources::getInstance();
	m_Renderer2D = Renderer2D::getInstance();
	m_GameState = GameState::getInstance();
}

HUD::~HUD()
{
}

void HUD::Init()
{
	m_ScoreTag = m_Resources->Load<Sprite>("Assets/Sprites/ingame_score.png");
	m_NumberSheet = m_Resources->Load<Sprite>("Assets/Sprites/ingame_numbers.png");

	m_HealthSheet = m_Resources->Load<Sprite>("Assets/Sprites/health.png");
	m_HealthSize = 63;

	m_HealthPosition = { 640, 5 };

	m_ScorePosition = { 700, 100 };
	m_NumbersOffset = 80;
}

void HUD::Update()
{

}

void HUD::Render()
{
	// Draw score
	m_Renderer2D->RenderGraphic(m_ScoreTag, m_ScorePosition.x, m_ScorePosition.y);
	
	uint32 score = m_GameState->getScore();

	int divisor = 10000;
	int number = score / divisor;

	m_Renderer2D->RenderGraphic(m_NumberSheet, number, 0, m_ScorePosition.x + m_NumbersOffset, m_ScorePosition.y, 14, 22);
	
	for (int i = 1; i < 5; i++) {
		number = score % divisor;
		divisor /= 10;
		number /= divisor;

		m_Renderer2D->RenderGraphic(m_NumberSheet, number * 14, 0, m_ScorePosition.x + m_NumbersOffset + (i * 14), m_ScorePosition.y, 14, 22);
	}

	// Draw health
	uint32 health = m_GameState->getHealth();
	uint32 srcX = 0;
	for (int i = 0; i < 5; i++) {
		if (health >= 2) {
			health -= 2;
		}
		else if (health == 1) {
			health--;

			srcX = m_HealthSize;
		}
		else {
			srcX = m_HealthSize * 2;
		}

		m_Renderer2D->RenderGraphic(m_HealthSheet, srcX, 0, m_HealthPosition.x + i * m_HealthSize, m_HealthPosition.y, m_HealthSize, m_HealthSize);
	}
}