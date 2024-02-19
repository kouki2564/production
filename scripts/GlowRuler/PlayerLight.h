#pragma once
#include "Game.h"
#include "Vec2.h"
#include "Rect.h"

namespace
{
	constexpr int kRadiusMove = 1;
	constexpr int kLightMaxRadius = 24;
	constexpr int kLightMinRadius = 18;

	constexpr int kLightColorSpeed = 15;
	constexpr int kLightAlphaPow = 40;
}

class Player;

class PlayerLight
{
public:
	PlayerLight();
	~PlayerLight();
	void Init(Vec2 player);
	void Update(Vec2 player);
	void Draw();

	void ColorFloorHit(Rect& inColor, int color);
	void ClearHit(Rect& Goal);

	void ColorEffect();

	void InColorEffect();

	// �����̃J���[��n��
	int GetColor() const { return m_color[kLightMaxRadius][kLightMaxRadius]; }
	// �����̃N���A�����n��
	bool GetClearFlag() const { return m_isClearColor[kLightMaxRadius][kLightMaxRadius]; }
	// �����蔻���n��
	Rect GetRect() const { return m_colRect; }
	
	Vec2 GetPos() const { return m_pos; }

	int GetAlpha() const { return m_alpha; }

	void ResetColor();

private:
	// �v���C���[�̔��F
	int m_color[kLightMaxRadius * 2][kLightMaxRadius * 2];
	int m_clearColor;
	int m_R, m_G, m_B;
	int m_alpha;
	Vec2 m_pos;
	// �����蔻��p�̋�`
	Rect m_colRect;
	float m_lightRadius;
	float m_radiusMove;
	bool m_isFloorHit;

	bool m_isClearColor[kLightMaxRadius * 2][kLightMaxRadius * 2];

	int m_posLightDir[3];

	bool m_isInColor;
	bool m_isInApp;
	Vec2 m_circlePos[8];
	int m_EfectAngle;
	int m_efectRad;
};

