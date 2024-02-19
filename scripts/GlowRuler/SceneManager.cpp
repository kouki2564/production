#include "SceneManager.h"
#include "DxLib.h"
#include "Game.h"
#include "Handle.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "EndingScene.h"
#include "Setting.h"
#include "File.h"
#include "StageMakerScene.h"

SceneManager::SceneManager() :
	m_stageNum(1),
	m_isTransScene(false),
	m_time(0),
	m_gameMode(0),
	m_isEnd(false),
	m_isMaker(false),
	m_lightPow(5),
	m_BGMPow(2),
	m_SEPow(2),
	m_handleNum(0),
	m_handleTimer(0)
{
	m_handleData = new Handle;
	m_dataFile = new File;

	m_pTitle = new TitleScene;
	m_pMaker = nullptr;
	m_pGame = nullptr;
	m_pEnding = nullptr;
	m_pSet = new Uti;
}

SceneManager::~SceneManager()
{
	delete m_handleData;
	m_handleData = nullptr;

	if (m_pTitle != nullptr)
	{
		delete m_pTitle;
		m_pTitle = nullptr;
	}
	if (m_pGame != nullptr)
	{
		delete m_pGame;
		m_pGame = nullptr;
	}
	if (m_pEnding != nullptr)
	{
		delete m_pEnding;
		m_pEnding = nullptr;
	}
	if (m_pMaker != nullptr)
	{
		delete m_pMaker;
		m_pMaker = nullptr;
	}
	delete m_pSet;
	m_pSet = nullptr;

	delete m_dataFile;
	m_dataFile = nullptr;
}

void SceneManager::Init()
{
	m_pSet->SetUti(m_BGMPow, m_SEPow, m_lightPow);
	// �^�C�g���V�[������X�^�[�g
	m_pTitle->Init( m_lightPow, m_BGMPow, m_SEPow, *m_handleData);
	ChangeFontFromHandle(m_handleData->h_data.hf_util_48);
}

void SceneManager::SceneMove()
{
	/////////////////////////////////////////////////////////////
	// �^�C�g�����Q�[�����G���f�B���O���^�C�g������̈�A�̗��� //
	/////////////////////////////////////////////////////////////
	// �e�V�[���̑J�ڔ���
	if (m_pTitle != nullptr) m_isTransScene = m_pTitle->GetTransFlag();
	else if (m_pGame != nullptr) m_isTransScene = m_pGame->GetTransFlag();
	else if (m_pEnding != nullptr) m_isTransScene = m_pEnding->GetTransFlag();

	// �V�[���J�ڎ��N��
	if (m_isTransScene)
	{
		m_isTransScene = false;
		// �Q�[������
		if (m_pTitle != nullptr)
		{
			// �Q�[�����[�h�̑I��
			m_gameMode = m_pTitle->GetMode();
			// ���邳
			m_lightPow = m_pTitle->GetLight();
			if (m_gameMode != 2)
			{
				// �I���X�^�[�g���A�X�e�[�W�ԍ���GET
				if (m_gameMode == 1)
					m_stageNum = m_pTitle->GetStartNum();
				else m_stageNum = 1;
				
				// �^�C�g�����������
				delete m_pTitle;
				m_pTitle = nullptr;
				// �Q�[������
				m_pGame = new GameScene;
				m_pGame->Init(m_stageNum, m_gameMode, m_lightPow, m_BGMPow, m_SEPow, *m_handleData);
			}
			// ���[�J�[���[�h
			else
			{
				// �^�C�g�����������
				delete m_pTitle;
				m_pTitle = nullptr;
				// ���[�J�[����
				m_pMaker = new StageMakerScene;
				m_pMaker->Init(m_gameMode);
			}
		}

		// �G���f�B���O����
		else if (m_pGame != nullptr)
		{
			m_time = m_pGame->GetSumTime();
			if (m_gameMode == 0)
			{
				m_dataFile->ChangeTime(m_time);
			}
			Rank timeRank = { m_dataFile->GetTime(0),m_dataFile->GetTime(1),
						m_dataFile->GetTime(2),m_dataFile->GetTime(3),m_dataFile->GetTime(4),};
			// �ݒ�X�V
			m_BGMPow = m_pGame->GetBGM();
			m_SEPow = m_pGame->GetSE();
			m_lightPow = m_pGame->GetLight();
			// �Q�[�����������
			delete m_pGame;
			m_pGame = nullptr;
			// �G���f�B���O����
			m_pEnding = new EndingScene;
			m_pEnding->Init(m_time, m_gameMode, m_BGMPow, m_SEPow, timeRank, *m_handleData);
		}
		// �^�C�g������
		else if (m_pEnding != nullptr)
		{
			// �Q�[�����������
			delete m_pEnding;
			m_pEnding = nullptr;
			// �G���f�B���O����
			m_pTitle = new TitleScene;
			m_pTitle->Init(m_lightPow, m_BGMPow, m_SEPow, *m_handleData);
		}
	}
	//////////////////////////////////////////
	// �Q�[���V�[�����Ƀ^�C�g���V�[���ɖ߂� //
	//////////////////////////////////////////
	if (m_pGame != nullptr)
	{
		if (m_pGame->GetBackFlag())
		{
			// �ݒ�X�V
			m_BGMPow = m_pGame->GetBGM();
			m_SEPow = m_pGame->GetSE();
			m_lightPow = m_pGame->GetLight();

			delete m_pGame;
			m_pGame = nullptr;
			m_pTitle = new TitleScene;
			m_pTitle->Init(m_lightPow, m_BGMPow, m_SEPow, *m_handleData);
		}
	}
	if (m_pMaker != nullptr)
	{
		if (m_pMaker->GetBackFlag())
		{
			delete m_pMaker;
			m_pMaker = nullptr;
			m_pTitle = new TitleScene;
			m_pTitle->Init(m_lightPow, m_BGMPow, m_SEPow, *m_handleData);
		}
	}
	////////////////////////////////
	// ���[�J�[����^�C�g���ɖ߂� //
	////////////////////////////////

}



void SceneManager::Update()
{
	
	// �^�C�g��
	if (m_pTitle != nullptr)
	{
		// �ݒ�X�V
		m_BGMPow = m_pTitle->GetBGM();
		m_SEPow = m_pTitle->GetSE();
		m_lightPow = m_pTitle->GetLight();

		m_pTitle->Update();
		m_isEnd = m_pTitle->GetEndFlag();
	}
	// �Q�[��
	if (m_pGame != nullptr)
	{
		// �ݒ�X�V
		m_BGMPow = m_pGame->GetBGM();
		m_SEPow = m_pGame->GetSE();
		m_lightPow = m_pGame->GetLight();

		m_pGame->Update();
		m_pGame->StageUpdate(*m_handleData);
	}
	// �G���f�B���O
	if (m_pEnding != nullptr) m_pEnding->Update();

	// ���[�J�[
	if (m_pMaker != nullptr) m_pMaker->Update();

	// �e��ݒ�̔��f
	m_pSet->SetUti(m_BGMPow, m_SEPow, m_lightPow);
	m_pSet->Update();
}

void SceneManager::Draw()
{
	

	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x1f152d, true);
	// �^�C�g��
	if (m_pTitle != nullptr) m_pTitle->Draw(*m_handleData);
	// �Q�[��
	if (m_pGame != nullptr) m_pGame->Draw(*m_handleData);
	// �G���f�B���O
	if (m_pEnding != nullptr) m_pEnding->Draw(*m_handleData);

	// ���[�J�[
	if (m_pMaker != nullptr) m_pMaker->Draw(*m_handleData);

	// ��ʂ̖��邳����
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_pSet->GetLight());
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}
