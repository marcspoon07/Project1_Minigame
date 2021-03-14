#pragma once
#include "../Resources.h"

class Image {
	private:
		ResourceId pImageId;
		int px, py;
	public:
		Image(const char* path, int x, int y);
		~Image();

		ResourceId getImageId() { return pImageId; }

		void Render();
};