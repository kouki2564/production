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
	// �K�v�ȉ��̐��ɉ����ĉώ�
	std::vector<Sound*> m_pSound;
	int m_soundNum;
	int m_soundCount;
};

