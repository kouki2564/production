#pragma once
#include "Game.h"

class File
{
public:
	File();
	~File();

	// �S�̃����L���O
	void CreateData();
	void ChangeTime(int time);
	int GetTime(int no);
	
private:

	void Save();
	void Load();

private:
	// �t�@�C���f�[�^
	// �����L���O�f�[�^
	int m_timeRank[5];

	// �e�X�e�[�W�f�[�^
	// int m_stageTime[Game::kStageNum];
};