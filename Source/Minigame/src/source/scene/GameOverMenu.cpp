#include "../../headers/scene/GameOverMenu.h"
#include "../../headers/Debug.h"
#include "../../headers/scene/SceneManager.h"
#include "../../headers/GameState.h"
#include "../../headers/Audio.h"

GameOverMenu::GameOverMenu()
{
	/*mBackgroundMusicId = Resources::getInstance()->Load<AudioClip>("Assets/Resources/sons/ambient_menu.mp3");*/
	m_Renderer2D = Renderer2D::getInstance();
}

GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::Init()
{
	m_Background = new Image("Assets/Sprites/gameOver.png", 0, 0);
	m_ReturnButton = new ReturnButton("Assets/Sprites/return_button.png", 10, 400);

	m_ScoreTag = Resources::getInstance()->Load<Sprite>("Assets/Sprites/gameover_score.png");
	m_NumberSheet = Resources::getInstance()->Load<Sprite>("Assets/Sprites/gameover_numbers.png");

	m_ScorePosition = { 313, 238 };

	m_NumberOffset = { 170,10 };
	m_ScoreTagSize = 333;
	m_NumberSize.width = 28;
	m_NumberSize.height = 44;
}

void GameOverMenu::Load()
{
	Scene::Load();

	/*Audio::getInstance()->PlayMusic(mBackgroundMusicId);*/
	Debug::getInstance()->Log("SCENE", "LOADED GAME OVER SCENE");

	ResourceId gameOverAudio = Resources::getInstance()->Load<AudioClip>("Assets/Audio/gameover.ogg");
	Audio::getInstance()->StopMusic();
	Audio::getInstance()->PlayAudio(gameOverAudio, 64);
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
	m_ReturnButton->Update();
}

void GameOverMenu::UpdateLeave()
{
}

void GameOverMenu::RenderEnter()
{
}

void GameOverMenu::RenderLoop()
{
	m_Background->Render();
	m_ReturnButton->Render();
	
	m_Renderer2D->RenderGraphic(m_ScoreTag, m_ScorePosition.x, m_ScorePosition.y);

	uint32 score = GameState::getInstance()->getScore();

	int divisor = 10000;
	int number = score / divisor;

	m_Renderer2D->RenderGraphic(m_NumberSheet, number, 0, m_ScorePosition.x + m_NumberOffset.x, m_ScorePosition.y + m_NumberOffset.y, m_NumberSize.width, m_NumberSize.height);

	for (int i = 1; i < 5; i++) {
		number = score % divisor;
		divisor /= 10;
		number /= divisor;

		m_Renderer2D->RenderGraphic(m_NumberSheet, number * m_NumberSize.width, 0, m_ScorePosition.x + m_NumberOffset.x + (i * m_NumberSize.width), m_ScorePosition.y + m_NumberOffset.y, m_NumberSize.width, m_NumberSize.height);
	}
}

void GameOverMenu::RenderLeave()
{
}
