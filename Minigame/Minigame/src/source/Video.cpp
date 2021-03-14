#include "../headers/Video.h"

Video::Video()
{
	m_ScreenWidth = 960;
	m_ScreenHeight = 540;

	m_Window = NULL;

	SDL_Init(SDL_INIT_EVERYTHING);

	m_WindowTitle = "Block Eater";

	m_Window = SDL_CreateWindow(m_WindowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_SHOWN);
	m_ScreenSurface = SDL_GetWindowSurface(m_Window);

	m_LastTime = 0;
	m_FrameMS = static_cast<uint32>(1.0f / (FPS / 1000.0f));
	m_CurrentTime = 0;

	m_DeltaTime = 0;
}

Video::~Video()
{

}

void Video::ResizeWindow(int width, int height)
{
	SDL_SetWindowSize(m_Window, width, height);
	m_ScreenWidth = width;
	m_ScreenHeight = height;
}

void Video::ClearScreen()
{
	SDL_FillRect(m_ScreenSurface, NULL, 0xFFFFFF);
}

void Video::UpdateScreen()
{
	std::string title = m_WindowTitle;
	title += " - ";
	title += std::to_string(m_DeltaTime);
	SDL_SetWindowTitle(m_Window, title.c_str());
	SDL_UpdateWindowSurface(m_Window);
}

void Video::Delay(int ms)
{
	SDL_Delay(ms);
}

void Video::TickDelay()
{
	m_CurrentTime = SDL_GetTicks();

	m_DeltaTime = m_CurrentTime - m_LastTime;

	if (m_DeltaTime < m_FrameMS) {
		SDL_Delay(m_FrameMS - m_DeltaTime);
	}

	m_LastTime = m_CurrentTime;
}

void Video::Close()
{
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}