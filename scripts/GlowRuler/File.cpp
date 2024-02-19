#include "File.h"
#include "DxLib.h"
#include "Game.h"
#include <cassert>
#include <cerrno>

// ���v�񐔃����L���O
File::File()
{
	Load();
}

File::~File()
{
	Save();
}

// �����f�[�^�쐬
void File::CreateData()
{
	for (int i = 0; i < 5; i++)
	{
		m_timeRank[i] = 3000 - (2500 -(i * 500));
	}
}

// ���ʂ̏�������
void File::ChangeTime(int times)
{
	for (int i = 4; i >= 0; i -= 1)
	{
		if (m_timeRank[i] > times)
		{
			if (i != 4) m_timeRank[i + 1] = m_timeRank[i];
			m_timeRank[i] = times;
		}
	}
	Save();
	Load();
}

// �w��ԍ��Ԗڂ̃^�C�����E��
int File::GetTime(int no)
{
	return m_timeRank[no];
}

// �Z�[�u
void File::Save()
{
	// �t�@�C���̘g�쐬
	FILE* Writefp = nullptr;

	// == 0�@�Ńt�@�C������
	if (fopen_s(&Writefp, "TimeData", "wb") == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (m_timeRank[i] > 0)
			{
				fwrite(&m_timeRank[i], sizeof(int), 1, Writefp);
			}
		}

		fclose(Writefp);
	}
	else
	{
		assert(false);
		return;
	}
}

// ���[�h
void File::Load()
{
	FILE* Readfp = nullptr;
	// == 0�@�Ńt�@�C������
	if (fopen_s(&Readfp, "TimeData", "rb") == 0)
	{
		// �z�������int������
		for (int i = 0; i < 5; i++)
		{
			fread(&m_timeRank[i], sizeof(int), 1, Readfp);
		}
		fclose(Readfp);
	}
	// �t�@�C��������(���v���C)���̏����f�[�^�쐬
	else
	{
		CreateData();
		Save();
		Load();
		return;
	}

}