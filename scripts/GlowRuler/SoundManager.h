#pragma once
#include <vector>

class Sound;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	
	void Init(int no);
	void Update();
	void Output(int no);

	void CallSound(int no);

private:
	// 必要な音の数に応じて可変式
	std::vector<Sound*> m_pSound;
	int m_soundNum;
	int m_soundCount;
};

