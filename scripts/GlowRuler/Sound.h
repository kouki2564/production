#pragma once
#include "Game.h"

class Sound
{
public:
	Sound();
	~Sound();
	// type : true�cBGM�@false�cSE
	void InitBGM(const int& handle);
	void InitSE(const int& handle);
	void UpdateBGM(int BGMvol);
	void UpdateSE(int SEvol);
	void OnePlay();
	void LoopPlay();
	void Stop();

	bool ChackPlaying() const;
	int GetVol()const { return m_volPow; };

	//bool GetPlaying() { return CheckSoundMem(m_handle); }

private:

	// �T�E���h�̃n���h��
	int m_num;
	int m_handle;
	int m_volume;
	int m_volPow;
};

