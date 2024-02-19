#include "GameBg.h"
#include "DxLib.h"
#include "Game.h"

GameBg::GameBg() :
	m_dir(10),
	m_angle_R(0),
	m_angle_L(360),
	m_timer(199),
	m_alpha(0),
	m_isAlpha(true),
	m_isColor(false),
	m_isClear(false),
	m_diaNo(0)
{
	m_dia.pos = {0,0 };
	m_dia.tripos = { m_dia.pos.x + 100, m_dia.pos.y };
	m_dia.color = 0xffffff;
}

GameBg::~GameBg()
{
}

void GameBg::Init(int no, int color)
{
	m_diaNo = no;
	m_dia.color = color;
	if(m_diaNo % 2 == 0)
		m_dia.pos = { static_cast<float>(50 + GetRand(Game::kScreenWidth * 0.25f - 100)), static_cast<float>(50 + GetRand(Game::kScreenHeight - 100)) };
	else
		m_dia.pos = { static_cast<float>(Game::kScreenWidth * 0.75f + 50 + GetRand(Game::kScreenWidth * 0.25f - 100)), static_cast<float>(50 + GetRand(Game::kScreenHeight - 100)) };
}

void GameBg::Update()
{
	// ��]�p�̍X�V
	if (!m_isColor)
	{
		if (m_angle_R < 359) m_angle_R += 0.5f;
		else m_angle_R = 0;

		if (m_angle_L > 1) m_angle_L -= 0.5f;
		else m_angle_L = 360;
	}
	else
	{
		if (m_angle_R < 359) m_angle_R += 2.0f;
		else m_angle_R = 0;

		if (m_angle_L > 1) m_angle_L -= 2.0f;
		else m_angle_L = 360;
	}

	// �T�b�� or �S�[���J�����ɋN��
	if (m_timer > 200 || m_isColor)
	{
		m_timer = 0;
		m_isAlpha = false;
	}

	// �t�F�[�h����
	Fade(m_isAlpha);
	
	if (m_alpha == 0)
	{
		// �ꏊ�X�V
		if (m_diaNo % 2 == 0)
			m_dia.pos = { static_cast<float>(GetRand(Game::kScreenWidth * 0.25f - 200)), static_cast<float>(50 + GetRand(Game::kScreenHeight - 100)) };
		else
			m_dia.pos = { static_cast<float>(Game::kScreenWidth * 0.75f + GetRand(Game::kScreenWidth * 0.25f - 200)), static_cast<float>(50 + GetRand(Game::kScreenHeight - 100)) }; 


		m_dia.tripos = { m_dia.pos.x + 100, m_dia.pos.y };
	}
	if (m_isColor)
	{
		m_isClear = true;
	}
	m_isColor = false;
	m_timer++;
	
}

void GameBg::Draw()
{
	double angle_R_a = m_angle_R + 120;
	double angle_R_b = m_angle_R + 240;
	double angle_L_a = m_angle_L + 120;
	double angle_L_b = m_angle_L + 240;

	if(angle_R_a >= 360) angle_R_a -= 360;
	if(angle_R_b >= 360) angle_R_b -= 360;
	if (angle_L_a <= 0) angle_L_a = 360;
	if(angle_L_b <= 0) angle_L_b = 360;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);

	if (m_isClear)
	{
		if (m_diaNo % 2 == 0)
		{
			// (3.14 / 180) = 0.0174

			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f * 5) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f * 5) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f * 5) * m_dir),
				m_dia.color, true);
			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f * 5) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f * 5) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f * 5) * -m_dir),
				m_dia.color, true);

			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f * 5) * m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f * 5) * m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f * 5) * m_dir), 5, m_dia.color, true);

			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f * 5) * -m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f * 5) * -m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f * 5) * -m_dir), 5, m_dia.color, true);
		}
		else
		{
			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f * 5) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f * 5) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f * 5) * m_dir),
				m_dia.color, true);
			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f * 5) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f * 5) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f * 5) * -m_dir),
				m_dia.color, true);


			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f * 5) * m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f * 5) * m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f * 5) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f * 5) * m_dir), 5, m_dia.color, true);

			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f * 5) * -m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f * 5) * -m_dir), 5, m_dia.color, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f * 5) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f * 5) * -m_dir), 5, m_dia.color, true);
		}
	}
	else
	{
		if (m_diaNo % 2 == 0)
		{
			// (3.14 / 180) = 0.0174

			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f) * m_dir),
				0xffffff, true);
			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f) * -m_dir),
				0xffffff, true);


			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f ) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f ) * m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f ) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f ) * m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f ) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f ) * m_dir), 5, 0xffffff, true);

			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_R * 0.0174f ) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_R * 0.0174f ) * -m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_a * 0.0174f ) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_a * 0.0174f ) * -m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_R_b * 0.0174f ) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_R_b * 0.0174f ) * -m_dir), 5, 0xffffff, true);
		}
		else
		{
			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f) * m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f) * m_dir),
				0xffffff, true);
			DrawTriangle(static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f) * -m_dir),
				static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f) * -m_dir),
				0xffffff, true);


			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f ) * m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f ) * m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f ) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f ) * m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f ) * m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f ) * m_dir), 5, 0xffffff, true);

			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(m_angle_L * 0.0174f ) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(m_angle_L * 0.0174f ) * -m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_a * 0.0174f ) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_a * 0.0174f ) * -m_dir), 5, 0xffffff, true);
			DrawCircle (static_cast<int>(m_dia.tripos.x + cos(angle_L_b * 0.0174f ) * -m_dir), static_cast<int>(m_dia.tripos.y + sin(angle_L_b * 0.0174f ) * -m_dir), 5, 0xffffff, true);
		}
	}

	
}
// �t�F�[�h����
void GameBg::Fade(bool isAlpha)
{
	// �����t�F�[�h�A�E�g
	if (isAlpha == true)
	{
		if (m_alpha < 255 - 17)
		{
			m_dir += 2;
			m_alpha += 17;
		}
		else m_alpha = 255;
	}
	// �t�F�[�h�C��
	else
	{
		if (m_alpha > 17)
		{
			m_dir -= 2;
			m_alpha -= 17;
		}
		else m_alpha = 0;
	}
	if (m_alpha == 0) m_isAlpha = true;
}
