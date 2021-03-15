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

	int m_ScreenWidth, m_ScreenHeight;

	std::string m_WindowTitle;
public:
	Video();
	~Video();

	void ResizeWindow(int width, int height);

	void ClearScreen();
	void UpdateScreen();
	void Delay(int ms);
	void TickDelay();
	void Close();

	int getScreenWidth() { return m_ScreenWidth; }
	int getScreenHeight() { return m_ScreenHeight; }

	unsigned int getDeltaTime() { return m_DeltaTime; }

	SDL_Surface* getScreenSurface() { return m_ScreenSurface; }
};