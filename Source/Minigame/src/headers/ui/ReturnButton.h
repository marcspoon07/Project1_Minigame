#pragma once
#include "../ui/Button.h"

class ReturnButton : public Button {
public:
	ReturnButton(const char* sheet_path, int x, int y);
	~ReturnButton();
private:
	void OnClick() override;
};