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

	uint32 m_Width;
	uint32 m_Height;

	uint32 m_AnimationTimer;

	Vector2i m_Position;

	ResourceId m_SpriteSheet;

	Renderer2D* m_Renderer2D;
	Resources* m_Resources;
	Video* m_Video;
public:
	Animation();
	~Animation();

	void Init(const char* path, uint32 frameCount, uint32 frameSpeed, uint32 positionY, uint32 width=SPRITE_SIZE, uint32 height=SPRITE_SIZE);
	void Update();
	void Render();

	void setPosition(Vector2i position) { m_Position = position; }
	void setPositionX(int x) { m_Position.x = x; }
	void setPositionY(int y) { m_Position.y = y; }

	void setFrameSpeed(uint32 frameSpeed) { m_FrameSpeed = frameSpeed; }
	uint32 getFrameSpeed() { return m_FrameSpeed; }

	void setSourceY(uint32 positionY) { m_PositionY = positionY; }
};