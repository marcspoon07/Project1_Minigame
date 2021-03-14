#include "../../headers/ui/PlayButton.h"
#include "../../headers/scene/SceneManager.h"

PlayButton::PlayButton(const char* sheet_path, int x, int y) : Button(sheet_path, x, y)
{

}

PlayButton::~PlayButton()
{
}

void PlayButton::OnClick()
{
	SceneManager::getInstance()->StartChangeScene(SceneManager::SceneEnum::SCENE_GAME);
}