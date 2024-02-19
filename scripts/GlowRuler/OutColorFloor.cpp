#include "OutColorFloor.h"
#include "DxLib.h"
#include "Handle.h"


OutColorFloor::OutColorFloor() :
	m_checkColor(0),
	m_pos{ 0,0 },
	m_isClear(false),
	m_alpha(0),
	m_filterAlpha(0),
	m_isFilter(false)
{
	m_dir = 0;
}

OutColorFloor::~OutColorFloor()
{
}

void OutColorFloor::Init(int x, int y, int color)
{
	m_pos = { static_cast<float>(x) * Game::kGraphWidth + Game::kMapStartPosX + Game::kGraphHalfWidth,
				static_cast<float>(y) * Game::kGraphHeight + Game::kMapStartPosY + Game::kGraphHalfHeight };
	m_colRect.SetCenter(m_pos.x,
		m_pos.y,
		Game::kGraphWidth - 1,
		Game::kGraphHeight - 1);
	m_checkColor = color;
}

void OutColorFloor::Update()
{
	if(!m_isClear) m_isClear = true;
}

void OutColorFloor::Draw(const Handle& handle)
{
	// ���F����
	if (m_isClear)
	{
		// ���X�ɒ��F

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
		DrawBox(static_cast<int>(m_pos.x - Game::kGraphHalfWidth),
			static_cast<int>(m_pos.y - Game::kGraphHalfHeight),
			static_cast<int>(m_pos.x + Game::kGraphHalfWidth) - 1,
			static_cast<int>(m_pos.y + Game::kGraphHalfHeight) - 1,
			m_checkColor, true);
		// 240�ɂȂ�܂ŃA���t�@�l�𑝉�
		if (m_alpha < kAlphaMax) m_alpha += kAlphaSpeed;

		if (!m_isFilter)
		{
			if (m_filterAlpha < 100)
				m_filterAlpha += 3;
			else
				m_isFilter = true;
		}
		else
		{
			if (m_filterAlpha >0)
				m_filterAlpha -= 3;
			else
				m_isFilter = false;
		}
	}
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_filterAlpha);
	DrawGraph(static_cast<int>(m_pos.x - Game::kGraphHalfWidth),
		static_cast<int>(m_pos.y - Game::kGraphHalfHeight),
		handle.h_data.hi_ChipFilter,true);
	
	// ���ŃA���t�@�l���������Ă��邽�߁A�����ōĒ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	// �t���[������
	for (int i = 0; i < kBoxNum; i++)
	{
		if (i == 0)
			DrawBox(static_cast<int>(m_pos.x - Game::kGraphHalfWidth) + i,
				static_cast<int>(m_pos.y - Game::kGraphHalfHeight) + i,
				static_cast<int>(m_pos.x + Game::kGraphHalfWidth) - 1 - i,
				static_cast<int>(m_pos.y + Game::kGraphHalfHeight) - 1 - i,
				0xffffff, false);
		else if (i <= 2)
			DrawBox(static_cast<int>(m_pos.x - Game::kGraphHalfWidth) + i,
				static_cast<int>(m_pos.y - Game::kGraphHalfHeight) + i,
				static_cast<int>(m_pos.x + Game::kGraphHalfWidth) - 1 - i,
				static_cast<int>(m_pos.y + Game::kGraphHalfHeight) - 1 - i,
				m_checkColor, false);
		else if (i <= 3)
			DrawBox(static_cast<int>(m_pos.x - Game::kGraphHalfWidth) + i,
				static_cast<int>(m_pos.y - Game::kGraphHalfHeight) + i,
				static_cast<int>(m_pos.x + Game::kGraphHalfWidth) - 1 - i,
				static_cast<int>(m_pos.y + Game::kGraphHalfHeight) - 1 - i,
				0xffffff, false);
	}
}

void OutColorFloor::Effect()
{
	m_dir++;
	if (m_dir > kDirMax) m_dir = 0;

	if (!m_isClear)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - m_dir * kAlphaPow);
			// �t���[������
		if (m_dir < kDrawDirMax)
		{
			for (int i = 0; i < kBoxNum; i++)
			{
				if (i == 0)
					DrawBox(static_cast<int>(m_pos.x - Game::kGraphHalfWidth) + i - m_dir,
						static_cast<int>(m_pos.y - Game::kGraphHalfHeight ) + i - m_dir,
						static_cast<int>(m_pos.x + Game::kGraphHalfWidth) - 1 - i + m_dir,
						static_cast<int>(m_pos.y + Game::kGraphHalfHeight ) - 1 - i + m_dir,
						0xffffff, false);
				else if (i <= 2)
					DrawBox(static_cast<int>(m_pos.x - Game::kGraphHalfWidth) + i - m_dir,
						static_cast<int>(m_pos.y - Game::kGraphHalfHeight ) + i - m_dir,
						static_cast<int>(m_pos.x + Game::kGraphHalfWidth) - 1 - i + m_dir,
						static_cast<int>(m_pos.y + Game::kGraphHalfHeight ) - 1 - i + m_dir,
						m_checkColor, false);
				else if (i <= 3)
					DrawBox(static_cast<int>(m_pos.x - Game::kGraphHalfWidth) + i - m_dir,
						static_cast<int>(m_pos.y- Game::kGraphHalfHeight ) + i - m_dir,
						static_cast<int>(m_pos.x + Game::kGraphHalfWidth) - 1 - i + m_dir,
						static_cast<int>(m_pos.y + Game::kGraphHalfHeight ) - 1 - i + m_dir,
						0xffffff, false);
			}
		}
	}
}

void OutColorFloor::Reset()
{
	m_isClear = false;
	m_alpha = 0;
	m_filterAlpha = 0;
	m_isFilter = false;
}
