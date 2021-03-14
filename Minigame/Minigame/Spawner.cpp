#include "Spawner.h"



Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

void Spawner::SpawnWave()
{
	m_Enemies = new Enemy [m_MaxEenmies];
	m_CurrentEnemies = 0;
	for (int i = 0; i < m_MaxEenmies; i++)
	{
		if (m_CurrentEnemies <= m_MaxEenmies)
		{
			m_Enemies[i].InitType();
			//init velocity
			//init position
			//
			m_CurrentEnemies++;
		}
	}
}

void Spawner::ClearWave()
{
	for (int i = 0; i < m_MaxEenmies; i++)
	{
		//if enemy Alive
		//enemies-> despawn()
		m_CurrentEnemies--;
	}
}

void Spawner::Update()
{
	if (m_WaveIsActive)
	{
		for (int i = 0; i < m_MaxEenmies; i++)
		{
			m_Enemies[i].Update();
		}
	}
}

void Spawner::Render()
{
	if (m_WaveIsActive)
	{
		for (int i = 0; i < m_MaxEenmies; i++)
		{
			m_Enemies[i].Render();
		}
	}
}
