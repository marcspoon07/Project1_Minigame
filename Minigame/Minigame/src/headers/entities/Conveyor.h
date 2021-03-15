#pragma once

#include "../math/Vector2i.h"
#include "../math/Sizei.h"
#include "../../headers/Resources.h"
#include "../../headers/Renderer2D.h"
#include "../utilities/Animation.h"

class Conveyor {
	private:
		Vector2i m_Position;

		ResourceId m_ConveyorSheet;

		Sizei m_ConveyorSize;

		Animation m_ConveyorAnimation;

		uint32 m_ConveyorCount;

		Resources* m_Resources;
		Renderer2D* m_Renderer2D;
	public:
		Conveyor();
		~Conveyor();

		void Init(Vector2i position);
		void Update();
		void Render();

		void setPosition(Vector2i position) { m_Position = position; m_ConveyorAnimation.setPosition(m_Position); }
};