#pragma once

#include "Singleton.h"

#include "../simple_types.h"

class GameState : public Singleton<GameState>
{
	friend class Singleton<GameState>;
	private:
		GameState() { m_Score = 0; m_Health = 20; }

		uint32 m_Score;
		uint32 m_Health;

	public:
		~GameState() {}
		uint32 getScore() { return m_Score; }
		void setScore(uint32 gameSpeed) { m_Score = gameSpeed; }
};