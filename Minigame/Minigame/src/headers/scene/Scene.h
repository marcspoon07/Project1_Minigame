#pragma once

#include "../Input.h"
#include "../Resources.h"
#include <SDL.h>

class Scene {
	public:
		Scene();
		~Scene();

		enum State {
			SCENE_ENTERING,
			SCENE_LOOP,
			SCENE_LEAVING
		};

		void Update();

		virtual void Init() = 0;
		virtual void Load();
		virtual void Unload(){}

		State getState() { return m_CurrentState; }

		void ChangeScene(unsigned int scene);
	protected:
		virtual void ProcessInput(){}

		virtual void UpdateEnter(){}
		virtual void UpdateLoop(){}
		virtual void UpdateLeave(){}

		virtual void RenderEnter(){}
		virtual void RenderLoop(){}
		virtual void RenderLeave(){}

		unsigned int m_MaxTimeEntering, m_MaxTimeLeaving;
	private:
		State m_CurrentState;
		unsigned int m_TransitionTimer;
		int m_SceneToChange;
};