#pragma once
#include "../ui/Button.h"

class QuitButton : public Button {
	public:
		QuitButton(const char* sheet_path, int x, int y);
		~QuitButton();
	private:
		void OnClick() override;
};