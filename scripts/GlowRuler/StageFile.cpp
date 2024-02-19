#include "StageFile.h"
#include "DxLib.h"
#include <cassert>

StageFile::StageFile()
{
	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 14; y++)
		{
			for (int x = 0; x < 19; x++)
			{
				m_createData[i].stage[y][x] = 0;
			}
		}
	}
	Load();
}

StageFile::~StageFile()
{
	Save();
}

void StageFile::CreateData()
{
}

void StageFile::ChangeData(int no, Data stage)
{
	m_createData[no] = stage;
	Save();
}



// マップの書き出し
Data StageFile::GetMapData(int no)
{
	return m_createData[no];
}

void StageFile::Save()
{
	// 未完成　まだ実装すな
	FILE* fp = nullptr;
	auto err = fopen_s(&fp, "StageData", "wb");
	if (err != errno)
	{
		assert(false);
		return;
	}

	/*for (int i = 0; i < )
	{
		int no = file.first;
		fwrite(&no, sizeof(no), 1, fp);
		Data data = file.second;
		fwrite(&data, sizeof(data), 1, fp);
	}*/

	fclose(fp);
}

void StageFile::Load()
{
}
