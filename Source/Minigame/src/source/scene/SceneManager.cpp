#include "../../headers/scene/SceneManager.h"

SceneManager::SceneManager()
{
	m_ActiveScene = SceneEnum::SCENE_LAST;
}

SceneManager::~SceneManager()
{
	for (int i = 0; i < SCENE_LAST; i++) {
		delete m_Scenes[i];
	}
}

void SceneManager::Init(SceneManager::SceneEnum initial_scene)
{
	m_ActiveScene = initial_scene;
	m_Scenes[m_ActiveScene]->Load();
}

void SceneManager::Update()
{
	m_Scenes[m_ActiveScene]->Update();
}

void SceneManager::ChangeScene(SceneManager::SceneEnum scene)
{
	m_Scenes[m_ActiveScene]->Unload();
	m_ActiveScene = scene;
	m_Scenes[m_ActiveScene]->Load();
}

void SceneManager::ChangeScene(int scene)
{
	ChangeScene(static_cast<SceneEnum>(scene));
}

void SceneManager::StartChangeScene(SceneEnum sceneId)
{
	m_Scenes[m_ActiveScene]->ChangeScene(sceneId);
}