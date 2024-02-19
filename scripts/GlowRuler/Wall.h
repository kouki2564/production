#pragma once
#include "Vec2.h"
#include "Rect.h"

class Handle;

class Wall
{
public:
	Wall();
	~Wall();
	void Init(int x, int y);
	void Update();
	void Draw(const Handle& handle);

	// �z�u���W�̐ݒ�
	void SetPos(float x, float y) { m_pos = { x,y }; }
	// �z�u���W�̊l��
	// Vec2 GetRect() { return { m_pos.x + kGraphHalfWidth, m_pos.y + kGraphHalfHeight }; }

	// �����蔻��
	Rect GetRect() { return m_colRect; }



private:
	// �z�u���W
	Vec2 m_pos;
	// player�Ƃ̓����蔻��
	Rect m_colRect;
	// �A�j���[�V����(����A������������)
	// int m_animaFrame;

	// ��������Ǘp
	// �����Ȃ��ǂƂ̍��ʉ�
	bool m_isFixed;
	// �ǂ������Ă���r�����ǂ���
	bool m_isMove;
	// �}�E�X�L�[����
	bool m_isClick;
	// �}�E�X���͍��W
	Vec2 m_mousePos;
};

