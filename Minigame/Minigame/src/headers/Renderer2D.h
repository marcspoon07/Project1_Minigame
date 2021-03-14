#pragma once

#include <SDL.h>

#include "Singleton.h"

#include "Debug.h"
#include "Video.h"
#include "Resources.h"

#include "../simple_types.h"

#include "utilities/Sprite.h"

#define SPRITE_SIZE 24

typedef SDL_Rect Rectangle;

class Renderer2D : public Singleton<Renderer2D> {
	friend class Singleton<Renderer2D>;

private:
	Renderer2D();

	Video* m_Video;
public:
	~Renderer2D();

	// Implementar funciones de renderizado
	void RenderGraphic(uint32 img, int sourcePosX, int sourcePosY, int posX, int posY, int width, int height);
	void RenderGraphic(int img, int posX, int posY);
};