#pragma once
#include "Vec2.h"
class Rect
{
public:
	float m_left;	// ����X���W (����)
	float m_top;	// ���Y���W (����)
	float m_right;	// �E��Y���W (�E��)
	float m_bottom;	// ����Y���W (�E��)
	Rect();
	virtual ~Rect();

	void zero() { m_left = 0.0f; m_top = 0.0f; m_right = 0.0f; m_bottom = 0.0f; }

	// �`��
	void Draw(unsigned int color, bool isFill) const;


	/// ������W�ƕ�, ������ۑ�
	void SetLT(float left, float top, float width, float height);


	/// ���S���W�ƕ�, ������ۑ�
	void SetCenter(float x, float y, float width, float height);


	// �K�v�ȏ����擾����
	float GetWidth() const;		// ��`�̕�
	float GetHeight() const;	// ��`�̍���
	Vec2 GetCenter() const;		// ��`�̒��S���W


	/// ��`���m�̓����蔻��
	bool IsCollsion(const Rect& target);

	int IsPointInRect(const Vec2& point);

private:
	
};

