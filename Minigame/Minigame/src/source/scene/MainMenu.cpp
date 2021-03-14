#include "../../headers/scene/MainMenu.h"
#include "../../headers/Debug.h"
#include "../../headers/scene/SceneManager.h"

MainMenu::MainMenu()
{
	/*mBackgroundMusicId = Resources::getInstance()->Load<AudioClip>("Assets/Resources/sons/ambient_menu.mp3");*/
}

MainMenu::~MainMenu()
{
	/*delete mMainMenuImage;
	delete mPlayButton;
	delete mQuitButton;*/
}

void MainMenu::Init()
{
	/*mMainMenuImage = new Image("Assets/Resources/menus/mainMenu.png", 0, 0);
	mPlayButton = new PlayButton("Assets/Resources/menus/button_jugar.png", 84, 150);
	mQuitButton = new QuitButton("Assets/Resources/menus/button_sortir.png", 84, 190);*/
}

void MainMenu::Load()
{
	Scene::Load();

	/*Audio::getInstance()->PlayMusic(mBackgroundMusicId);*/
	Debug::getInstance()->Log("SCENE", "LOADED MAIN SCENE");
}

void MainMenu::ProcessInput()
{
	/*if (Input::getInstance()->getKey(SCANCODE_ESC)) {
		Input::getInstance()->QuitGame();
	}*/

	if (Input::getInstance()->getKeyDown(SDL_SCANCODE_SPACE)) {
		ChangeScene(SceneManager::SceneEnum::SCENE_GAME);
	}
}

void MainMenu::UpdateEnter()
{
}

void MainMenu::UpdateLoop()
{
	/*mPlayButton->Update();
	mQuitButton->Update();*/
}

void MainMenu::UpdateLeave()
{
}

void MainMenu::RenderEnter()
{
}

void MainMenu::RenderLoop()
{
	/*mMainMenuImage->Render();
	mPlayButton->Render();
	mQuitButton->Render();*/
}

void MainMenu::RenderLeave()
{
}
