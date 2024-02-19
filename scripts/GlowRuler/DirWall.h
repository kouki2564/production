#pragma once
#include "Vec2.h"
#include "Rect.h"

class Handle;

class DirWall
{
	// �����Ă������
	enum Dir
	{
		kDirDown,	// ��
		kDirLeft,	// ��
		kDirRight,	// �E
		kDirUp		// ��
	};
public:
	DirWall();
	~DirWall();
	void Init(int x, int y, int dir);
	void Update(Rect& player);
	void Draw(const Handle& handle);

	// �z�u���W�̐ݒ�
	void SetPos(float x, float y) { m_pos = { x,y }; }
	// �z�u���W�̊l��
	// Vec2 GetRect() { return { m_pos.x + kGraphHalfWidth, m_pos.y + kGraphHalfHeight }; }

	// �����蔻��
	Rect GetRect() const { return m_colRect; }
	bool GetPass() const { return m_isPass; }
	int GetDir() const;

private:
	// �z�u���W
	Vec2 m_pos;
	// player�Ƃ̓����蔻��
	Rect m_colRect;
	// �ʍs����
	Dir m_wallDir;

	bool m_isPass;
};

