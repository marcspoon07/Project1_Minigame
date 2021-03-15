#pragma once
#include "Scene.h"
#include "../ui/Image.h"
#include "../utilities/Animation.h"

#include "../entities/Spawner.h"
#include "../entities/Portal.h"
#include "../entities/HUD.h"
#include "../entities/Conveyor.h"

#include "../GameState.h"

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
	GameState* m_GameState;

	Image* m_BackgroundImage;

	uint32 m_BlockEaterFrameSpeed;
	Animation m_BlockEaterAnimation;

	Spawner m_Spawner;
	Portal m_Portal;
	SDL_Scancode m_ActiveScancode;
	HUD m_HUD;

	ResourceId m_BackgroundMusic;

	Conveyor m_Conveyor;
	Vector2i m_FirstConveyorPosition, m_SecondConveyorPosition;
};