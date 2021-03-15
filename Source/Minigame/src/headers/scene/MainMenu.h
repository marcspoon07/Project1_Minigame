#pragma once
#include "Scene.h"
#include "../ui/PlayButton.h"
#include "../ui/QuitButton.h"
#include "../ui/Image.h"

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
		PlayButton* m_PlayButton;
		QuitButton* m_QuitButton;

		Image* m_MainImage;
};