#include "StageMakerScene.h"
#include "Map.h"
#include "Vec2.h"

// �}�b�v�`�b�v
#include "Wall.h"
#include "DirWall.h"
#include "InColorFloor.h"
#include "OutColorFloor.h"
#include "Player.h"
#include "PlayerLight.h"
#include "GoalPoint.h"

StageMakerScene::StageMakerScene() :
	m_isMake(false),
	m_isSelect(false),
	m_isClear(false),
	m_mode(1),
	m_X(1),
	m_Y(1),
	m_stringWidth(0),
	m_isLastHitKey(false),
	m_isPlayer(false),
	m_isGoal(false),
	m_goalColor(0xff0000),
	m_R(255),
	m_G(0),
	m_B(0),
	m_animaTimer(0),
	m_triMove(-8.0f),
	m_isBack(false)
{
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			if (y == 0 || y == kChipNumY - 1 || x == 0 || x == kChipNumX - 1)
				m_stage.stageData[y][x] = 1;
			else
				m_stage.stageData[y][x] = 0;
		}
	} 
	m_pMap = new Map;
	m_cursorPos = { static_cast<float>(m_X) * Game::kGraphWidth + kMapStartPosX + Game::kGraphHalfWidth,
				static_cast<float>(m_Y) * Game::kGraphHeight + kMapStartPosY + Game::kGraphHalfHeight };

	m_pWall = new Wall;
	m_pPlayer = new Player;
	m_pLight = new PlayerLight;
	m_pInColor = new InColorFloor;
	m_pOutColor = new OutColorFloor;
	m_pDirWall = new DirWall;
	m_pGoal = new GoalPoint;
}

StageMakerScene::~StageMakerScene()
{
	delete m_pMap;
	m_pMap = nullptr;

	delete m_pPlayer;
	m_pPlayer = nullptr;
	delete m_pLight;
	m_pLight = nullptr;
	delete m_pWall;
	m_pWall = nullptr;
	delete m_pInColor;
	m_pInColor = nullptr;
	delete m_pOutColor;
	m_pOutColor = nullptr;
	delete m_pDirWall;
	m_pDirWall = nullptr;
	delete m_pGoal;
	m_pGoal = nullptr;
}

void StageMakerScene::Init(int gameMode)
{

}

void StageMakerScene::Update()
{
	// ����
	int hitSpace = CheckHitKey(KEY_INPUT_SPACE);
	int hitU = CheckHitKey(KEY_INPUT_UP);
	int hitD = CheckHitKey(KEY_INPUT_DOWN);
	int hitL = CheckHitKey(KEY_INPUT_LEFT);
	int hitR = CheckHitKey(KEY_INPUT_RIGHT);
	int hitEsc = CheckHitKey(KEY_INPUT_ESCAPE);


	// �L�[���͏�

	// Space�Ői�߂�
	if (hitSpace && !m_isLastHitKey)
	{
		if (m_isMake)
		{
			if (m_isSelect) m_isSelect = false;
			else m_isSelect = true;
		}
		else
		{
			if(m_mode == 1)m_isMake = true;
		}
	}
	// Esc�Ŗ߂�
	if (hitEsc && !m_isLastHitKey)
	{
		if (m_isSelect)
		{
			m_isSelect = false;
		}
		else if (m_isMake)
		{
			m_isMake = false;
		}
		else
		{
			m_isBack = true;
		}
	}

	// �J�[�\������

	// �X�e�[�W�쐬
	if (!m_isLastHitKey)
	{
		if (m_isMake)
		{
			// �E�B���h�E���o�Ă���Ƃ��̓^�C�g�����삵�Ȃ�
			if (!m_isSelect)
			{
				// �㉺�L�[
				if (hitU)
				{
					if (m_Y > 1) m_Y--;
					else m_Y = kChipNumY - 2;
				}
				if (hitD)
				{
					if (m_Y < kChipNumY - 2) m_Y++;
					else m_Y = 1;
				}
				// ���E�L�[�@(�I���X�^�[�g�ɃJ�[�\�����킹�����̂�)
				if (hitR)
				{
					if (m_X < kChipNumX - 2) m_X++;
					else m_X = 1;
				}
				if (hitL)
				{
					if (m_X > 1) m_X--;
					else m_X = kChipNumX - 2;
				}
			}
			// �J�[�\���ʒu�X�V
			m_cursorPos = { static_cast<float>(m_X) * Game::kGraphWidth + kMapStartPosX,
					static_cast<float>(m_Y) * Game::kGraphHeight + kMapStartPosY + Game::kGraphHalfHeight };
		}
		// ���or������or�ۑ��@�I��
		else
		{
			// ���E�L�[�@(���[�h�I��)
			if (hitR)
			{
				if (m_mode < 3) m_mode++;
				else m_mode = 1;
			}
			if (hitL)
			{
				if (m_mode > 1) m_mode--;
				else m_mode = 3;
			}

			// �J�[�\���ʒu�X�V
			m_cursorPos = { static_cast<float>(Game::kScreenWidth * (0.25f * m_mode)) - 50,
					static_cast<float>(Game::kScreenHeight - 75) };
		}
	}
	
	// �`�b�v�I��
	if (m_isSelect && !m_isLastHitKey)
	{
		// ���E�L�[�@(�I���X�^�[�g�ɃJ�[�\�����킹�����̂�)
		if (hitR)
		{
			if (m_stage.stageData[m_Y][m_X] == 1)
			{
				if (!m_isPlayer)
				{
					m_isPlayer = true;
					m_stage.stageData[m_Y][m_X] = 2;
				}
				else m_stage.stageData[m_Y][m_X] = 30;
			}
			else if (m_stage.stageData[m_Y][m_X] == 2)
			{
				m_isPlayer = false;
				m_stage.stageData[m_Y][m_X] = 30;
			}
			else if (m_stage.stageData[m_Y][m_X] == 33) m_stage.stageData[m_Y][m_X] = 40;
			else if (m_stage.stageData[m_Y][m_X] == 43) m_stage.stageData[m_Y][m_X] = 50;
			else if (m_stage.stageData[m_Y][m_X] == 53)
			{
				if (!m_isGoal)
				{
					m_isGoal = true;
					m_stage.stageData[m_Y][m_X] = 6;
				}
				else m_stage.stageData[m_Y][m_X] = 0;
			}
			else if (m_stage.stageData[m_Y][m_X] == 6)
			{
				m_isGoal = false;
				m_stage.stageData[m_Y][m_X] = 0;
			}
			else  m_stage.stageData[m_Y][m_X]++;
		}
		if (hitL)
		{
			if (m_stage.stageData[m_Y][m_X] == 30)
			{
				if (!m_isPlayer)
				{
					m_isPlayer = true;
					m_stage.stageData[m_Y][m_X] = 2;
				}
				else m_stage.stageData[m_Y][m_X] = 1;
			}
			else if (m_stage.stageData[m_Y][m_X] == 2)
			{
				m_isPlayer = false;
				m_stage.stageData[m_Y][m_X] = 1;
			}
			else if (m_stage.stageData[m_Y][m_X] == 40) m_stage.stageData[m_Y][m_X] = 33;
			else if (m_stage.stageData[m_Y][m_X] == 50) m_stage.stageData[m_Y][m_X] = 43;
			else if (m_stage.stageData[m_Y][m_X] == 6)
			{
				m_isGoal = false;
				m_stage.stageData[m_Y][m_X] = 53;
			}
			else if (m_stage.stageData[m_Y][m_X] == 0)
			{
				if (!m_isGoal)
				{
					m_isGoal = true;
					m_stage.stageData[m_Y][m_X] = 6;
				}
				else m_stage.stageData[m_Y][m_X] = 53;
			}
			else m_stage.stageData[m_Y][m_X]--;
		}
	}


	// ���O�t���[���̃L�[���͏�
	if (hitSpace || hitU || hitD || hitL || hitR || hitEsc)
	{
		m_isLastHitKey = true;
	}
	else m_isLastHitKey = false;


	// �S�[���J���[
	if (m_B == 0)
	{
		if (!(m_R == 0))
		{
			m_R -= 15;
			m_G += 15;
		}
	}
	if (m_R == 0)
	{
		if (!(m_G == 0))
		{
			m_G -= 15;
			m_B += 15;
		}
	}
	if (m_G == 0)
	{
		if (!(m_B == 0))
		{
			m_B -= 15;
			m_R += 15;
		}
	}
	m_goalColor = (16 * 16 * 16 * 16 * m_R) + (16 * 16 * m_G) + (m_B);

	// ���̃A�j������
	if (m_animaTimer < 30)
	{
		if(m_triMove < 2.0f)
		m_triMove += 0.34f;
	}
	else if (m_animaTimer < 60)
	{
		if(m_triMove > -8.0f)
		m_triMove -= 0.34f;
	}
	else m_animaTimer = 0;
	m_animaTimer++;
}

void StageMakerScene::ChipInit(int chipNum)
{
	if (chipNum == 1)
	{
		m_pWall->Init(m_X,m_Y);
	}

	if (chipNum == 2)
	{

	}
	if (chipNum >= 30 && chipNum < 40)
	{

	}
	if (chipNum >= 40 && chipNum < 50)
	{

	}
	if (chipNum >= 50 && chipNum < 60)
	{

	}
	if (chipNum == 6)
	{

	}
}

void StageMakerScene::Draw(const Handle& handle)
{
	////////////
	// �}�b�v //
	////////////
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			if (m_stage.stageData[y][x] == 1)
			{
				m_pWall->Init(x, y);
				m_pWall->Draw(handle);
			}

			else if (m_stage.stageData[y][x] == 2)
			{
				m_pPlayer->Init(static_cast<float>(x), static_cast<float>(y));
				m_pLight->Init(m_pPlayer->GetPos());
				m_pLight->Draw();
				m_pPlayer->Draw();
				
			}
			else if (m_stage.stageData[y][x] >= 30 && m_stage.stageData[y][x] < 40)
			{
				// �F�w��
				auto setColor = 0xffffff;
				switch (m_stage.stageData[y][x] - 30)
				{
				case 0:
					setColor = 0xff0000;
					break;
				case 1:
					setColor = 0x00ff00;
					break;
				case 2:
					setColor = 0x0000ff;
					break;
				case 3:
					setColor = 0xffff00;
					break;
				default:
					setColor = 0xffffff;
					break;
				}
				m_pInColor->Init(x, y, setColor);
				m_pInColor->Draw(handle);
			}
			else if (m_stage.stageData[y][x] >= 40 && m_stage.stageData[y][x] < 50)
			{
				// �F�w��
				auto setColor = 0xffffff;
				switch (m_stage.stageData[y][x] - 40)
				{
				case 0:
					setColor = 0xff0000;
					break;
				case 1:
					setColor = 0x00ff00;
					break;
				case 2:
					setColor = 0x0000ff;
					break;
				case 3:
					setColor = 0xffff00;
					break;
				default:
					setColor = 0xffffff;
					break;
				}
				m_pOutColor->Init(x, y, setColor);
				m_pOutColor->Draw(handle);
			}
			else if (m_stage.stageData[y][x] >= 50 && m_stage.stageData[y][x] < 60)
			{
				m_pDirWall->Init(x, y, m_stage.stageData[y][x] - 50);
				m_pDirWall->Draw(handle);
			}
			else if (m_stage.stageData[y][x] == 6)
			{
				m_pGoal->Init(x, y);
				DrawBox(static_cast<int>(x * Game::kGraphWidth + kMapStartPosX - Game::kGraphHalfWidth),
					static_cast<int>(y * Game::kGraphHeight + kMapStartPosY),
					static_cast<int>(x * Game::kGraphWidth + kMapStartPosX + Game::kGraphHalfWidth - 1),
					static_cast<int>(y * Game::kGraphHeight + kMapStartPosY + Game::kGraphHeight - 1),
					m_goalColor, true);
				m_pGoal->Draw();
			}
		}
	}

	//////////////
	// �J�[�\�� //
	//////////////
	if (m_isMake)
	{

		if (!m_isSelect)
		{
			// �g
			DrawBox(static_cast<int>(m_cursorPos.x - Game::kGraphHalfWidth),static_cast<int>(m_cursorPos.y - Game::kGraphHalfHeight),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfWidth - 1),static_cast<int>(m_cursorPos.y + Game::kGraphHalfHeight - 1),
				0xff0000, false);
			// ��
			DxLib::DrawTriangle(static_cast<int>(m_cursorPos.x - Game::kGraphWidth * 1.05f + m_triMove), static_cast<int>(m_cursorPos.y),
				static_cast<int>(m_cursorPos.x - Game::kGraphHalfWidth * 1.05f + m_triMove), static_cast<int>(m_cursorPos.y - Game::kGraphHalfWidth * 0.75f),
				static_cast<int>(m_cursorPos.x - Game::kGraphHalfWidth * 1.05f + m_triMove), static_cast<int>(m_cursorPos.y + Game::kGraphHalfWidth * 0.75f),
				0xffaa00, true);
			// �E
			DxLib::DrawTriangle(static_cast<int>(m_cursorPos.x + Game::kGraphWidth * 1.05f - m_triMove), static_cast<int>(m_cursorPos.y),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfWidth * 1.05f - m_triMove), static_cast<int>(m_cursorPos.y - Game::kGraphHalfWidth * 0.75f),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfWidth * 1.05f - m_triMove), static_cast<int>(m_cursorPos.y + Game::kGraphHalfWidth * 0.75f),
				0xffaa00, true);
			// ��
			DxLib::DrawTriangle(static_cast<int>(m_cursorPos.x), static_cast<int>(m_cursorPos.y - Game::kGraphHeight * 1.05f + m_triMove),
				static_cast<int>(m_cursorPos.x - Game::kGraphHalfHeight * 0.75f), static_cast<int>(m_cursorPos.y - Game::kGraphHalfWidth * 1.05f + m_triMove),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfHeight * 0.75f), static_cast<int>(m_cursorPos.y - Game::kGraphHalfWidth * 1.05f + m_triMove),
				0xffaa00, true);
			// ��
			DxLib::DrawTriangle(static_cast<int>(m_cursorPos.x), static_cast<int>(m_cursorPos.y + Game::kGraphHeight * 1.05f - m_triMove),
				static_cast<int>(m_cursorPos.x - Game::kGraphHalfHeight * 0.75f), static_cast<int>(m_cursorPos.y + Game::kGraphHalfWidth * 1.05f - m_triMove),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfHeight * 0.75f), static_cast<int>(m_cursorPos.y + Game::kGraphHalfWidth * 1.05f - m_triMove),
				0xffaa00, true);
		}
		else
		{
			// �g
			DrawBox(static_cast<int>(m_cursorPos.x - Game::kGraphHalfWidth),
				static_cast<int>(m_cursorPos.y - Game::kGraphHalfHeight),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfWidth - 1),
				static_cast<int>(m_cursorPos.y + Game::kGraphHalfHeight - 1),
				0xffff00, false);
			// ��
			DxLib::DrawTriangle(static_cast<int>(m_cursorPos.x - Game::kGraphWidth * 1.05f + m_triMove), static_cast<int>(m_cursorPos.y),
				static_cast<int>(m_cursorPos.x - Game::kGraphHalfWidth * 1.05f + m_triMove), static_cast<int>(m_cursorPos.y - Game::kGraphHalfWidth * 0.75f),
				static_cast<int>(m_cursorPos.x - Game::kGraphHalfWidth * 1.05f + m_triMove), static_cast<int>(m_cursorPos.y + Game::kGraphHalfWidth * 0.75f),
				0xffaa00, true);
			// �E
			DxLib::DrawTriangle(static_cast<int>(m_cursorPos.x + Game::kGraphWidth * 1.05f - m_triMove), static_cast<int>(m_cursorPos.y),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfWidth * 1.05f - m_triMove), static_cast<int>(m_cursorPos.y - Game::kGraphHalfWidth * 0.75f),
				static_cast<int>(m_cursorPos.x + Game::kGraphHalfWidth * 1.05f - m_triMove), static_cast<int>(m_cursorPos.y + Game::kGraphHalfWidth * 0.75f),
				0xffaa00, true);
		}
	}
	else
	{
		// �g
		DrawBox(static_cast<int>(m_cursorPos.x - Game::kGraphHalfWidth),
			static_cast<int>(m_cursorPos.y - Game::kGraphHalfHeight),
			static_cast<int>(m_cursorPos.x + Game::kGraphHalfWidth - 1 + 75),
			static_cast<int>(m_cursorPos.y + Game::kGraphHalfHeight - 1 + 40),
			0xffff00, true);
	}


	// ������
	if (m_isMake)
	{
		switch (m_mode)
		{
		case 1:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.25f) - 50, static_cast<int>(Game::kScreenHeight - 75), "���", 0x864AF9);
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�V��", 0x864AF9);
			DrawString(static_cast<int>(Game::kScreenWidth * 0.75f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�ۑ�", 0x864AF9);
			break;
		case 2:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.25f) - 50, static_cast<int>(Game::kScreenHeight - 75), "���", 0x864AF9);
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�V��", 0x864AF9);
			DrawString(static_cast<int>(Game::kScreenWidth * 0.75f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�ۑ�", 0x864AF9);
			break;
		case 3:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.25f) - 50, static_cast<int>(Game::kScreenHeight - 75), "���", 0x864AF9);
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�V��", 0x864AF9);
			DrawString(static_cast<int>(Game::kScreenWidth * 0.75f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�ۑ�", 0x864AF9);
			break;
		default:
			break;
		}
	}
	else
	{
		DrawString(static_cast<int>(Game::kScreenWidth * 0.25f) - 50, static_cast<int>(Game::kScreenHeight - 75), "���", 0x864AF9);
		DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�V��(������)", 0x864AF9);
		DrawString(static_cast<int>(Game::kScreenWidth * 0.75f) - 50, static_cast<int>(Game::kScreenHeight - 75), "�ۑ�(������)", 0x864AF9);
	}

	if (m_isSelect)
	{
		switch (m_stage.stageData[m_Y][m_X])
		{
		case 0:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�Ȃ�", 0xffffff);
			break;
		case 1:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "����", 0xffffff);
			break;
		case 2:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�v���C���[", 0xffffff);
			break;
		case 30:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�ς����i�ԁj", 0xffffff);
			break;
		case 31:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�ς����i�΁j", 0xffffff);
			break;
		case 32:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�ς����i�j", 0xffffff);
			break;
		case 33:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�ς����i���j", 0xffffff);
			break;
		case 40:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�h�菰�i�ԁj", 0xffffff);
			break;
		case 41:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�h�菰�i�΁j", 0xffffff);
			break;
		case 42:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�h�菰�i�j", 0xffffff);
			break;
		case 43:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�F�h�菰�i���j", 0xffffff);
			break;
		case 50:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�P�����ǁi��j", 0xffffff);
			break;
		case 51:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�P�����ǁi���j", 0xffffff);
			break;
		case 52:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�P�����ǁi���j", 0xffffff);
			break;
		case 53:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�P�����ǁi�E�j", 0xffffff);
			break;
		case 6:
			DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 100, 40, "�S�[��", 0xffffff);
			break;
		default:
		break;
		}
	}
	else if(m_isMake)
		DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 200, 40, "�ҏW����}�X��I��ł�", 0xffffff);
	else
	{
		DrawString(static_cast<int>(Game::kScreenWidth * 0.5f) - 200, 40, "�������悤��", 0xffffff);
	}

	DrawFormatString(static_cast<int>(Game::kScreenWidth) - 300, static_cast<int>(50), 0xffffff, "���ǂ�[ESC]");
}
