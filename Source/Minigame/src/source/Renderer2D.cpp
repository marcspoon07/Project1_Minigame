#include "..\headers\Renderer2D.h"

Renderer2D::Renderer2D() {
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
		Debug::getInstance()->LogError("RENDERER2D", IMG_GetError());
	}

	m_Video = Video::getInstance();
}

Renderer2D::~Renderer2D()
{
	
}

void Renderer2D::RenderGraphic(uint32 img, int sourcePosX, int sourcePosY, int posX, int posY, int width, int height)
{
	Sprite* sprite = Resources::getInstance()->GetResourceById<Sprite>(img);

	if (sprite) {
		SDL_Rect r, rectAux;
		r.x = posX;
		r.y = posY;
		rectAux.h = height;
		rectAux.w = width;
		rectAux.x = sourcePosX;
		rectAux.y = sourcePosY;

		SDL_Surface* sprite_srfc = sprite->getSurface();
		SDL_Surface* screen_srfc = m_Video->getScreenSurface();

		if (SDL_BlitSurface(sprite_srfc, &rectAux, screen_srfc, &r) == -1) {
			Debug::getInstance()->LogWarning("RENDERER2D", SDL_GetError());
		}
	}
}


void Renderer2D::RenderGraphic(int img, int posX, int posY)
{
	Sprite* sprite = Resources::getInstance()->GetResourceById<Sprite>(img);

	if (sprite) {
		RenderGraphic(img, 0, 0, posX, posY, sprite->getWidth(), sprite->getHeight());
	}
}