#include "Map.h"

#include "Handle.h"

// �v���C���[
#include "Player.h"
#include "PlayerLight.h"

// �M�~�b�N
#include "Wall.h"
#include "InColorFloor.h"
#include "OutColorFloor.h"
#include "DirWall.h"
#include "GoalPoint.h"

// �G�t�F�N�g
#include "EfectColor.h"

// �T�E���h
#include "Sound.h"

// BG
#include "GameBg.h"

// �t�@�C���f�[�^
#include "FileQuickTime.h"

// �v���C���[�J���[��Bg
#include "pColorBg.h"

#include <cassert>

Map::Map() :
	m_wallCount(0),
	m_inColorCount(0),
	m_outColorCount(0),
	m_dirWallCount(0),
	m_paintCount(0),
	m_isClear(false),
	m_alpha(255),
	m_isTransScene(false),
	m_timeAttack(false),
	m_timer(0),
	m_clearBgColor(0x1f152d),
	m_mapNum(0),
	m_isUpdateTime(false),
	m_mode(0),
	m_stringTimer(0),
	m_clearWindowTimer(0),
	m_clearWindowY(0),
	m_BGM(0),
	m_SE(0),
	m_isReset(false)
{
	for (int i = 0; i < kChipNumY; i++)
	{
		for (int j = 0; j < kChipNumX; j++)
		{
			chipData[i][j] = 0;
		}
	}
	m_pPlayer = new Player;
	m_pLight = new PlayerLight;
	m_pGoal = new GoalPoint;
	
	// �T�E���h
	m_pSound.resize(9);
	for (int i = 0; i < m_pSound.size(); i++)
	{
		m_pSound[i] = new Sound;
	}

	

	m_clearPos = { Game::kScreenWidth,Game::kScreenHeight * 0.5f };

	// �t�@�C���f�[�^
	m_pData = new FileQuickTime;

	m_pColorBg = new pColorBg;
}

Map::~Map()
{
	if(!m_isReset)
		m_pSound[0]->Stop();

	delete m_pPlayer;
	m_pPlayer = nullptr;
	delete m_pLight;
	m_pLight = nullptr;
	for (int i = 0; i < m_wallCount; i++)
	{
		delete m_pWall[i];
		m_pWall[i] = nullptr;
	}
	for (int i = 0; i < m_inColorCount; i++)
	{
		delete m_pInColor[i];
		m_pInColor[i] = nullptr;
	}
	for (int i = 0; i < m_outColorCount; i++)
	{
		delete m_pOutColor[i];
		m_pOutColor[i] = nullptr;
		delete m_pEfect[i];
		m_pEfect[i] = nullptr;
	}
	for (int i = 0; i < m_dirWallCount; i++)
	{
		delete m_pDirWall[i];
		m_pDirWall[i] = nullptr;
	}
	delete m_pGoal;
	m_pGoal = nullptr;

	
	for (int i = 0; i < m_pSound.size(); i++)
	{
		delete m_pSound[i];
		m_pSound[i] = nullptr;
	}

	for (int i = 0; i < m_pBg.size(); i++)
	{
		delete m_pBg[i];
		m_pBg[i] = nullptr;
	}
	delete m_pData;
	m_pData = nullptr;

	delete m_pColorBg;
	m_pColorBg = nullptr;
}

void Map::Init(int mode, int mapNum, int BGM, int SE, const Handle& handle)
{
	m_mode = mode;
	m_mapNum = mapNum;
	m_BGM = BGM;
	m_SE = SE;
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			// �}�b�v���ǂݎ��
				chipData[y][x] = MapData::SetMap(mapNum, y, x);


			// �g�p���̊e�M�~�b�N�m��

			/////////////
			// �P = �� //
			/////////////
			if (chipData[y][x] == 1)
			{
				// �v�f���̍X�V(���݌��Ɂ{�P)
				m_pWall.resize(m_wallCount + 1);
				// �X�V�Œǉ����ꂽ�v�f�ԍ���������
				m_pWall[m_wallCount] = new Wall;
				m_pWall[m_wallCount]->Init(x, y);
				// �Ō�Ɍ��݌��̍X�V
				m_wallCount++;
			}

			/////////////////////
			// �Q = �v���C���[ //
			/////////////////////
			if (chipData[y][x] == 2)
			{
				m_pPlayer->Init(static_cast<float>(x), static_cast<float>(y));
			}

			///////////////////
			// �R = �F�ύX�� //
			///////////////////
			if(chipData[y][x] >= 30 && chipData[y][x] < 40)
			{
				// �v�f���̍X�V(���݌��Ɂ{�P)
				m_pInColor.resize(m_inColorCount + 1);
				// �X�V�Œǉ����ꂽ�v�f�ԍ���������
				m_pInColor[m_inColorCount] = new InColorFloor;
				// �F�w��
				auto setColor = 0xffffff;
				switch (chipData[y][x] - 30)
				{
				case 0: // ��
					setColor = 0xff69b4;
					break;
				case 1: // ��
					setColor = 0x39ff14;
					break;
				case 2: // ��
					setColor = 0x00aeef;
					break;
				case 3: // ��
					setColor = 0xffd300;
					break;
				default: // ��
					setColor = 0xffffff;
					break;
				}
				m_pInColor[m_inColorCount]->Init(x, y, setColor);
				// �Ō�Ɍ��݌��̍X�V
				m_inColorCount++;
			}

			/////////////////
			// �S = ���F�� //
			/////////////////
			if (chipData[y][x] >= 40 && chipData[y][x] < 50)
			{
				// �v�f���̍X�V(���݌��Ɂ{�P)
				m_pOutColor.resize(m_outColorCount + 1);
				m_pEfect.resize(m_outColorCount + 1);
				// �X�V�Œǉ����ꂽ�v�f�ԍ���������
				m_pOutColor[m_outColorCount] = new OutColorFloor;
				m_pEfect[m_outColorCount] = new EfectColor;
				// �F�w��
				auto setColor = 0xffffff;
				switch (chipData[y][x] - 40)
				{
				case 0:
					setColor = 0xff69b4;
					break;
				case 1:
					setColor = 0x39ff14;
					break;
				case 2:
					setColor = 0x00aeef;
					break;
				case 3:
					setColor = 0xffd300;
					break;
				default:
					setColor = 0xffffff;
					break;
				}
				m_pOutColor[m_outColorCount]->Init(x, y, setColor);

				// Bg�̐��w��
				m_pBg.resize(m_outColorCount + 1);
				m_pBg[m_outColorCount] = new GameBg;
				m_pBg[m_outColorCount]->Init(m_outColorCount,setColor);

				// �Ō�Ɍ��݌��̍X�V
				m_outColorCount++;
			}

			/////////////////
			// �T = ����� //
			/////////////////

				/*�C�ӂ̕��������̕��@*/
			// �@�\���̂��g�������������i�\�̓A�s�Ȃ炱�����j
			// �A�`�b�v�f�[�^�Ƃ��ĂS����Ă��܂��i�����葁�����Ȃ炱�����j
			if (chipData[y][x] >= 50 && chipData[y][x] < 60)
			{
				// �v�f���̍X�V(���݌��Ɂ{�P)
				m_pDirWall.resize(m_dirWallCount + 1);
				// �X�V�Œǉ����ꂽ�v�f�ԍ���������
				m_pDirWall[m_dirWallCount] = new DirWall;
				// �����w��
				int setDir = 0;
				switch (chipData[y][x] - 50)
				{
				case 0:
					setDir = 0;
					break;
				case 1:
					setDir = 1;
					break;
				case 2:
					setDir = 2;
					break;
				default:
					setDir = 3;
					break;
				}
				m_pDirWall[m_dirWallCount]->Init(x, y, setDir);
				// �Ō�Ɍ��݌��̍X�V
				m_dirWallCount++;
			}

			/////////////////
			// �U = �S�[�� //
			/////////////////
			if (chipData[y][x] == 6)
			{
				m_pGoal->Init(x,y);
			}
		}
	}
	// �v���C���[�̃I�[����
	m_pLight->Init(m_pPlayer->GetPos());


	// �Q�[��BGM
	m_pSound[0]->InitBGM(handle.h_data.hm_B_1);
	// �ǃq�b�g��
	m_pSound[1]->InitSE(handle.h_data.hm_S_04);
	// �F�ύX��
	m_pSound[2]->InitSE(handle.h_data.hm_S_05);
	// ���F��
	m_pSound[3]->InitSE(handle.h_data.hm_S_06);
	// �S�h�艹
	m_pSound[4]->InitSE(handle.h_data.hm_S_07);
	// �|�[�Y��
	m_pSound[5]->InitSE(handle.h_data.hm_S_01);
	// �S�[����
	m_pSound[6]->InitSE(handle.h_data.hm_S_08);
	// �L�^�X�V��
	m_pSound[7]->InitSE(handle.h_data.hm_S_09);
	// ���Z�b�g��
	m_pSound[8]->InitSE(handle.h_data.hm_S_10);

	// ���ʍX�V
	for (int i = 0; i < m_pSound.size(); i++)
	{
		if (i == 0) m_pSound[i]->UpdateBGM(BGM);
		else m_pSound[i]->UpdateSE(SE);
	}

	if(!m_pSound[0]->ChackPlaying())
		m_pSound[0]->LoopPlay();
}

void Map::Update(bool isPause)
{
	if (!isPause)
	{
		/////////////////////////////
		// ����ǂ̏Փ˔��� �ՓˑO //
		/////////////////////////////
		for (int i = 0; i < m_dirWallCount; i++)
		{
			Rect player = m_pPlayer->GetColRect();
			m_pDirWall[i]->Update(player);				// �v���C���[���ŏՓ˔���
		}

		// �v���C���[
		m_pPlayer->Update();

		//////////////////
		// �ǂ̏Փ˔��� //
		//////////////////
		for (int i = 0; i < m_wallCount; i++)
		{
			Rect wallRect = m_pWall[i]->GetRect();				// �ǂ̓����蔻��l��
			m_pPlayer->WallHit(wallRect);						// �v���C���[���ŏՓ˔���
			if (m_pPlayer->GetHitFlag() && !m_pPlayer->GetGoal())
			{
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
			}
		}

		/////////////////////////
		// �ǂ̏Փ˔��� �Փˌ� //
		/////////////////////////
		for (int i = 0; i < m_dirWallCount; i++)
		{
			Rect dirWallRect = m_pDirWall[i]->GetRect();				// dir�ǂ̓����蔻��l��
			bool dirPass = m_pDirWall[i]->GetPass();
			m_pPlayer->DirWallHit(dirWallRect, dirPass);						// �v���C���[���ŏՓ˔���
			if (m_pPlayer->GetHitFlag() && !m_pPlayer->GetGoal())
			{
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
				m_pSound[1]->OnePlay();
			}
		}

		// �Փˏ�����Ƀv���C���[����Update���s�����ƂŃu�����Ȃ���
		m_pLight->Update(m_pPlayer->GetPos());


		////////////////////////////////
		// �F�ύX���ɂ����̕ύX���� //
		////////////////////////////////
		for (int i = 0; i < m_inColorCount; i++)
		{
			m_pInColor[i]->Update();
			Rect inColorRect = m_pInColor[i]->GetRect();		// �F�ύX���̓����蔻��l��
			int pcolor = m_pLight->GetColor();
			int setcolor = m_pInColor[i]->GetColor();			// �F�ύX���̐F���l��
			if (pcolor != setcolor && inColorRect.IsPointInRect(m_pLight->GetPos()) != 0 && !m_pPlayer->GetGoal())
			{
				m_pSound[2]->OnePlay();
				m_pLight->InColorEffect();
			}
			m_pLight->ColorFloorHit(inColorRect, setcolor);		// �v���C���[���ŐF��t�^
		}

		//////////////////////////////
		// �v���C���[���F��t�^���� //
		//////////////////////////////
		for (int i = 0; i < m_outColorCount; i++)
		{
			Rect outColorRect = m_pOutColor[i]->GetRect();		// ���F���̓����蔻��l��
			Rect lightColorRect = m_pLight->GetRect();			// �v���C���[���̓����蔻��l��
			if (outColorRect.IsCollsion(lightColorRect))		// �Փ˔���
			{
				int targetColor = m_pOutColor[i]->GetColor();	// ���F���̐F���l��
				int lightColor = m_pLight->GetColor();			// �v���C���[���̐F���l��
				// �F���r���A���F�Ȃ璅�F
				if (targetColor == lightColor)
				{
					// ���F���A�`�F�b�N�O��bool���󂯎���Ă������ƂŁA�P�񂾂��J�E���g�����
					bool isChack = m_pOutColor[i]->GetChack();
					m_pOutColor[i]->Update();

					if (!isChack)
					{
						m_pSound[3]->OnePlay();
						m_pEfect[i]->Init(m_pOutColor[i]->GetPos(), targetColor);
						// �S�[�������̃J�E���g�X�V
						m_pBg[i]->SetFlag(true);
						m_paintCount++;
						if (m_paintCount >= m_outColorCount) m_pSound[4]->OnePlay();
					}
				}
			}
			if (m_paintCount >= m_outColorCount)
			{
				m_pEfect[i]->ClearChack(i, m_pGoal->GetPos());
			}
			// �G�t�F�N�g�A�b�v�f�[�g
			m_pEfect[i]->Update();
		}
		//////////////////////
		// �S�[���n�_�̔��� //
		//////////////////////
		if (m_paintCount >= m_outColorCount)
		{
			m_isClear = true;
		}
		else m_isClear = false;
		m_pGoal->Update(m_isClear);

		// �S�[�������Ō�����F�Ɍ��点��
		Rect goalRect = m_pGoal->GetRect();
		int goalColor = m_pGoal->GetColor();
		m_pLight->ClearHit(goalRect);

		////////////
		// �S�[�� //
		////////////
		if (m_isClear && !m_isReset)
		{
			m_pPlayer->GoalIn(goalRect);
			// �w�i�𖾂邭
			if (m_clearBgColor < 0x600060) m_clearBgColor += (256 * 256 * 3 + 3);
		}
		//////////////
		// �S�[���� //
		//////////////
		if (m_pPlayer->GetGoal() && !m_isReset)
		{
			
			// �ŒZ�񐔂̃t�@�C���X�V
			if (m_alpha == 0)
			{
				m_pSound[6]->OnePlay();
				m_pSound[6]->OnePlay();
				if (m_pData->GetTime(m_mapNum) >= m_timer)
				{
					m_isUpdateTime = true;
					m_pData->ChangeTime(m_mapNum, m_timer);
					m_pSound[7]->OnePlay();
				}
				m_alpha = 3;
			}

			// �V�[���J�ڂ܂ł̃t�F�[�h�A�E�g����
			if (!m_pSound[7]->ChackPlaying() && m_clearWindowTimer > 50)
			{
				if (m_alpha < 255)
				{
					m_alpha += 3;
				}
				else
				{
					m_pSound[0]->Stop();
					m_isTransScene = true;
				}
			}

			// ������_�ł̃^�C�}�[
			if (m_stringTimer < 120)
			{
				m_stringTimer += 12;
			}
			else
			{
				m_stringTimer = 0;
			}

			// �S�[���\�L
			// �E�C���h�E���J��
			if (m_clearPos.x >= 0 && m_clearWindowY < 20)
			{
				m_clearWindowY++;
			}
			// �N���A�ʒu�𗬂�
			else if(m_clearWindowTimer == 0 || m_clearWindowTimer >= 50)
			{
				m_clearPos.x -= 30;
			}

			// �E�C���h�E�����
			if (m_clearPos.x < 0 && m_clearWindowY > 0)
			{
				m_clearWindowY--;
			}

			// �N���A�\�L�̒�~����
			if (m_clearPos.x < Game::kScreenWidth * 0.5f - 100)
			{
				if(m_clearWindowTimer < 80)
					m_clearWindowTimer++;
			}

		}
		else if(!m_isReset)
		{
			// �����t�F�[�h�C��
			if (m_alpha > 0)
			{
				m_alpha -= 5;
			}
			else
			{
				m_alpha = 0;
			}
		}

		int pad = GetJoypadInputState(DX_INPUT_PAD1);
		int hitZ = CheckHitKey(KEY_INPUT_Z);

		if ((hitZ || pad == PAD_INPUT_3) && !m_pPlayer->GetGoal() && m_mode == 1 && !m_isReset)
		{
			m_pSound[8]->OnePlay();
			m_pSound[8]->OnePlay();
			m_pSound[8]->OnePlay();
			m_isReset = true;
			
		}

		if (m_isReset)
		{
			if (m_alpha < 255)
			{
				m_alpha += 5;
			}
			else
			{
				m_alpha = 255;
				Reset();
			}
		}


		// �񐔂̍X�V
		m_timer = m_pPlayer->GetMoveTime();

		for (int i = 0; i < m_pBg.size(); i++)
		{
			// �w�i�ւ̃N���A�\�t���O�󂯓n��
			m_pBg[i]->Update();
		}
		m_pColorBg->Update(m_pLight->GetColor());

		
	}
	m_pColorBg->SetisDontMove(isPause);
}

void Map::Draw(const Handle& handle)
{
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_clearBgColor, true);

	// �G�t�F�N�g�`��
	for (int i = 0; i < m_outColorCount; i++)
	{
		m_pEfect[i]->Draw();
	}
	// �����h�~�̍����
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 70);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);

	for (int i = 0; i < m_pBg.size(); i++)
	{
		m_pBg[i]->Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	m_pColorBg->Draw();
	// �����h�~�̍����m 
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 75);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	

	// �M�~�b�N�֘A
	// ��
	for (int i = 0; i < m_wallCount; i++)
	{
		m_pWall[i]->Draw(handle);
	}
	// �F�ύX��
	for (int i = 0; i < m_inColorCount; i++)
	{
		m_pInColor[i]->Draw(handle);
	}
	// �F���`��
	for (int i = 0; i < m_outColorCount; i++)
	{
		m_pOutColor[i]->Draw(handle);
	}
	// ����ʍs��
	for (int i = 0; i < m_dirWallCount; i++)
	{
		m_pDirWall[i]->Draw(handle);
	}
	// �S�[��
	m_pGoal->Draw();

	// �S�[�����G�t�F�N�g
	if (m_pPlayer->GetGoal())
	{
		m_pGoal->GoalEffect();
	}

	// �v���C���[�֘A
	// ��
	m_pLight->Draw();
	// �v���C���[
	m_pPlayer->Draw();

	// �G�t�F�N�g�`��
	if (m_isClear)
	{
		for (int i = 0; i < m_outColorCount; i++)
		{
			m_pEfect[i]->Draw();
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180); 
	 
	// �񐔃X�R�A�E�C���h�E
	DrawExtendGraph(static_cast<int>(Game::kScreenWidth * 0.75f),-25,
		static_cast<int>(Game::kScreenWidth), 250,
		handle.h_data.hi_countWindow, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	if (m_isUpdateTime && m_stringTimer > 60)
	{
		DrawStringToHandle(static_cast<int>(Game::kScreenWidth * 0.84f), 50, "Fastest !!!!", 0xffd300,handle.h_data.hf_starry_20);
		DrawFormatStringToHandle(static_cast<int>(Game::kScreenWidth * 0.82f), 160, 0xffd300, handle.h_data.hf_util_24, " �ŒZ�� : %d ", m_pData->GetTime(m_mapNum));
	}
	else
	{
		if (m_isUpdateTime)
			DrawStringToHandle(static_cast<int>(Game::kScreenWidth * 0.84f), 50, "Fastest !!!!", 0xff4e4e, handle.h_data.hf_starry_20);

		DrawFormatStringToHandle(static_cast<int>(Game::kScreenWidth * 0.82f), 160, 0xff4e4e,handle.h_data.hf_util_24, " �ŒZ�� : %d ", m_pData->GetTime(m_mapNum));
	}

	// �F���G�t�F�N�g
	for (int i = 0; i < m_outColorCount; i++)
	{
		m_pOutColor[i]->Effect();
	}

	// �F�ύX���G�t�F�N�g
	for (int i = 0; i < m_inColorCount; i++)
	{
		m_pInColor[i]->colorEffect();
	}

	// �S�[���G�t�F�N�g
	m_pGoal->Effect();

	// �v���C���[���ݒn�G�t�F�N�g
	m_pLight->ColorEffect();

	if (m_pPlayer->GetGoal())
	{
		GoalDraw(handle);
	}
}

void Map::Reset()
{
	m_paintCount = 0;
	m_pPlayer->ResetPos();
	m_pLight->ResetColor();
	for (int i = 0; i < m_pOutColor.size(); i++)
	{
		m_pOutColor[i]->Reset();
		m_pBg[i]->Reset();
		m_pEfect[i]->Reset();
	}
	m_clearBgColor = 0x1f152d;
	m_isReset = false;
}


void Map::GoalDraw(const Handle& handle)
{
	if (m_clearWindowY > 0)
	{
		DrawBox(0, static_cast<int>(Game::kScreenHeight * 0.5f) - (m_clearWindowY + 2), Game::kScreenWidth,
			static_cast<int>(Game::kScreenHeight * 0.5f) + (m_clearWindowY + 2), 0xee0000, true);
		DrawBox(0, static_cast<int>(Game::kScreenHeight * 0.5f) - m_clearWindowY, Game::kScreenWidth,
			static_cast<int>(Game::kScreenHeight * 0.5f) + m_clearWindowY, 0xeec000, true);
	}
	DrawStringToHandle(static_cast<int>(m_clearPos.x), static_cast<int>(m_clearPos.y - 15), "STAGE  CLEAR  !!!!", 0xee0000, handle.h_data.hf_starry_32, 0xffffff);
}

void Map::SetSound(int BGM, int SE)
{
	// ���ʍX�V
	for (int i = 0; i < m_pSound.size(); i++)
	{
		if (i == 0) m_pSound[i]->UpdateBGM(BGM);
		else m_pSound[i]->UpdateSE(SE);
	}
}
