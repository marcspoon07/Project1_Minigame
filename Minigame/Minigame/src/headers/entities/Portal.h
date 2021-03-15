#pragma once

#include "../utilities/Animation.h"
#include <vector>
#include "Character.h"
#include "../Video.h"
#include "../Renderer2D.h"
#include "../Audio.h"

class Portal {
private:
	enum State {
		ST_IN,
		ST_IDLE,
		ST_OUT
	};

	State m_AnimState;

	uint32 m_AnimTimer;
	uint32 m_AnimStep;
	uint32 m_AnimMaxSteps;
	uint32 m_AnimSpeed;

	Animation m_PortalAnimation;

	bool m_IsActive;
	Vector2i m_Position;

	ResourceId m_PortalAudio;

	std::vector<Character>* m_CharacterList;

	Video* m_Video;
	Renderer2D* m_Renderer2D;
	Audio* m_Audio;

	uint32 m_ShrinkCollider;

	void CheckCharacters();
	bool Collide(Rectangle rect);
public:
	Portal();
	~Portal();

	void Init(std::vector<Character>* characterList);
	void Update();
	void Render();

	void Activate(Vector2i position, uint32 multiplier);
	void Deactivate();

	bool IsActive() { return m_IsActive; }
};