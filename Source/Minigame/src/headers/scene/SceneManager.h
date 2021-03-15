#pragma once

#include "../Singleton.h"

#include "Scene.h"
#include <vector>

class SceneManager : public Singleton<SceneManager> {
	friend class Singleton<SceneManager>;
	public:
		enum SceneEnum {
			SCENE_MAIN,
			SCENE_GAME,
			SCENE_GAMEOVER,
			SCENE_LAST
		};
	private:
		Scene* m_Scenes[SCENE_LAST];
		SceneEnum m_ActiveScene;

		SceneManager();
	public:
		~SceneManager();

		void Init(SceneEnum initial_scene);

		void Update();

		void ChangeScene(SceneEnum scene);
		void ChangeScene(int scene);

		void StartChangeScene(SceneEnum sceneId);

		SceneEnum getActiveScene() { return m_ActiveScene; }

		template<typename T> void CreateScene(SceneEnum sceneId);
};

template<typename T>
inline void SceneManager::CreateScene(SceneEnum sceneId)
{
	T* scene = new T();
	scene->Init();

	m_Scenes[sceneId] = scene;

	m_ActiveScene = sceneId;
}