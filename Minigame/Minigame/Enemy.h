#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include "src/headers/math/Vector2f.h"
#include "src/headers/utilities/Sprite.h"
#include <time.h> 
#include <string>
#include "src/headers/Renderer2D.h"
#include "src/headers/Resources.h"


class Enemy {
private:
	enum EnemyType { BLUE, GREEN, RED, NEUTRAL };

	int m_Score;
	float m_Speed;

	Vector2f m_Pos;
	EnemyType m_Type;
	
	Renderer2D *m_Renderer;
	Resources *m_Resources;
	int m_PathId;

	bool m_Alive = false;

public:
	Enemy();
	~Enemy();

	void Update();
	void Render();

	void SetPosition(Vector2f newm_Pos) { m_Pos = newm_Pos;	}

	Vector2f GetPosition() { return m_Pos; }

	void InitType()
	{
		srand(time(NULL));
		int choosenType = rand() % 4;
		
		switch(choosenType)
		{
		case 0:
			m_Type = BLUE;
			m_Score = 50;
			//init sprite
			break;
		case 1:
			m_Type = GREEN;
			m_Score = 100;
			//init sprite
			break;
		case 2:
			m_Type = RED;
			m_Score = -100;
			//init sprite
			break;
		case 3:
			m_Type = NEUTRAL;
			m_Score = 10;
			//init sprite
			break;
		default:
			break;
		}
	
	}
	void Death(int *score) {
		score += m_Score;
		m_Alive = false;
	}
	void Move();

};