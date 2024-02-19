#pragma once
#include "Vec2.h"

class EfectColor
{
public:
	EfectColor();
	~EfectColor();

	void Init(Vec2 pos, int color);
	void Update();
	void Draw();

	bool GetStart()const { return m_isStart; }

	void ClearChack(int efeNum,Vec2 goalPos);

	void Reset();

private:
	// �G�t�F�N�g
	Vec2 m_pos;
	Vec2 m_firstPos;
	int m_color;
	int m_speed;
	int m_rad;
	bool m_isStart;

	bool m_isClear;
	bool m_isReduct;

	// �S�[������G�t�F�N�g
	Vec2 m_goalPos;
	bool m_isApp;
	int m_goalRad;
};

