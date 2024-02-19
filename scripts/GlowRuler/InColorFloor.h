#pragma once
#include "Vec2.h"
#include "Game.h"
#include "Rect.h"

class Handle;

namespace
{
	// �~�̐�
	constexpr int kEffectNum = 4;
	// �ȉ~��x,y�̔��a
	constexpr int kCircleRX = 20;
	constexpr int kCircleRY = 10;
	// �~�̊Ԋu
	constexpr int kEffectSpace = 10;
	// �~�̍ő�ʒu
	constexpr int kEffectMaxY = -40;
	// �~�̏����n�߈ʒu
	constexpr int kDisAppY = -30;
}

class InColorFloor
{
public:
	InColorFloor();
	~InColorFloor();
	void Init(int x, int y, int color);
	void Update();
	void Draw(const Handle& handle);

	void colorEffect();

	// �z�u���W�̐ݒ�
	void SetPos(float x, float y) { m_pos = { x,y }; }
	// �����蔻��
	Rect GetRect() const { return m_colRect; }
	// �F�n��
	int GetColor() const { return m_color; }

private:
	// �z�u���W
	Vec2 m_pos;
	// player�Ƃ̓����蔻��
	Rect m_colRect;
	// �F
	int m_color;

	int m_animaY[kEffectNum];
};

