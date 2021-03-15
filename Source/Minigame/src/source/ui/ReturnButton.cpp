#include "../../headers/ui/ReturnButton.h"
#include "../../headers/Input.h"
#include "../../headers/scene/SceneManager.h"

ReturnButton::ReturnButton(const char* sheet_path, int x, int y) : Button(sheet_path, x, y)
{

}

ReturnButton::~ReturnButton()
{
}

void ReturnButton::OnClick()
{
	SceneManager::getInstance()->StartChangeScene(SceneManager::SceneEnum::SCENE_MAIN);
}