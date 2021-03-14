#pragma once
#include "Scene.h"
#include "../utilities/Image.h"

class GameScene : public Scene {
public:
	GameScene();
	~GameScene();

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
	Image* m_BackgroundImage;
};