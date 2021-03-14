#include "../../headers/scene/GameOverMenu.h"
#include "../../headers/Debug.h"
#include "../../headers/scene/SceneManager.h"

GameOverMenu::GameOverMenu()
{
	/*mBackgroundMusicId = Resources::getInstance()->Load<AudioClip>("Assets/Resources/sons/ambient_menu.mp3");*/
}

GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::Init()
{
	/*mGameOverMenuImage = new Image("Assets/Resources/menus/GameOverMenu.png", 0, 0);*/
}

void GameOverMenu::Load()
{
	Scene::Load();

	/*Audio::getInstance()->PlayMusic(mBackgroundMusicId);*/
	Debug::getInstance()->Log("SCENE", "LOADED GAME OVER SCENE");
}

void GameOverMenu::ProcessInput()
{
	if (Input::getInstance()->getKey(SDL_SCANCODE_ESCAPE)) {
		Input::getInstance()->QuitGame();
	}
}

void GameOverMenu::UpdateEnter()
{
}

void GameOverMenu::UpdateLoop()
{
}

void GameOverMenu::UpdateLeave()
{
}

void GameOverMenu::RenderEnter()
{
}

void GameOverMenu::RenderLoop()
{
}

void GameOverMenu::RenderLeave()
{
}
