#pragma once
#include "Game.h"

class FileQuickTime
{
public:
	FileQuickTime();
	~FileQuickTime();

	void CreateData();
	void ChangeTime(int no, int time);
	int GetTime(int no);


private:

	void Save();
	void Load();

	// �e�X�e�[�W�f�[�^
	int m_stageTime[Game::kStageNum];
};

