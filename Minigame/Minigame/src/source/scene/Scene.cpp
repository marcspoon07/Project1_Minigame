#include "../../headers/scene/Scene.h"
#include "../../headers/Video.h"
#include "../../headers/scene/SceneManager.h"

Scene::Scene()
{
	m_MaxTimeEntering = 0;
	m_MaxTimeLeaving = 0;

	m_Input = Input::getInstance();
}

Scene::~Scene()
{
}

void Scene::Update()
{
	switch (m_CurrentState)
	{
		case Scene::SCENE_ENTERING:
			m_TransitionTimer += Video::getInstance()->getDeltaTime();
			if (m_TransitionTimer >= m_MaxTimeEntering) m_CurrentState = SCENE_LOOP;
			UpdateEnter();
			RenderEnter();
			break;
		case Scene::SCENE_LOOP:
			ProcessInput();
			UpdateLoop();
			RenderLoop();
			break;
		case Scene::SCENE_LEAVING:
			m_TransitionTimer += Video::getInstance()->getDeltaTime();
			if (m_TransitionTimer >= m_MaxTimeLeaving) SceneManager::getInstance()->ChangeScene(m_SceneToChange);
			UpdateLeave();
			RenderLeave();
			break;
		default:
			break;
	}
}

void Scene::Load()
{
	m_TransitionTimer = 0;

	m_CurrentState = SCENE_ENTERING;
}

void Scene::ChangeScene(unsigned int scene)
{
	m_SceneToChange = scene;
	m_CurrentState = SCENE_LEAVING;
	m_TransitionTimer = 0;
}