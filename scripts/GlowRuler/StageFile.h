#pragma once
#include "Game.h"

struct Data
{
	int stage[14][19];
};

class StageFile
{
public:
	StageFile();
	~StageFile();

	void CreateData();
	void ChangeData(int no, Data stage);
	Data GetMapData(int no);

private:
	void Save();
	void Load();

private:

	// �쐬�}�b�v�f�[�^
	Data m_createData[10];
};

