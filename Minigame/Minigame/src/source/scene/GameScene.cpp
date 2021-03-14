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
}

void GameScene::Load()
{
	Scene::Load();

	Debug::getInstance()->Log("SCENE", "LOADED GAME SCENE");
}

void GameScene::ProcessInput()
{
	
}

void GameScene::UpdateEnter()
{
}

void GameScene::UpdateLoop()
{
	
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
}

void GameScene::RenderLeave()
{
}