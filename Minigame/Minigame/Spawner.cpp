#include "Spawner.h"



Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

void Spawner::SpawnWave()
{
	for (int i = 0; i < m_MaxEenmies; i++)
	{
		if (m_CurrentEnemies <= m_MaxEenmies)
		{
			//spawn enemy
		}
	}
}

void Spawner::ClearWave()
{
	for (int i = 0; i < m_MaxEenmies; i++)
	{
		//if enemy Alive
		//enemies-> despawn()
	}
}

void Spawner::Update()
{
	if (m_WaveIsActive)
	{
		for (int i = 0; i < m_MaxEenmies; i++)
		{
			//enemies-> update()
		}
	}
}

void Spawner::Render()
{
	if (m_WaveIsActive)
	{
		for (int i = 0; i < m_MaxEenmies; i++)
		{
			//eneimes-> render()
		}
	}
}
