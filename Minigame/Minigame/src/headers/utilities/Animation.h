#pragma once

#include "../../simple_types.h"
#include "Sprite.h"
#include "../Renderer2D.h"
#include "../Resources.h"
#include "../math/Vector2i.h"

class Animation {
private:
	uint32 m_FrameSpeed;
	uint32 m_FramesCount;
	uint32 m_ActiveFrame;
	uint32 m_PositionY;

	uint32 m_AnimationTimer;

	Vector2i m_Position;

	ResourceId m_SpriteSheet;

	Renderer2D* m_Renderer2D;
	Resources* m_Resources;
	Video* m_Video;

public:
	Animation();
	~Animation();

	void Init(const char* name, uint32 frameCount, uint32 frameSpeed, uint32 positionY);
	void Update();
	void Render();

	void ChangePosition(Vector2i position) { m_Position = position; }
};