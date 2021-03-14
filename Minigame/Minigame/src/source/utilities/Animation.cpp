#include "..\..\headers\utilities\Animation.h"

Animation::Animation()
{
	m_Renderer2D = Renderer2D::getInstance();
	m_Resources = Resources::getInstance();
	m_Video = Video::getInstance();
	
	m_AnimationTimer = 0;
}

Animation::~Animation()
{
}


void Animation::Init(const char * path, uint32 frameCount, uint32 frameSpeed, uint32 positionY)
{
	m_SpriteSheet = m_Resources->Load<Sprite>(path);
	m_FramesCount = frameCount;
	m_FrameSpeed = frameSpeed;
	m_PositionY = positionY;
}

void Animation::Update()
{
	m_AnimationTimer += m_Video->getDeltaTime();

	if (m_AnimationTimer >= m_FrameSpeed) {
		m_AnimationTimer = 0;
		m_ActiveFrame++;

		if (m_ActiveFrame >= m_FramesCount) {
			m_ActiveFrame = 0;
		}
	}
}

void Animation::Render()
{
	m_Renderer2D->RenderGraphic(m_SpriteSheet, (m_ActiveFrame*SPRITE_SIZE), m_PositionY, m_Position.x, m_Position.y, SPRITE_SIZE, SPRITE_SIZE);
}