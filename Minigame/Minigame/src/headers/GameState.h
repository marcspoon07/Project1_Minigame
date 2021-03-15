#pragma once

#include "Singleton.h"

#include "../simple_types.h"

class GameState : public Singleton<GameState>
{
	friend class Singleton<GameState>;
	private:
		GameState() { m_Score = 0; m_Health = 10; }

		uint32 m_Score;
		uint32 m_Health;
	public:
		~GameState() {}

		uint32 getScore() { return m_Score; }
		void addPoints(uint32 pts) { m_Score += pts; }
		void setPoints(uint32 pts) { m_Score = pts; }

		uint32 getHealth() { return m_Health; }
		void loseHealth() { m_Health--; }
		void setHealth(uint32 health) { m_Health = health; }
};