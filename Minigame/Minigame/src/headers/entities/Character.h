#include "../math/Vector2i.h"
#include "../utilities/Sprite.h"

#include "../Renderer2D.h"
#include "../Resources.h"
#include "../GameState.h"

#include "../utilities/Animation.h"

class Character {
private:
	enum CharacterType { NATURE, FIRE, WATER, POISON };

	uint32 m_Score;

	uint32 m_Speed;
	Vector2i m_Pos;
	CharacterType m_Type;
	
	Renderer2D *m_Renderer;
	Resources *m_Resources;
	GameState* m_GameState;

	Animation m_CharacterAnimation;
public:
	Character();
	~Character();

	void Init(uint32 choosenType, uint32 frameSpeed, Vector2i pos);
	void Update();
	void Render();

	void SetPosition(Vector2i newm_Pos) { m_Pos = newm_Pos;	}

	Vector2i GetPosition() { return m_Pos; }

	void Death(int *score);
	void Move();

};