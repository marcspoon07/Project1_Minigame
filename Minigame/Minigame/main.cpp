#include "src/headers/Video.h"
#include "src/headers/Input.h"
#include "src/headers/Audio.h"
#include "src/headers/Renderer2D.h"
#include "src/headers/scene/SceneManager.h"

#include <time.h>
#include <iostream>

// Scenes
#include "src/headers/scene/MainMenu.h"
#include "src/headers/scene/GameScene.h"
#include "src/headers/scene/GameOverMenu.h"

int main(int argc, char* args[]) {
	srand(time(NULL));

	// Create all necessary singletons
	Video* video = Video::getInstance();
	Input* input = Input::getInstance();
	Audio* audio = Audio::getInstance();
	Resources* resources = Resources::getInstance();
	Renderer2D* renderer2D = Renderer2D::getInstance();
	SceneManager* sceneManager = SceneManager::getInstance();

	// Create scenes
	sceneManager->CreateScene<MainMenu>(SceneManager::SceneEnum::SCENE_MAIN);
	sceneManager->CreateScene<GameScene>(SceneManager::SceneEnum::SCENE_GAME);
	sceneManager->CreateScene<GameOverMenu>(SceneManager::SceneEnum::SCENE_GAMEOVER);

	// Initialize the scene manager
	sceneManager->Init(SceneManager::SceneEnum::SCENE_MAIN);

	// Program loop
	while (!input->WindowQuit()) {
		video->ClearScreen();
		input->UpdateInputs();

		sceneManager->Update();

		video->UpdateScreen();
		video->TickDelay();
	}

	video->Close();

	// Delete all singletons
	delete video;
	delete input;
	delete audio;
	delete resources;
	delete renderer2D;
	delete sceneManager;

	return 0;
}