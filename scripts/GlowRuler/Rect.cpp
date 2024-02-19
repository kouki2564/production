#include "Rect.h"
#include <DxLib.h>
#include <cassert>

Rect::Rect() :
	m_left(0.0f),
	m_top(0.0f),
	m_right(0.0f),
	m_bottom(0.0f)
{
}

Rect::~Rect()
{
}

void Rect::Draw(unsigned int color, bool isFill) const
{
	DrawBox(static_cast<int>(m_left), static_cast<int>(m_top), static_cast<int>(m_right), static_cast<int>(m_bottom),
		color, isFill);
}

void Rect::SetLT(float left, float top, float width, float height)
{
	m_left = left;
	m_top = top;
	m_right = left + width;
	m_bottom = top + height;
}

void Rect::SetCenter(float x, float y, float width, float height)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_right = x + width / 2;
	m_bottom = y + height / 2;
}

float Rect::GetWidth() const
{
	assert(m_left <= m_right);	// ���E�̍��W����ւ��`�F�b�N
	return m_right - m_left;
}

float Rect::GetHeight() const
{
	assert(m_top <= m_bottom);	// �㉺�̍��W����ւ��`�F�b�N
	return m_bottom - m_top;
}

Vec2 Rect::GetCenter() const
{
	return Vec2{ (m_left + m_right) / 2, (m_top + m_bottom) / 2 };
}

// Rect���m�̓����蔻��
bool Rect::IsCollsion(const Rect& target)
{
	// ��΂ɓ�����Ȃ��p�^�[�����͂����Ă���
	if (target.m_right < m_left) return false;
	if (target.m_bottom < m_top) return false;
	if (m_right < target.m_left) return false;
	if (m_bottom < target.m_top) return false;

	// ������Ȃ��p�^�[���ȊO�͓������Ă���
	return true;
}

// ����P�_��Rect�̓����蔻��i0:�͈͊O�@1:��̃s�b�^���@2:�͈͓��j
int Rect::IsPointInRect(const Vec2& point)
{
	if (point.x >= m_left &&
		point.x <= m_right &&
		point.y >= m_top &&
		point.y <= m_bottom)
	{
		// ��̃s�b�^���łP
		if (point.x <= m_left + 2 ||
			point.x >= m_right - 2 ||
			point.y <= m_top + 2||
			point.y >= m_bottom - 2) return 1;
		// ����ȊO�͂Q
		else return 2;
	}
	// �͈͊O�͂O
	return false;
}