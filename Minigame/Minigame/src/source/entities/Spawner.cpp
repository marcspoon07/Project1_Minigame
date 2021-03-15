#include "../../headers/entities/Spawner.h"

Spawner::Spawner()
{
	m_Video = Video::getInstance();
	m_GameState = GameState::getInstance();
	m_Audio = Audio::getInstance();

	m_MaxSpawns = 20;
	
	m_SpawnStartSpeed = 3000;

	m_WaitWaveTime = 5000;
	

	m_RowPositions[0] = 320;
	m_RowPositions[1] = 416;
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

	if (m_SpawnCount > m_MaxSpawns) {
		m_WaitWave = true;
		m_WaitWaveTimer = 0;
	}

	m_DamagedAudio = Resources::getInstance()->Load<AudioClip>("Assets/Audio/UH.ogg");
}

void Spawner::Init()
{
	m_SpawnCount = 0;
	m_Multiplier = 1;
	m_SpawnSpeed = m_SpawnStartSpeed;
	m_SpawnTimer = m_SpawnSpeed;
	m_ActiveWave = 0;
	m_WaitWaveTimer = m_WaitWaveTime;
	m_WaitWave = false;

	m_CharacterCount = 0;
	m_CharacterList.resize(0);
	m_CharacterList.clear();
}

void Spawner::Update()
{
	for (int i = 0; i < m_CharacterCount; i++)
	{
		if (m_CharacterList[i].IsAlive()) {
			m_CharacterList[i].Update();
		}
		else {
			Character::CharacterType type = m_CharacterList[i].getType();
			
			if (m_CharacterList[i].WasEaten()) {
				if (type == Character::CharacterType::WATER || type == Character::CharacterType::NATURE) {
					m_GameState->addPoints(m_CharacterList[i].getPoints());
				}
				else {
					m_GameState->loseHealth();
					m_Audio->PlayAudio(m_DamagedAudio, 128);
				}
			}
			else {

				if (type == Character::CharacterType::WATER || type == Character::CharacterType::NATURE) {
					m_GameState->loseHealth();
					m_Audio->PlayAudio(m_DamagedAudio, 128);
				}
				else {
					m_GameState->addPoints(m_CharacterList[i].getPoints());
				}
			}

			m_CharacterList.erase(m_CharacterList.begin() + i);
			i--;
			m_CharacterCount--;		
		}
	}

	m_WaitWaveTimer += m_Video->getDeltaTime();

	if (m_WaitWaveTimer >= m_WaitWaveTime) {
		if (m_WaitWave) {
			m_WaitWave = false;
			m_ActiveWave++;
			m_SpawnCount = 0;

			m_Multiplier *= 2;
			m_SpawnSpeed = m_SpawnStartSpeed / m_Multiplier;
			m_MaxSpawns *= 2;
		}

		m_SpawnTimer += m_Video->getDeltaTime();

		if (m_SpawnTimer >= m_SpawnSpeed) {
			m_SpawnTimer = 0;
			SpawnEnemy();
		}
	}
}

void Spawner::Render()
{
	for (int i = 0; i < m_CharacterCount; i++)
	{
		m_CharacterList[i].Render();
	}
}
