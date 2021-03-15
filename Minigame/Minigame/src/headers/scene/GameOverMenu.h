#pragma once
#include "Scene.h"
#include "../ui/ReturnButton.h"

#include "../ui/Image.h"

#include "../Renderer2D.h"

class GameOverMenu : public Scene {
public:
	GameOverMenu();
	~GameOverMenu();

	virtual void Init() override;
	virtual void Load() override;
private:
	void ProcessInput() override;

	void UpdateEnter() override;
	void UpdateLoop() override;
	void UpdateLeave() override;

	void RenderEnter() override;
	void RenderLoop() override;
	void RenderLeave() override;

	// Required resources
	Image* m_Background;
	ReturnButton* m_ReturnButton;

	ResourceId m_ScoreTag;
	ResourceId m_NumberSheet;

	Vector2i m_ScorePosition;

	uint32 m_ScoreTagSize;
	Vector2i m_NumberOffset;
	Sizei m_NumberSize;

	Renderer2D* m_Renderer2D;
};