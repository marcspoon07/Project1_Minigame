#include "src/headers/Video.h"
#include "src/headers/Input.h"
#include "src/headers/Audio.h"

int main(int argc, char* args[]) {
	Video* video = Video::getInstance();
	Input* input = Input::getInstance();
	Audio* audio = Audio::getInstance();
	Resources* resources = Resources::getInstance();

	while (!input->WindowQuit()) {
		video->clearScreen();
		input->UpdateInputs();

		// Game logic

		video->updateScreen();
		video->tickDelay();
	}

	video->close();

	delete video;
	delete input;
	delete audio;

	return 0;
}