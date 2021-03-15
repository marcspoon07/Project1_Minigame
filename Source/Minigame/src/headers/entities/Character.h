#pragma once
#include "../math/Vector2i.h"
#include "../utilities/Sprite.h"

#include "../Renderer2D.h"
#include "../Resources.h"
#include "../GameState.h"

#include "../utilities/Animation.h"

class Character {
public:
	enum CharacterType { NATURE, FIRE, WATER, POISON };
private:
	uint32 m_Score;

	uint32 m_Speed;
	Vector2i m_Pos;
	CharacterType m_Type;

	uint32 m_LimitX;
	
	Renderer2D *m_Renderer;
	Resources *m_Resources;
	GameState* m_GameState;

	Animation m_CharacterAnimation;

	bool m_IsAlive;
	bool m_Eaten;
public:
	Character();
	~Character();

	void Init(uint32 choosenType, uint32 frameSpeed, Vector2i pos);
	void Update();
	void Render();

	void Move();

	void Kill() { m_IsAlive = false; }
	bool IsAlive() { return m_IsAlive; }
	bool WasEaten(){ return m_Eaten; }

	uint32 getPoints() { return m_Score; }
	CharacterType getType() { return m_Type; }

	Rectangle getBounds() { return {m_Pos.x, m_Pos.y, SPRITE_SIZE, SPRITE_SIZE}; }

};