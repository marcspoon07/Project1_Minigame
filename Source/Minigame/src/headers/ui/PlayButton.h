#pragma once
#include "../ui/Button.h"

class PlayButton : public Button {
	public:
		PlayButton(const char* sheet_path, int x, int y);
		~PlayButton();
	private:
		void OnClick() override;
};