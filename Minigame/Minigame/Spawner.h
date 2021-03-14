#pragma once
class Spawner
{
private: 
	
	int m_CurrentWave;
	int m_MaxEenmies;
	int m_CurrentEnemies;

	float m_WaveSpeed;

	bool m_WaveIsActive;

public:
	Spawner();
	~Spawner();

	void SpawnWave();
	void ClearWave();

	void Update();
	void Render();


	int GetCurrentWave() { return m_CurrentWave; }

	int GetMaxEnemies() { return m_MaxEenmies; }
	void SetMaxEnemies(int maxEnemies) { m_MaxEenmies = maxEnemies; }

	int GetCurrentEnemies() { return m_CurrentEnemies; }

	float GetWaveSpeed() { return m_WaveSpeed; }
	void SetWaveSpeed(float waveSpeed) { m_WaveSpeed = waveSpeed; }

	bool GetWaveIsActive() { return m_WaveIsActive; }
	void SetWaveIsActive(bool waveActive) { m_WaveIsActive = waveActive; }


};

