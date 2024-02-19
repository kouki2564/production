#include "FileQuickTime.h"
#include "DxLib.h"
#include "Game.h"
#include <cassert>
#include <cerrno>

FileQuickTime::FileQuickTime()
{
	Load();
}

FileQuickTime::~FileQuickTime()
{
	Save();
}

void FileQuickTime::CreateData()
{
	for (int i = 0; i < Game::kStageNum; i++)
	{
		m_stageTime[i] = 100;
	}
}

void FileQuickTime::ChangeTime(int no, int time)
{
	// no�ԃX�e�[�W�̉񐔂��X�V����
	m_stageTime[no] = time;
}

int FileQuickTime::GetTime(int no)
{
	return m_stageTime[no];
}

void FileQuickTime::Save()
{
	// �t�@�C���̘g�쐬
	FILE* fp = nullptr;
	// �t�@�C�����J���Ȃ��Ƃ����[��
	if (fopen_s(&fp, "StageTimeData", "wb") == 0)
	{
		for (int i = 0; i < Game::kStageNum; i++)
		{
			if (m_stageTime[i] > 0)
			{
				fwrite(&m_stageTime[i], sizeof(int), 1, fp);
			}
		}


		fclose(fp);
	}
	else
	{
		assert(false);
		return;
	}

	
}

void FileQuickTime::Load()
{
	FILE* fp = nullptr;
	if (fopen_s(&fp, "StageTimeData", "rb") == 0)
	{
		// �z������̃f�[�^������
		for (int i = 0; i < Game::kStageNum; i++)
		{
			fread(&m_stageTime[i], sizeof(int), 1, fp);
		}
		fclose(fp);
	}
	else
	{
		CreateData();
		Save();
		Load();
		return;
	}
}
