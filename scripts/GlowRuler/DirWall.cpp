#include "DirWall.h"
#include "DxLib.h"
#include "Game.h"
#include "Handle.h"
#include <cmath>


DirWall::DirWall():
	m_pos(0.0f,0.0f),
	m_wallDir(kDirDown),
	m_isPass(true)
{
}

DirWall::~DirWall()
{
}

void DirWall::Init(int x, int y, int dir)
{
	m_pos = { static_cast<float>(x) * Game::kGraphWidth + Game::kMapStartPosX + Game::kGraphHalfWidth,
				static_cast<float>(y)* Game::kGraphHeight + Game::kMapStartPosY + Game::kGraphHalfHeight };
	m_colRect.SetCenter(m_pos.x,
		m_pos.y,
		Game::kGraphWidth,
		Game::kGraphHeight);
	// int�^�����ŕ���������
	if (dir == 0) m_wallDir = kDirUp;
	if (dir == 1) m_wallDir = kDirLeft;
	if (dir == 2) m_wallDir = kDirDown;
	if (dir == 3) m_wallDir = kDirRight;
}

void DirWall::Update(Rect& player)
{
	// �����蔻���ǂłƂ�
	// bool�Ɍ��ʂ�����
	// player����bool��ǂݎ��A���s���������Ȃ�
	
	if (!m_colRect.IsCollsion(player))
	{
		// ��
		if (m_wallDir == kDirUp)
		{
			if (player.m_bottom < m_colRect.m_top) m_isPass = false;
			else m_isPass = true;
		}
		// ��
		else if (m_wallDir == kDirLeft)
		{
			if (player.m_right < m_colRect.m_left) m_isPass = false;
			else m_isPass = true;
		}
		// ��
		else if (m_wallDir == kDirDown)
		{
			if (player.m_top > m_colRect.m_bottom) m_isPass = false;
			else m_isPass = true;
		}
		// �E
		else if (m_wallDir == kDirRight)
		{
			if (player.m_left > m_colRect.m_right) m_isPass = false;
			else m_isPass = true;
		}
	}


}

void DirWall::Draw(const Handle& handle)
{
	// ��
	if (m_wallDir == kDirUp)
	{
		DrawRotaGraph2(static_cast<int>(m_pos.x),
			static_cast<int>(m_pos.y),
			Game::kGraphWidth, Game::kGraphHeight, 0.475f, 0, handle.h_data.hi_dirWall, true);
	}
	// ��
	else if (m_wallDir == kDirLeft)
	{
		DrawRotaGraph2(static_cast<int>(m_pos.x),
			static_cast<int>(m_pos.y),
			Game::kGraphWidth, Game::kGraphHeight, 0.475f, 3.14f * 1.5f, handle.h_data.hi_dirWall, true);
	}
	// ��
	else if (m_wallDir == kDirDown)
	{
		DrawRotaGraph2(static_cast<int>(m_pos.x),
			static_cast<int>(m_pos.y),
			Game::kGraphWidth, Game::kGraphHeight, 0.475f, 3.14, handle.h_data.hi_dirWall, true);
	}
	// �E
	else if (m_wallDir == kDirRight)
	{
		DrawRotaGraph2(static_cast<int>(m_pos.x),
			static_cast<int>(m_pos.y),
			Game::kGraphWidth, Game::kGraphHeight, 0.475f, 3.14 * 0.5f, handle.h_data.hi_dirWall, true);
	}
}

// ����ǂ̕����n��
int DirWall::GetDir() const
{
	if (m_wallDir == kDirUp)
	{
		return 0;
	}
	else if (m_wallDir == kDirLeft)
	{
		return 1;
	}
	else if (m_wallDir == kDirDown)
	{
		return 2;
	}
	else if (m_wallDir == kDirRight)
	{
		return 3;
	}
	else return 0;
}
