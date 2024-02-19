#pragma once
#include "Rect.h"

class Rect;

namespace 
{
	// 色変化速度
	constexpr int kColorSpeed = 15;

	// エフェクト
	constexpr int kCircleDir = 50;
	constexpr int kCircleMoveDir = 100;
	constexpr int kCurcleNum = 8;
}

class GoalPoint
{
public:
	GoalPoint();
	~GoalPoint();
	void Init(int& x, int& y);
	void Update(bool& isClear);
	void Draw();

	void Effect();
	void GoalEffect();

	Rect GetRect()const { return m_colRect; }
	int GetColor()const { return m_color; }

	Vec2 GetPos()const { return m_pos; }

private:
	bool m_isApp;
	Rect m_colRect;
	Vec2 m_pos;
	int m_color;
	int m_R;
	int m_G;
	int m_B;
	int m_alpha;
	

	// ゴールエフェクト
	int m_dir;
	Vec2 m_circlePos[kCurcleNum];
	int m_EfectAngle;

	
};

