#pragma once

#include "sdl.h"

#include "../simple_types.h"

#include "Singleton.h"

#include <string>

#define FPS 60

class Video : public Singleton<Video>
{
	friend class Singleton<Video>;
private:
	unsigned int
		m_LastTime,
		m_CurrentTime,
		m_DeltaTime;

	uint32 m_FrameMS;

	SDL_Window* m_Window;
	SDL_Surface* m_ScreenSurface;

	int m_ScreenWidth, mScreenHeight;

	std::string m_WindowTitle;
public:
	Video();
	~Video();

	unsigned int getDeltaTime();

	void ResizeWindow(int width, int height);

	void clearScreen();
	void updateScreen();
	void waitTime(int ms);
	void tickDelay();
	void close();

	int getScreenWidth() { return m_ScreenWidth; }
	int getScreenHeight() { return mScreenHeight; }

	SDL_Surface* getScreenSurface() { return m_ScreenSurface; }
};