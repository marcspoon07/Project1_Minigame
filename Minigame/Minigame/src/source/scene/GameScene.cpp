#include "../../headers/scene/GameScene.h"
#include "../../headers/Debug.h"
#include "../../headers/scene/SceneManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete m_BackgroundImage;
}

void GameScene::Init()
{
	m_GameState = GameState::getInstance();

	m_BackgroundImage = new Image("Assets/Sprites/background.png", 0, 0);

	m_BlockEaterFrameSpeed = 500;
	m_BlockEaterAnimation.Init("Assets/Sprites/block_eater.png", 3, m_BlockEaterFrameSpeed, 0, 388, 747);
	m_BlockEaterAnimation.setPosition({ 0, -50 });

	m_Portal.Init(m_Spawner.getCharacterList());

	m_HUD.Init();

	m_FirstConveyorPosition.x = 220;
	m_FirstConveyorPosition.y = 380;

	m_SecondConveyorPosition.x = 220;
	m_SecondConveyorPosition.y = 480;

	m_Conveyor.Init(m_FirstConveyorPosition);

	m_BackgroundMusic = Resources::getInstance()->Load<AudioClip>("Assets/Audio/game.wav");
}

void GameScene::Load()
{
	Scene::Load();

	Debug::getInstance()->Log("SCENE", "LOADED GAME SCENE");

	m_GameState->setHealth(10);
	m_GameState->setPoints(0);

	m_Spawner.Init();
	Audio::getInstance()->PlayMusic(m_BackgroundMusic);
}

void GameScene::ProcessInput()
{
	if (m_Input->getKeyDown(SDL_SCANCODE_ESCAPE)) {
		m_Input->QuitGame();
	}

	if (m_Input->getKey(SDL_SCANCODE_UP)) {
		if (!m_Portal.IsActive()) {
			m_Portal.Activate({ 240, 316 }, m_Spawner.getMultiplier());
			m_ActiveScancode = SDL_SCANCODE_UP;
		}
	}

	if (m_Input->getKeyUp(SDL_SCANCODE_UP)) {
		if (m_Portal.IsActive() && m_ActiveScancode == SDL_SCANCODE_UP) {
			m_Portal.Deactivate();
		}
	}

	if (m_Input->getKey(SDL_SCANCODE_DOWN)) {
		if (!m_Portal.IsActive()) {
			m_Portal.Activate({ 240, 420 }, m_Spawner.getMultiplier());
			m_ActiveScancode = SDL_SCANCODE_DOWN;
		}
	}
	
	if(m_Input->getKeyUp(SDL_SCANCODE_DOWN)){
		if (m_Portal.IsActive() && m_ActiveScancode == SDL_SCANCODE_DOWN) {
			m_Portal.Deactivate();
		}
	}
}

void GameScene::UpdateEnter()
{
}

void GameScene::UpdateLoop()
{
	m_Spawner.Update();
	m_BlockEaterAnimation.Update();
	m_Portal.Update();
	m_Conveyor.Update();

	if (m_GameState->getHealth() <= 0) {
		SceneManager::getInstance()->StartChangeScene(SceneManager::SceneEnum::SCENE_GAMEOVER);
	}
}

void GameScene::UpdateLeave()
{
}

void GameScene::RenderEnter()
{
}

void GameScene::RenderLoop()
{
	m_BackgroundImage->Render();
	m_BlockEaterAnimation.Render();

	// Render dobule conveyor
	m_Conveyor.setPosition(m_FirstConveyorPosition);
	m_Conveyor.Render();
	m_Conveyor.setPosition(m_SecondConveyorPosition);
	m_Conveyor.Render();

	m_Spawner.Render();
	m_Portal.Render();
	m_HUD.Render();

}

void GameScene::RenderLeave()
{
}