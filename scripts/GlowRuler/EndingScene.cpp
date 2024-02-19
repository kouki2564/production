#include "EndingScene.h"
#include "DxLib.h"
#include "Game.h"
#include "Sound.h"
#include "Handle.h"

EndingScene::EndingScene() :
	m_clearWidth(0),
	m_startWidth(0),
	m_timeWidth(0),
	m_alpha(0),
	m_isAlpha(false),
	m_appStartTimer(0),
	m_isKey(false),
	m_isTransScene(false),
	m_resultTime(0),
	m_gameMode(0),
	m_efectDir(0),
	m_FadeAlpha(0),
	m_flashTimer(0),
	m_isUpdateSound(false)
{
	m_pos = { (Game::kScreenWidth * 0.1f), Game::kScreenHeight * 0.1f };
	m_RankResult = { 0,0,0,0,0 };

	// �T�E���h
	m_pSound.resize(4);
	for (int i = 0; i < m_pSound.size(); i++)
	{
		m_pSound[i] = new Sound;
	}

	for (int i = 0; i < 5; i++)
	{
		m_rankPosMove[i] = 500;
	}
}

EndingScene::~EndingScene()
{
	m_pSound[0]->Stop();
	for (int i = 0; i < m_pSound.size(); i++)
	{
		delete m_pSound[i];
		m_pSound[i] = nullptr;
	}
}

void EndingScene::Init(int time, int gameMode, int BGM, int SE, const Rank& timerank, const Handle& handle)
{
	m_clearWidth = GetDrawStringWidth("CLEAR", static_cast<int>(strlen("CLEAR")));
	m_startWidth = GetDrawStringWidth("PRESS SPACE", static_cast<int>(strlen("PRESS SPACE")));
	m_timeWidth = GetDrawStringWidth("�L�^  �@ ��", static_cast<int>(strlen("�L�^  �@ ��")));
	m_gameMode = gameMode;
	m_resultTime = time;
	m_RankResult = timerank;

	

	// ���U���gBGM
	m_pSound[0]->InitSE(handle.h_data.hm_S_12);
	// ���艹
	m_pSound[1]->InitSE(handle.h_data.hm_S_01);
	// �L�^�X�V��
	m_pSound[2]->InitSE(handle.h_data.hm_S_09);
	// �����L���O�ړ���
	m_pSound[3]->InitSE(handle.h_data.hm_S_11);

	// ���ʍX�V
	for (int i = 0; i < m_pSound.size(); i++)
	{
		m_pSound[i]->UpdateSE(SE);
	}

	m_pSound[0]->OnePlay();
}

void EndingScene::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_PAD1);
	int hitSpace = CheckHitKey(KEY_INPUT_SPACE);
	if (m_alpha < 255 && !m_isKey)
	{
		m_alpha += 5;
	}
	if (m_alpha >= 255)
	{
		for (int i = 0; i < 5; i++)
		{
			if (i == 0 || m_rankPosMove[i - 1] <= 0)
			{
				if (m_rankPosMove[i] > 0)
				{
					m_rankPosMove[i] -= 25;
					if (m_rankPosMove[i] == 500 - 25)
					{
						m_pSound[3]->OnePlay();
					}
				}
			}
		}
		m_alpha = 255;
		m_isAlpha = true;
		if ((hitSpace || pad == PAD_INPUT_1) && !m_isKey)
		{
			m_pSound[1]->OnePlay();
			m_isKey = true;
		}
	}
	if (m_appStartTimer < 120)
	{
		if (!m_isKey) m_appStartTimer++;
		else
		{
			m_appStartTimer += 12;
		}
	}
	else m_appStartTimer = 0;

	if (m_isKey)
	{
		if (m_FadeAlpha < 255)
			m_FadeAlpha += 5;
		if (m_FadeAlpha >= 255)
			m_isTransScene = true;
	}

	if (m_efectDir <= Game::kScreenWidth * 0.5f)
		m_efectDir += 20;

	if (m_flashTimer < 40)
	{
		m_flashTimer++;
	}
	else
	{
		m_flashTimer = 0;
	}
}

void EndingScene::Draw(const Handle& handle)
{
	// �G�t�F�N�g
	/*
	for (int i = 10; i >= 0; i--)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (i * 25));
		DrawCircle(static_cast<int>(Game::kScreenWidth * 0.5f), static_cast<int>(Game::kScreenHeight * 0.5f), m_efectDir + (i * 30), 0xee82ee, true);
	}
	*/
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	DrawBox(0, 0, Game::kScreenWidth + 1, Game::kScreenHeight + 1, 0xba70d3, true);
	DrawBox(Game::kScreenWidth + 1, Game::kScreenHeight + 1, static_cast<int>(Game::kScreenWidth * 0.7f), 0, 0x603d90, true);
	// �e�L�X�g
	DrawStringToHandle(static_cast<int>(m_pos.x - (m_clearWidth * 0.5f)), static_cast<int>(m_pos.y), "C L E A R", 0xb22222,handle.h_data.hf_starry_64, 0xffffff);
	
	if (m_gameMode == 0)
	{
		// ����̉�
		if((m_resultTime == m_RankResult.time_1 || m_resultTime == m_RankResult.time_2 ||
			m_resultTime == m_RankResult.time_3 || m_resultTime == m_RankResult.time_4 ||
			m_resultTime == m_RankResult.time_5)
			&& m_flashTimer <= 20
			&& m_rankPosMove[4] <= 0)
		{
			if (!m_isUpdateSound)
			{
				m_isUpdateSound = true;
				m_pSound[2]->OnePlay();
			}
			DrawFormatString2FToHandle(Game::kScreenWidth * 0.175f, Game::kScreenHeight * 0.4f,
				0xffd300, 0x8986eb, handle.h_data.hf_util_72, "�@�L�^  %d ��", m_resultTime);
			DrawFormatString2FToHandle(Game::kScreenWidth * 0.175f, Game::kScreenHeight * 0.6f,
				0xffd300, 0x8986eb, handle.h_data.hf_starry_64, "NEW RECORD !!!!", m_resultTime);
		}
		else if ((m_resultTime == m_RankResult.time_1 || m_resultTime == m_RankResult.time_2 ||
			m_resultTime == m_RankResult.time_3 || m_resultTime == m_RankResult.time_4 ||
			m_resultTime == m_RankResult.time_5)
			&& m_rankPosMove[4] <= 0)
		{
			DrawFormatString2FToHandle(Game::kScreenWidth * 0.175f, Game::kScreenHeight * 0.4f,
				0xffffff, 0x8986eb, handle.h_data.hf_util_72, "�@�L�^  %d ��", m_resultTime);
			DrawFormatString2FToHandle(Game::kScreenWidth * 0.175f, Game::kScreenHeight * 0.6f,
				0xffffff, 0x8986eb, handle.h_data.hf_starry_64, "NEW RECORD !!!!", m_resultTime);
		}
		else
		{
			DrawFormatString2FToHandle(Game::kScreenWidth * 0.175f, Game::kScreenHeight * 0.4f,
				0xffffff, 0x8986eb, handle.h_data.hf_util_72, "�@�L�^  %d ��", m_resultTime);
		}

		// �����L���O
		DrawStringToHandle(static_cast<int>((Game::kScreenWidth * 0.78f)), static_cast<int>(Game::kScreenHeight * 0.075f), "All Stage\n Ranking",
			0xb22222, handle.h_data.hf_starry_48, 0xffffff);

		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[0],Game::kScreenHeight * 0.3f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48,"�Pst�@%d ��", m_RankResult.time_1);
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f - 5) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[1], Game::kScreenHeight * 0.4f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Qnd�@%d ��",m_RankResult.time_2);
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[2], Game::kScreenHeight * 0.5f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Rrd�@%d ��", m_RankResult.time_3);0x8986eb,
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[3], Game::kScreenHeight * 0.6f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Sth�@%d ��", m_RankResult.time_4);
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[4], Game::kScreenHeight * 0.7f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Tth�@%d ��", m_RankResult.time_5);

		// �L�^�X�V�ŉ��F�������L���O�_��
		if (m_resultTime == m_RankResult.time_1 && m_flashTimer <= 20 && m_rankPosMove[4] <= 0)
		{
			DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[0], Game::kScreenHeight * 0.3f, 0xffd300, 0x8986eb,
				handle.h_data.hf_util_48, "�Pst�@%d ��", m_RankResult.time_1);
		}
		else if (m_resultTime == m_RankResult.time_2 && m_flashTimer <= 20 && m_rankPosMove[4] <= 0)
		{
			DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f - 5) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[1], Game::kScreenHeight * 0.4f, 0xffd300, 0x8986eb,
				handle.h_data.hf_util_48, "�Qnd�@%d ��", m_RankResult.time_2);
		}
		else if (m_resultTime == m_RankResult.time_3 && m_flashTimer <= 20 && m_rankPosMove[4] <= 0)
		{
			DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[2], Game::kScreenHeight * 0.5f, 0xffd300, 0x8986eb,
				handle.h_data.hf_util_48, "�Rrd�@%d ��", m_RankResult.time_3);
		}
		else if (m_resultTime == m_RankResult.time_4 && m_flashTimer <= 20 && m_rankPosMove[4] <= 0)
		{
			DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[3], Game::kScreenHeight * 0.6f, 0xffd300, 0x8986eb,
				handle.h_data.hf_util_48, "�Sth�@%d ��", m_RankResult.time_4);
		}
		else if (m_resultTime == m_RankResult.time_5 && m_flashTimer <= 20 && m_rankPosMove[4] <= 0)
		{
			DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[4], Game::kScreenHeight * 0.7f, 0xffd300, 0x8986eb,
				handle.h_data.hf_util_48, "�Tth�@%d ��", m_RankResult.time_5);
		}
		
		

		
		
	}
	else if (m_gameMode == 1)
	{
		// ����̉�
		DrawFormatString2FToHandle(Game::kScreenWidth * 0.175f, Game::kScreenHeight * 0.4f,
			0xffffff, 0x8986eb, handle.h_data.hf_util_72, "�@�L�^  %d ��", m_resultTime);

		// �����L���O
		DrawStringToHandle(static_cast<int>((Game::kScreenWidth * 0.78f)), static_cast<int>(Game::kScreenHeight * 0.075f), "All Stage\n Ranking",
			0xb22222, handle.h_data.hf_starry_48, 0xffffff);

		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[0], Game::kScreenHeight * 0.3f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Pst�@%d ��", m_RankResult.time_1);
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f - 5) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[1], Game::kScreenHeight * 0.4f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Qnd�@%d ��", m_RankResult.time_2);
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[2], Game::kScreenHeight * 0.5f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Rrd�@%d ��", m_RankResult.time_3);
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[3], Game::kScreenHeight * 0.6f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Sth�@%d ��", m_RankResult.time_4);
		DrawFormatString2FToHandle((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30 + m_rankPosMove[4], Game::kScreenHeight * 0.7f, 0xffffff, 0x8986eb,
			handle.h_data.hf_util_48, "�Tth�@%d ��", m_RankResult.time_5);

		DrawStringToHandle(static_cast<int>((Game::kScreenWidth * 0.825f) - (m_timeWidth * 0.5f) - 30) + m_rankPosMove[4], static_cast<int>(Game::kScreenHeight * 0.85f),
				"�����L���O�ɂ�\n�@�@�`�������W���Ă݂悤 !!", 0xffffff, handle.h_data.hf_util_24);
	}
	if (m_isAlpha && m_appStartTimer < 60)
	{
		DrawString(static_cast<int>(Game::kScreenWidth * 0.2f), static_cast<int>(Game::kScreenHeight * 0.8f), "PRESS�@ SPACE or A", 0xffffff);
	}
	// �t�F�[�h�A�E�g�p
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_FadeAlpha);
	DrawBox(0, 0, Game::kScreenWidth + 1, Game::kScreenHeight + 1, 0x000000, true);
}
