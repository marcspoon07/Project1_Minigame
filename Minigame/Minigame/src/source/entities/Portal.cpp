#include "../../headers/entities/Portal.h"

Portal::Portal()
{
	m_AnimSpeed = 90;
	m_AnimStep = 0;
	m_AnimMaxSteps = 3;

	m_ShrinkCollider = 30;

	m_Video = Video::getInstance();
	m_Renderer2D = Renderer2D::getInstance();
	m_Audio = Audio::getInstance();
}

Portal::~Portal()
{
}

void Portal::CheckCharacters()
{
	size_t size = m_CharacterList->size();

	for (size_t i = 0; i < size; i++) {
		if (Collide(m_CharacterList->at(i).getBounds())) {
			m_CharacterList->at(i).Kill();
		}
	}
}

bool Portal::Collide(Rectangle rect)
{
	Vector2i pos = m_Position;
	pos.x += m_ShrinkCollider / 2;

	uint32 size = SPRITE_SIZE - m_ShrinkCollider * 2;

	if (rect.x >= pos.x && rect.x <= pos.x + size) {
		if (rect.y >= pos.y && rect.y <= pos.y + size) {
			return true;
		}
		else if (pos.y >= rect.y && pos.y <= rect.y + SPRITE_SIZE) {
			return true;
		}
	}
	else if (pos.x >= rect.x && pos.x <= rect.x + SPRITE_SIZE) {
		if (pos.y >= rect.y && pos.y <= rect.y + SPRITE_SIZE) {
			return true;
		}
		else if (rect.y >= pos.y && rect.y <= pos.y + size) {
			return true;
		}
	}

	return false;
}

void Portal::Init(std::vector<Character>* characterList)
{
	m_CharacterList = characterList;
	
	m_PortalAnimation.Init("Assets/Sprites/portal.png", m_AnimMaxSteps, m_AnimSpeed, m_AnimState);
	m_PortalAudio = Resources::getInstance()->Load<AudioClip>("Assets/Audio/portal.ogg");
}

void Portal::Update()
{
	if (m_IsActive) {
		m_AnimTimer += m_Video->getDeltaTime();

		switch (m_AnimState) {
		case ST_IN:
			if (m_AnimTimer >= m_AnimSpeed) {
				m_AnimStep++;

				if (m_AnimStep >= m_AnimMaxSteps) {
					m_AnimState = ST_IDLE;
					m_PortalAnimation.setSourceY(ST_IDLE);
				}
			}
			break;
		case ST_IDLE:
			break;
		case ST_OUT:
			if (m_AnimTimer >= m_AnimSpeed) {
				m_AnimStep++;

				if (m_AnimStep >= m_AnimMaxSteps) {
					m_IsActive = false;
				}
			}
			break;
		}
		CheckCharacters();
		m_PortalAnimation.Update();
	}
}

void Portal::Render()
{
	if (m_IsActive) {
		m_PortalAnimation.Render();
	}
}

void Portal::Activate(Vector2i position, uint32 multiplier)
{
	m_AnimTimer = 0;
	m_AnimStep = 0;
	m_AnimState = ST_IN;

	m_Position = position;
	m_PortalAnimation.setPosition(position);
	m_PortalAnimation.setFrameSpeed(m_AnimSpeed / (multiplier * 1.8));
	m_PortalAnimation.setSourceY(ST_IN);
	m_IsActive = true;

	m_Audio->PlayAudio(m_PortalAudio, 64);
}

void Portal::Deactivate()
{
	m_AnimTimer = 0;
	m_AnimStep = 0;
	m_AnimState = ST_OUT;
	m_PortalAnimation.setSourceY(ST_OUT);
}