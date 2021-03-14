#include "../../headers/scene/MainMenu.h"
#include "../../headers/Debug.h"
#include "../../headers/scene/SceneManager.h"

MainMenu::MainMenu()
{
	/*mBackgroundMusicId = Resources::getInstance()->Load<AudioClip>("Assets/Resources/sons/ambient_menu.mp3");*/
}

MainMenu::~MainMenu()
{
	delete m_PlayButton;
	delete m_QuitButton;
	delete m_MainImage;
}

void MainMenu::Init()
{
	m_MainImage = new Image("Assets/Sprites/main_menu.png", 0, 0);
	m_PlayButton = new PlayButton("Assets/Sprites/play_button.png", 352, 290);
	m_QuitButton = new QuitButton("Assets/Sprites/quit_button.png", 352, 380);
}

void MainMenu::Load()
{
	Scene::Load();

	/*Audio::getInstance()->PlayMusic(mBackgroundMusicId);*/
	Debug::getInstance()->Log("SCENE", "LOADED MAIN SCENE");
}

void MainMenu::ProcessInput()
{
	if (Input::getInstance()->getKey(SDL_SCANCODE_ESCAPE)) {
		Input::getInstance()->QuitGame();
	}
}

void MainMenu::UpdateEnter()
{
}

void MainMenu::UpdateLoop()
{
	m_PlayButton->Update();
	m_QuitButton->Update();
}

void MainMenu::UpdateLeave()
{
}

void MainMenu::RenderEnter()
{
}

void MainMenu::RenderLoop()
{
	m_MainImage->Render();
	m_PlayButton->Render();
	m_QuitButton->Render();
}

void MainMenu::RenderLeave()
{
}
