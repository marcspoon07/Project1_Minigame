#include "../../headers/ui/Image.h"
#include "../../headers/Renderer2D.h"

Image::Image(const char * path, int x, int y)
{
	pImageId = Resources::getInstance()->Load<Sprite>(path);
	px = x;
	py = y;
}

Image::~Image()
{

}

void Image::Render()
{
	Renderer2D::getInstance()->RenderGraphic(pImageId, px, py);
}