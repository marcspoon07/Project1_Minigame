#pragma once
#include "Scene.h"

class MainMenu : public Scene {
	public:
		MainMenu();
		~MainMenu();

		virtual void Init() override;
		virtual void Load() override;
	private:
		void ProcessInput() override;

		void UpdateEnter() override;
		void UpdateLoop() override;
		void UpdateLeave() override;

		void RenderEnter() override;
		void RenderLoop() override;
		void RenderLeave() override;

		// Required resources
};