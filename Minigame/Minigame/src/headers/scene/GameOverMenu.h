#pragma once
#include "Scene.h"
#include "../ui/PlayButton.h"
#include "../ui/QuitButton.h"

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
};