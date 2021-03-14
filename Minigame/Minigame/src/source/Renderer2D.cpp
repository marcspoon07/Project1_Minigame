#include "..\headers\Renderer2D.h"

Renderer2D::Renderer2D() {
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

		SDL_BlitSurface(sprite->getSurface(), &rectAux, m_Video->getScreenSurface(), &r);
	}
}


void Renderer2D::RenderGraphic(int img, int posX, int posY)
{
	Sprite* sprite = Resources::getInstance()->GetResourceById<Sprite>(img);

	if (sprite) {
		RenderGraphic(img, 0, 0, posX, posY, sprite->getWidth(), sprite->getHeight());
	}
}