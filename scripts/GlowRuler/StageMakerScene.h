#pragma once
#include "Vec2.h"
#include "MapData.h"

class Map;

class Wall;
class Player;
class PlayerLight;
class InColorFloor;
class OutColorFloor;
class DirWall;
class GoalPoint;
class Handle;

struct MapChip
{
	int stageData[kChipNumY][kChipNumX];
};

class StageMakerScene
{
public:
	StageMakerScene();
	~StageMakerScene();


	void Init(int gameMode);
	void Update();
	void ChipInit(int chipNum);
	void Draw(const Handle& handle);

	// ������X�e�[�W�f�[�^�̈����n��
	MapChip GetChip() const { return m_stage; }

	bool GetBackFlag()const { return m_isBack; }


private:
	// �X�e�[�W�f�[�^
	MapChip m_stage;

	// �`�b�v�f�[�^
	Wall* m_pWall;
	Player* m_pPlayer;
	PlayerLight* m_pLight;
	InColorFloor* m_pInColor;
	OutColorFloor* m_pOutColor;
	DirWall* m_pDirWall;
	GoalPoint* m_pGoal;
	// �v���C���[�̔z�u��
	bool m_isPlayer;
	// �S�[���̔z�u��
	bool m_isGoal;
	int m_goalColor;
	int m_R;
	int m_G;
	int m_B;

	// �X�e�[�W�쐬���[�h
	bool m_isMake;
	// �`�b�v�I��
	bool m_isSelect;
	// �X�e�[�W�ۑ��ׂ̈̃N���A�`�F�b�N
	bool m_isClear;
	
	// �I���J�[�\���ʒu
	Vec2 m_cursorPos;
	// ���[�h�I��
	int m_mode;
	//�@�}�X��
	int m_X;
	int m_Y;
	int m_animaTimer;
	float m_triMove;

	// �f�ޖ���string����
	int m_stringWidth;

	// �v���C����
	Map* m_pMap;

	// ���O�t���[���̃L�[���͏�
	bool m_isLastHitKey;

	// �^�C�g���o�b�N�t���O
	bool m_isBack;
};

