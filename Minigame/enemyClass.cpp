#include <> //la libreria para hacer el srand xD
#include <Vector2f.h>

class Enemy {
private:
	enum EnemyType { BLUE, GREEN ,RED, NEUTRAL };
	//float posX = 960, posY;
	int score;
	vector2f pos;

public:
	Enemy(int y) {
		pos.x = 960;
		pos.y = y;
		if (EnemyType == BLUE || EnemyType == GREEN) score = 100;
		if (EnemyType == RED) score = -100;
	}
	~Enemy(int* score) {		// with changes in the score
		*score += this->score;
	}
	~Enemy();					// no changes in the score

	void SetPosition(Vector2f newPos) {
		pos = newPos;
	}
	Vector2f GetPosition() {
		Vector2f position = pos;
		return position;
	}
	void ChangeType() {
		int choosenLine = rand() % 2;
		if (choosenLine == 0) {
			EnemyType = GREEN;
			score = 100;
		}
		else {
			EnemyType = RED;
			score = -100;
		}
		// llamar la funcion de animacion uwu o en algun lugar
	}

	void Move(float speed) { pos.x -= speed; }

};