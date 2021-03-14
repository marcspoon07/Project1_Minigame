#include "../../headers/scene/GameScene.h"
#include "../../headers/Debug.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete m_BackgroundImage;
}

void GameScene::Init()
{
	m_BackgroundImage = new Image("Assets/Sprites/background.png", 0, 0);
	m_BlockEaterImage = new Image("Assets/Sprites/block_eater.png", 0, 41);
}

void GameScene::Load()
{
	Scene::Load();

	Debug::getInstance()->Log("SCENE", "LOADED GAME SCENE");
}

void GameScene::ProcessInput()
{
	// TODO: Control input
}

void GameScene::UpdateEnter()
{
}

void GameScene::UpdateLoop()
{
	m_Spawner.Update();
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
	m_BlockEaterImage->Render();
	m_Spawner.Render();
}

void GameScene::RenderLeave()
{
}