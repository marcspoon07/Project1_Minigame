#include "../../headers/entities/Character.h"

Character::Character()
{
	m_Renderer = Renderer2D::getInstance();
	m_Resources = Resources::getInstance();
	m_GameState = GameState::getInstance();
}


Character::~Character()
{
}

void Character::Init(uint32 choosenType, uint32 frameSpeed, Vector2i pos)
{
	m_Type = static_cast<CharacterType>(choosenType);
	m_Score = 10;
	m_CharacterAnimation.Init("Assets/Sprites/characters.png", 2, 500 / frameSpeed, choosenType * SPRITE_SIZE);
	m_CharacterAnimation.setPosition(pos);

	m_Pos = pos;
	m_Speed = frameSpeed;

	if (m_Type == FIRE || m_Type == POISON) {
		m_Score *= -1;
	}
}

void Character::Update()
{
	Move();

	m_CharacterAnimation.Update();
	m_CharacterAnimation.setPosition(m_Pos);
}

void Character::Render()
{
	m_CharacterAnimation.Render();
}

void Character::Death(int * score)
{
	*score += m_Score;
}

void Character::Move()
{
	m_Pos.x -= m_Speed;
	m_CharacterAnimation.setPosition(m_Pos);
}
