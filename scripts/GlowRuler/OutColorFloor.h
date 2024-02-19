#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Game.h"

namespace
{
	constexpr int kAlphaMax = 240;
	constexpr int kAlphaSpeed = 8;

	// Box�̕������i�񐔁j
	constexpr int kBoxNum = 4;

	// �G�t�F�N�g�p
	constexpr int kDirMax = 100;
	constexpr int kDrawDirMax = 30;
	constexpr int kAlphaPow = 10;

}

class Handle;

class OutColorFloor
{
public:
	OutColorFloor();
	~OutColorFloor();
	void Init(int x, int y, int color);
	void Update();
	void Draw(const Handle& handle);

	void Effect();

	// �z�u���W�̐ݒ�
	void SetPos(float x, float y) { m_pos = { x,y }; }
	// �����蔻��
	Rect GetRect() const { return m_colRect; }

	Vec2 GetPos() const { return m_pos; }

	// �F�n��
	int GetColor() const { return m_checkColor; }

	// �h��ꂽ����
	bool GetChack() const { return m_isClear; }

	void Reset();

private:
	// �ǃO���t�B�b�N(�摜�f�[�^����)
	// int m_handle;

	// �z�u���W
	Vec2 m_pos;
	// player�Ƃ̓����蔻��
	Rect m_colRect;
	// ����ׂ��F
	int m_checkColor;
	// ���F����
	bool m_isClear;
	// ���F�����̃A���t�@�l
	int m_alpha;

	// �L����G�t�F�N�g
	int m_dir;

	int m_filterAlpha;
	int m_isFilter;
};

