#pragma once
#include "Character.h"
#include "../Video.h"
#include "../GameState.h"
#include "../Audio.h"

class Spawner
{
private: 
	uint32 m_ActiveWave;

	uint32 m_SpawnCount;
	uint32 m_MaxSpawns;

	uint32 m_Multiplier;

	uint32 m_SpawnStartSpeed;
	uint32 m_SpawnSpeed;

	uint32 m_SpeedupTimer;
	uint32 m_SpawnTimer;

	uint32 m_WaitWaveTimer;
	uint32 m_WaitWaveTime;

	ResourceId m_DamagedAudio;

	std::vector<Character> m_CharacterList;
	size_t m_CharacterCount;

	bool m_WaitWave;

	int m_RowPositions[2];

	Video* m_Video;
	Audio* m_Audio;
	GameState* m_GameState;
public:
	Spawner();
	~Spawner();
	
	void SpawnEnemy();

	void Init();
	void Update();
	void Render();

	std::vector<Character>* getCharacterList() { return &m_CharacterList; }
	uint32 getMultiplier() { return m_Multiplier; }
};

