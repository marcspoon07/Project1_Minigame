#include "../../headers/ui/QuitButton.h"
#include "../../headers/Input.h"

QuitButton::QuitButton(const char* sheet_path, int x, int y) : Button(sheet_path, x, y)
{

}

QuitButton::~QuitButton()
{
}

void QuitButton::OnClick()
{
	Input::getInstance()->QuitGame();
}