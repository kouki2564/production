#pragma once
#include "Game.h"
#include "Rect.h"
#include "DxLib.h"
#include "MapData.h"
#include <vector>
using namespace std;


namespace
{
	// �\��������M�~�b�N�̎��
	constexpr int kGimmickNum = 6;

	// �`�b�v��u���ꏊ�̊J�n�_
	constexpr int kMapStartPosX = (Game::kScreenWidth - (kChipNumX * kChipWidth)) / 2;
	constexpr int kMapStartPosY = (Game::kScreenHeight - (kChipNumY * kChipHeight)) / 2;
}

class Wall;
class Player;
class PlayerLight;
class InColorFloor;
class OutColorFloor;
class DirWall;
class GoalPoint;

class Handle;

class EfectColor;

class Sound;

class GameBg;

class FileQuickTime;

class pColorBg;

class Map
{
public:
	Map();
	~Map();

	void Init(int mode, int mapNum, int BGM, int SE, const Handle& handle);
	void Update(bool isPause);
	void Draw(const Handle& handle);
	void Reset();

	void GoalDraw(const Handle& handle);

	bool GetTransFlag() const { return m_isTransScene; }
	int GetTime() const { return m_timer; }

	int GetAlpha() const { return m_alpha; }

	void SetSound(int BGM, int SE);

	bool GetUpdateFlag() const { return m_isUpdateTime; }

private:

	// �Q�[�����[�h
	int m_mode;
	// �X�e�[�W��ǂݍ��ޔ�
	int chipData[kChipNumY][kChipNumX];
	//int m_chipHandle[kGimmickNum];
	// �v���C���[
	Player* m_pPlayer;
	PlayerLight* m_pLight;
	// ��
	vector<Wall*> m_pWall;
	int m_wallCount;
	// �F�ύX��
	vector<InColorFloor*> m_pInColor;
	int m_inColorCount;
	// ���F��
	vector<OutColorFloor*> m_pOutColor;
	int m_outColorCount;
	// ����ʍs��
	vector<DirWall*> m_pDirWall;
	int m_dirWallCount;
	// �S�[��
	GoalPoint* m_pGoal;
	int m_paintCount;
	bool m_isClear;
	// �V�[���J�ڃt���O
	bool m_isTransScene;
	// �J�ڎ��̃A���t�@�l
	int m_alpha;
	// �^�C���A�^�b�N�p
	bool m_timeAttack;
	int m_timer;

	vector<EfectColor*> m_pEfect;

	// �T�E���h
	std::vector<Sound*> m_pSound;
	int m_BGM;
	int m_SE;

	// �o�b�N�O���E���h
	vector<GameBg*> m_pBg;
	int m_clearBgColor;

	// �ŒZ��
	FileQuickTime* m_pData;
	int m_mapNum;
	// �L�^�X�V
	bool m_isUpdateTime;

	pColorBg* m_pColorBg;
	int m_stringTimer;

	// �N���A�\�L
	int m_clearWindowTimer;
	Vec2 m_clearPos;
	int m_clearWindowY;

	// ���Z�b�g
	bool m_isReset;
	
};