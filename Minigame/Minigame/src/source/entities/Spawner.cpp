#include "../../headers/entities/Spawner.h"

Spawner::Spawner()
{
	m_Video = Video::getInstance();

	m_SpawnCount = 0;
	m_Multiplier = 1;
	m_SpawnStartSpeed = 3000;
	m_SpawnSpeed = m_SpawnStartSpeed;
	m_ActiveWave = 0;

	m_WaitWaveTime = 5000;
	m_WaitWaveTimer = m_WaitWaveTime;

	m_RowPositions[0] = 80;
	m_RowPositions[1] = 300;

	m_WaitWave = false;
}


Spawner::~Spawner()
{
}

void Spawner::SpawnEnemy()
{
	uint32 choosenType = rand() % 4;

	int ypos = m_RowPositions[rand() % 2];

	m_CharacterList.emplace_back();
	m_CharacterList[m_CharacterCount].Init(choosenType, m_Multiplier, Vector2i({ 900, ypos }));
	m_CharacterCount++;

	m_SpawnCount++;

	if (m_SpawnCount > 12) {
		m_WaitWave = true;
		m_WaitWaveTimer = 0;
	}
}

void Spawner::Update()
{
	m_WaitWaveTimer += m_Video->getDeltaTime();

	if (m_WaitWaveTimer >= m_WaitWaveTime) {
		if (m_WaitWave) {
			m_WaitWave = false;
			m_ActiveWave++;
			m_SpawnCount = 0;

			m_Multiplier *= 2;
			m_SpawnSpeed = m_SpawnStartSpeed / m_Multiplier;
		}

		m_SpawnTimer += m_Video->getDeltaTime();

		if (m_SpawnTimer >= m_SpawnSpeed) {
			m_SpawnTimer = 0;
			SpawnEnemy();
		}
	}

	for (int i = 0; i < m_CharacterCount; i++)
	{
		m_CharacterList[i].Update();
	}
}

void Spawner::Render()
{
	for (int i = 0; i < m_CharacterCount; i++)
	{
		m_CharacterList[i].Render();
	}
}
