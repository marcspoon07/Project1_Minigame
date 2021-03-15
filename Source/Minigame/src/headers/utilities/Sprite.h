#pragma once

#include "../../simple_types.h"

#include <SDL.h>

typedef SDL_Surface Surface;

class Sprite {
private:
	Surface* m_Surface;
	uint32 m_Width, m_Height;
public:
	Sprite(Surface* srfc, uint32 width, uint32 height);
	~Sprite();

	uint32 getWidth() { return m_Width; }
	uint32 getHeight() { return m_Height; }
	Surface* getSurface() { return m_Surface; }
};