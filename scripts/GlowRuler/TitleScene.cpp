#include <iostream>
#include <string>
#include "TitleScene.h"
#include "DxLib.h"
#include "Game.h"
#include "Window.h"
#include "Sound.h"
#include "Handle.h"

using namespace std;

TitleScene::TitleScene() :
	m_titleWidth(0),
	m_startWidth(0),
	m_selectWidth(0),
	m_alpha(0),
	m_isAlpha(false),
	m_appStartTimer(0),
	m_appSelectTimer(0),
	m_isKey(false),
	m_isTransScene(false),
	m_startNum(1),
	m_isRastHit(false),
	m_gameMode(0),
	m_menuNum(0),
	m_cursorMove(0),
	m_cursorMoveVec(1),
	m_isEnd(false),
	m_isMaker(false),
	m_isSetting(false),
	m_isCredit(false),
	m_isWindow(false)
{
	m_pWindow = new Window;
	m_pos = { (Game::kScreenWidth * 0.5f), 0.0f};
	m_cursorPos = { 0,0 };
	m_pSound.resize(3);
	for (int i = 0; i < m_pSound.size(); i++)
	{
		m_pSound[i] = new Sound;
	}
	

	//Bg�֘A
	m_bg.resize(9);
	for (int i = 0; i < 9; i++)
	{
		m_bg[i].m_bgPos = { static_cast<float>(GetRand(1800) - 100),-100.0f };
		m_bg[i].m_isLight = false;
		if(GetRand(1) == 0)
			m_bg[i].m_bgLightMove = { 10.0f, 20.0f };
		else
			m_bg[i].m_bgLightMove = { - 10.0f, 20.0f };
		m_bg[i].m_moveTimer = GetRand(15);;

		m_bg[i].m_wavePos = { 0,0 };
		m_bg[i].m_isWave = false;
		m_bg[i].m_waveDir = 0;

		// �F
		if (i % 3 == 0) m_bg[i].m_bgColor = 0xff69b4;
		else if(i % 3 == 1) m_bg[i].m_bgColor = 0x39ff14;
		else m_bg[i].m_bgColor = 0x00aeef;
		// �^�C�}�[
		m_bg[i].m_bgCoolTimer = i * 30;
	}
	
}

TitleScene::~TitleScene()
{
	delete m_pWindow;
	m_pWindow = nullptr;
	m_pSound[0]->Stop();
	for (int i = 0; i < m_pSound.size(); i++)
	{
		delete m_pSound[i];
		m_pSound[i] = nullptr;
	}
}

void TitleScene::Init( int light, int BGM, int SE, const Handle& handle)
{
	this->SetUti(BGM, SE,light);
	if(m_titleWidth < 0) m_titleWidth = GetDrawStringWidth("Color Dust", static_cast<int>(strlen("Color Dust")));
	m_startWidth = GetDrawStringWidth("MODE:[����]  SELECT[�� ��]  START:[SPACE]", static_cast<int>(strlen("MODE:[����]  SELECT[�� ��]  START:[SPACE]")));
	m_selectWidth = 400;

	m_cursorPos.x = m_pos.x - (m_selectWidth * 0.5f) - 15;
	m_pWindow->Init(handle);

	
	
	// �^�C�g��BGM
	m_pSound[0]->InitBGM(handle.h_data.hm_B_0);
	// �J�[�\����
	m_pSound[1]->InitSE(handle.h_data.hm_S_00);
	// ���艹
	m_pSound[2]->InitSE(handle.h_data.hm_S_01);

	// ���ʍX�V
	for (int i = 0; i < m_pSound.size(); i++)
	{
		if (i == 0) m_pSound[i]->UpdateBGM(BGM);
		else m_pSound[i]->UpdateSE(SE);
	}

	m_pSound[0]->LoopPlay();
}

void TitleScene::Update()
{
	// ���ʍX�V
	for (int i = 0; i < m_pSound.size(); i++)
	{
		if (i == 0) m_pSound[i]->UpdateBGM(m_pWindow->GetBGM());
		else m_pSound[i]->UpdateSE(m_pWindow->GetSE());
	}

	// ���j���[�I���@�\���㉺�L�[
	int pad = GetJoypadInputState(DX_INPUT_PAD1);
	// ��
	int hitU = CheckHitKey(KEY_INPUT_UP); 
	int hitD = CheckHitKey(KEY_INPUT_DOWN);
	// �X�e�[�W�I���@�\�����E�L�[
	int hitL = CheckHitKey(KEY_INPUT_LEFT);
	int hitR = CheckHitKey(KEY_INPUT_RIGHT);

	// ����@�X�y�[�X�L�[
	int hitSpace = CheckHitKey(KEY_INPUT_SPACE);

	//////////////////////
	// �����t�F�[�h�C�� //
	//////////////////////

	// �^�C�g���ʒu����
	if (m_pos.y < Game::kScreenHeight * 0.25f)
	{
		m_pos.y += 2.0f;
	}
	// �^�C�g���o���r���̃A���t�@
	if (m_alpha < 255 && !m_isKey)
	{
		m_alpha++;
	}
	// �^�C�g���t�F�[�h�C���̃V���[�g�J�b�g
	if (m_pos.y > 2.0f && m_alpha > 1)
	{
		if ((hitSpace || pad == PAD_INPUT_1) && !m_isRastHit && !m_isAlpha)
		{
			m_pos.y = Game::kScreenHeight * 0.25f;
			m_alpha = 255;
			m_isRastHit = true;
		}
	}
	// ���j���[��\��������t���O
	if (m_alpha >= 255) m_isAlpha = true;


	//////////////
	// �L�[���� //
	//////////////

	// �t�F�[�h�C���ォ�瑀��\
	if (m_isAlpha && !m_isRastHit && !m_isKey)
	{
		// �E�B���h�E���o�Ă���Ƃ��̓^�C�g�����삵�Ȃ�
		if (!m_isWindow)
		{
			// ���j���[�I���@�㉺�L�[
			if (hitU || pad == PAD_INPUT_UP)
			{
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				if (m_menuNum > 0) m_menuNum--;
				else m_menuNum = 4;
			}
			if (hitD || pad == PAD_INPUT_DOWN)
			{
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				if (m_menuNum < 4) m_menuNum++;
				else m_menuNum = 0;
			}
			// �X�e�[�W�I���@���E�L�[�@(�I���X�^�[�g�ɃJ�[�\�����킹�����̂�)
			if (m_menuNum == 1)
			{
				if (hitR || pad == PAD_INPUT_RIGHT)
				{
					m_pSound[1]->OnePlay();
					m_pSound[1]->OnePlay();
					m_pSound[1]->OnePlay();
					if (m_startNum < Game::kStageNum - 1)m_startNum++;
					else m_startNum = 1;
				}
				if (hitL || pad == PAD_INPUT_LEFT)
				{
					m_pSound[1]->OnePlay();
					m_pSound[1]->OnePlay();
					m_pSound[1]->OnePlay();
					if (m_startNum > 1)m_startNum--;
					else m_startNum = Game::kStageNum - 1;
				}
			}
			// �e���j���[����
			if (m_menuNum == 0)
			{
				// TA���[�h
				m_gameMode = 0;
				// �J�[�\���ʒu�ړ�
				m_cursorPos.y = m_pos.y + 350 + (40 * m_menuNum) + 12;
				if (hitSpace || pad == PAD_INPUT_1)
				{
					m_pSound[2]->OnePlay();
					m_isKey = true;
				}
			}
			else if (m_menuNum == 1)
			{
				// �I�����[�h
				m_gameMode = 1;
				m_cursorPos.y = m_pos.y + 350 + (40*m_menuNum) + 12;
				if (hitSpace || pad == PAD_INPUT_1)
				{
					m_pSound[2]->OnePlay();
					m_isKey = true;
				}
			}
			/*
			else if (m_menuNum == 2)				// ���[�J�[���[�h
			{
				m_gameMode = 2;
				m_cursorPos.y = m_pos.y + 350 + (40*m_menuNum) + 12;
				if (hitSpace)
				{
					m_pSound[2]->OnePlay();
					m_isMaker = true;
				}
			}
			*/
			else if (m_menuNum == 2)
			{
				m_cursorPos.y = m_pos.y + 350 + (40 * m_menuNum) + 12;
				// �ݒ�E�C���h�E�\��
				if (hitSpace || pad == PAD_INPUT_1)
				{
					m_pSound[2]->OnePlay();
					m_isSetting = true;
				}
			}
			else if (m_menuNum == 3)
			{
				m_cursorPos.y = m_pos.y + 350 + (40 * m_menuNum) + 12;
				// �I���t���O
				if (hitSpace || pad == PAD_INPUT_1)
				{
					m_pSound[2]->OnePlay();
					m_isEnd = true;
				}
			}
			else if (m_menuNum == 4)
			{
				m_cursorPos.y = m_pos.y + 350 + (40 * m_menuNum) + 12;
				// �����\�L�E�C���h�E�\��
				if (hitSpace || pad == PAD_INPUT_1)
				{
					m_pSound[2]->OnePlay();
					m_isCredit = true;
				}
			}
		}

		// �E�C���h�E���o�Ă��邩
		if (m_isMaker || m_isSetting || m_isCredit)m_isWindow = true;
		else m_isWindow = false;

		// �E�C���h�E�\��
		if (m_isMaker) m_pWindow->Maker();
		else if (m_isSetting) m_pWindow->Setting();
		else if (m_isCredit) m_pWindow->Credit();
		else m_pWindow->Close();

		// �E�C���h�E����������false��
		if (m_pWindow->GetGoMakeFlag())
		{
			m_isWindow = false;
			m_isKey = true;
		}
		m_isMaker = m_pWindow->GetMakerFlag();
		m_isSetting = m_pWindow->GetSettingFlag();
		m_isCredit = m_pWindow->GetCreditFlag();
	}
	// ���O�t���[���ł̃L�[��������
	if (hitU || hitD || hitL || hitR || hitSpace || pad) m_isRastHit = true;
	else m_isRastHit = false;

	// �X�e�[�W�I�����̃A�j���[�V����
	if (m_cursorMove >= 10)
		m_cursorMoveVec = -1;
	if (m_cursorMove <= 0)
		m_cursorMoveVec = 1;
	m_cursorMove += m_cursorMoveVec;

	////////////////////////
	// �t�F�[�h�A�E�g���� //
	////////////////////////

	if (!m_isWindow && m_appStartTimer < 120)
	{
		if (m_isKey)
		{
			m_appStartTimer += 12;
			if (m_alpha > 0) m_alpha -= 5;
			else m_isTransScene = true;
		}
	}
	else m_appStartTimer = 0;

	// bg
	for (int i = 0; i < 9; i++)
	{
		// ����J�n
		if(m_bg[i].m_bgCoolTimer > 300)
		{
			m_bg[i].m_bgPos += m_bg[i].m_bgLightMove;

			// 30�t���[�����Ƃ�x�i�s�������]
			if (m_bg[i].m_moveTimer > 40)
			{
				m_bg[i].m_moveTimer = GetRand(15);
				m_bg[i].m_bgLightMove.x = - m_bg[i].m_bgLightMove.x;
				m_bg[i].m_isWave = true;
				m_bg[i].m_waveDir = 0;
				m_bg[i].m_wavePos = m_bg[i].m_bgPos;
			}
			else m_bg[i].m_moveTimer++;
		}
		

		// ��O�Ȃ珉���ʒu���Đݒ�
		if (m_bg[i].m_bgPos.y > 930 || m_bg[i].m_bgPos.x < -30 || m_bg[i].m_bgPos.x > Game::kScreenWidth +30)
		{
			m_bg[i].m_bgPos = { static_cast<float>(GetRand(1800) - 100), -100.0f };
			if (GetRand(1) == 0)
				m_bg[i].m_bgLightMove = { 10.0f, 20.0f };
			else
				m_bg[i].m_bgLightMove = { -10.0f, 20.0f };
			m_bg[i].m_bgCoolTimer = 0;
		}

		if (m_bg[i].m_isWave)
		{
			if (m_bg[i].m_waveDir < 200)
				m_bg[i].m_waveDir += 6;
			else
			{
				m_bg[i].m_waveDir = 0;
				m_bg[i].m_isWave = false;
			}
		}

		// �^�C�}�[
		m_bg[i].m_bgCoolTimer++;
	}
}



void TitleScene::Draw(const Handle& handle)
{
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	// Bg
	for (int i = 0; i < 9; i++)
	{
		DrawCircle(static_cast<int>(m_bg[i].m_bgPos.x), static_cast<int>(m_bg[i].m_bgPos.y), 6, m_bg[i].m_bgColor, true);
		if (m_bg[i].m_isWave)
		{
			if(m_alpha > 255 - (m_bg[i].m_waveDir * 2 - (400 - 255)))
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (m_bg[i].m_waveDir * 2 - (400-255)));
			DrawCircle(static_cast<int>(m_bg[i].m_wavePos.x), static_cast<int>(m_bg[i].m_wavePos.y), m_bg[i].m_waveDir, m_bg[i].m_bgColor, false);
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);

	//// �^�C�g��
	//DrawExtendGraph(static_cast<int>(m_pos.x - (m_titleWidth * 0.5f) - 400), static_cast<int>(m_pos.y - 150),
	//	static_cast<int>(m_pos.x - (m_titleWidth * 0.5f) + 400), static_cast<int>(m_pos.y + 250),
	//	handle.h_data.hi_logoBg, true);


	DrawExtendGraph(static_cast<int>(m_pos.x - (m_titleWidth * 0.5f) - 400), static_cast<int>(m_pos.y - 150),
		static_cast<int>(m_pos.x - (m_titleWidth * 0.5f) + 400), static_cast<int>(m_pos.y + 250),
		handle.h_data.hi_logoBg, true);

	// ChangeFontFromHandle(m_backTitleFont);
	DrawStringToHandle(static_cast<int>(m_pos.x - (m_titleWidth * 0.5f) - 240), static_cast<int>(m_pos.y + 15), "Glow  Ruler", 0x101010, handle.h_data.hf_backTitle,0x303030);
	// ChangeFontFromHandle(m_titleFont);
	DrawStringToHandle(static_cast<int>(m_pos.x - (m_titleWidth * 0.5f) - 250), static_cast<int>(m_pos.y), "Glow  Ruler", 0xffffff, handle.h_data.hf_title);
	// ChangeFontFromHandle(m_otherFont);
	
	// �^�C�g�����j���[
	if (m_isAlpha) // if (a >= 255) ���ƁA�t�F�[�h�A�E�g���Ȃ�
	{
		
		// ����
		DrawStringToHandle(static_cast<int>(Game::kScreenWidth - 550), static_cast<int>(m_pos.y) + 570, "����F", 0xffffff, handle.h_data.hf_util_24);
		DrawStringToHandle(static_cast<int>(Game::kScreenWidth - 450), static_cast<int>(m_pos.y) + 550, "�@���@\n������", 0xffffff, handle.h_data.hf_util_24);
		DrawStringToHandle(static_cast<int>(Game::kScreenWidth - 340), static_cast<int>(m_pos.y) + 570, "����FSPACE  or  A button", 0xffffff, handle.h_data.hf_util_24);
		// �J�[�\��
		/*DrawTriangle(static_cast<int>(m_cursorPos.x + 6 - 150), static_cast<int>(m_cursorPos.y),
					static_cast<int>(m_cursorPos.x - 2 - 150),static_cast<int>(m_cursorPos.y + 4),
					static_cast<int>(m_cursorPos.x - 2 - 150), static_cast<int>(m_cursorPos.y - 4),
					0xF8E559, true);*/

		// �^�C���A�^�b�N
		if (m_menuNum == 0 && m_appStartTimer < 60) // �I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 300, "�����L���O �`�������W", 0xe04000, 0xddc000);
		else if (m_menuNum == 0)					// �I�����{���莞
		{
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 300, "�����L���O �`�������W", 0xe04000, 0xb0b0b0);
		}
		else										// ���I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 220), static_cast<int>(m_pos.y) + 300, "�����L���O �`�������W", 0xe04000, 0xb0b0b0);
		

		// �X�e�[�W�I��
		if (m_menuNum == 1 && m_appStartTimer < 60) // �I����
		{
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 350, "�Z���N�g�X�e�[�W", 0xe04000, 0xddc000);
			DrawFormatString2F(m_pos.x - 40 - m_cursorMove, m_pos.y + 350, 0xe04000, 0xddc000, "��");
			DrawFormatString2F(m_pos.x, m_pos.y + 350, 0xe04000, 0xddc000, "[");
			if(m_startNum < 10)
				DrawFormatString2F(m_pos.x + 40, m_pos.y + 350, 0xe04000, 0xddc000, "%d", m_startNum);
			else
				DrawFormatString2F(m_pos.x + 35, m_pos.y + 350, 0xe04000, 0xddc000, "%d", m_startNum);
			DrawFormatString2F(m_pos.x + 85, m_pos.y + 350, 0xe04000, 0xddc000, "]�@ ( 1 �` %d )", Game::kStageNum - 1);
			DrawFormatString2F(m_pos.x + 85 + 10 + m_cursorMove, m_pos.y + 350, 0xe04000, 0xddc000, "��");
		}
		else if (m_menuNum == 1)					// �I�����{���莞
		{
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 350, "�Z���N�g�X�e�[�W", 0xe04000, 0xb0b0b0);
			DrawFormatString2F(m_pos.x - 40 - m_cursorMove, m_pos.y + 350, 0xe04000, 0xb0b0b0, "��");
			DrawFormatString2F(m_pos.x, m_pos.y + 350, 0xe04000, 0xb0b0b0, "[");
			if (m_startNum < 10)
				DrawFormatString2F(m_pos.x + 40, m_pos.y + 350, 0xe04000, 0xb0b0b0, "%d", m_startNum);
			else
				DrawFormatString2F(m_pos.x + 35, m_pos.y + 350, 0xe04000, 0xb0b0b0, "%d", m_startNum);
			DrawFormatString2F(m_pos.x + 85, m_pos.y + 350, 0xe04000, 0xb0b0b0, "]�@ ( 1 �` %d )", Game::kStageNum - 1);
			DrawFormatString2F(m_pos.x + 85 + 10 + m_cursorMove, m_pos.y + 350, 0xe04000, 0xb0b0b0, "��");
		}
		else										// ���I����
		{
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 220), static_cast<int>(m_pos.y) + 350, "�Z���N�g�X�e�[�W", 0xe04000, 0xb0b0b0);
			DrawFormatString2F(m_pos.x , m_pos.y + 350, 0xe04000, 0xb0b0b0, "[");
			if (m_startNum < 10)
				DrawFormatString2F(m_pos.x + 40, m_pos.y + 350, 0xe04000, 0xb0b0b0, "%d", m_startNum);
			else
				DrawFormatString2F(m_pos.x + 35, m_pos.y + 350, 0xe04000, 0xb0b0b0, "%d", m_startNum);
			DrawFormatString2F(m_pos.x + 85, m_pos.y + 350, 0xe04000, 0xb0b0b0, "]�@ ( 1 �` %d )", Game::kStageNum - 1);
		}

		/*
		// ���[�J�[
		if (m_menuNum == 2 && m_appStartTimer < 60) // �I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 170), static_cast<int>(m_pos.y) + 430, "�X�e�[�W���[�J�[", 0xe04000, 0xddc000);
		else if (m_menuNum == 2)					// �I�����{���莞
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 170), static_cast<int>(m_pos.y) + 350, "�X�e�[�W���[�J�[", 0xe04000, 0xb0b0b0);
		else										// ���I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 150), static_cast<int>(m_pos.y) + 430, "�X�e�[�W���[�J�[", 0xe04000, 0xb0b0b0);
		*/

		// �ݒ�
		if (m_menuNum == 2 && m_appStartTimer < 60) // �I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 400, "�ݒ�", 0xe04000, 0xddc000);
		else if (m_menuNum == 2)					// �I�����{���莞
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 400, "�ݒ�", 0xe04000, 0xb0b0b0);
		else										// ���I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 220), static_cast<int>(m_pos.y) + 400, "�ݒ�", 0xe04000, 0xb0b0b0);


		// �Q�[���I��
		if (m_menuNum == 3 && m_appStartTimer < 60) // �I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 450, "�I��", 0xe04000, 0xddc000);
		else if (m_menuNum == 3)					// �I�����{���莞
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 450, "�I��", 0xe04000, 0xb0b0b0);
		else										// ���I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 220), static_cast<int>(m_pos.y) + 450, "�I��", 0xe04000, 0xb0b0b0);


		// �����\�L
		if (m_menuNum == 4 && m_appStartTimer < 60) // �I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 500, "�N���W�b�g", 0xe04000, 0xddc000);
		else if (m_menuNum == 4)					// �I�����{���莞
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 250), static_cast<int>(m_pos.y) + 500, "�N���W�b�g", 0xe04000, 0xb0b0b0);
		else										// ���I����
			DrawString(static_cast<int>(m_pos.x - (m_selectWidth * 0.5f) - 220), static_cast<int>(m_pos.y) + 500, "�N���W�b�g", 0xe04000, 0xb0b0b0);
		
		m_pWindow->WindowDraw(handle);
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - m_alpha);
		DrawBox(0, 0, Game::kScreenWidth + 1, Game::kScreenHeight + 1, 0x000000, true);
	}
}

int TitleScene::GetLight() const
{
	return m_pWindow->GetLight();
}

int TitleScene::GetBGM() const
{
	return m_pWindow->GetBGM();
}

int TitleScene::GetSE() const
{
	return m_pWindow->GetSE();
}

void TitleScene::SetUti(int BGM, int SE, int light)
{
	m_pWindow->SetSetting(BGM, SE, light);
}
