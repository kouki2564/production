#pragma once
#include "Vec2.h"
#include "Rect.h"

class Map;
class Sound;

namespace
{
	// �ړ����x
	constexpr float kSpeed = 16.0f;
	constexpr float kGoalSpeed = 0.25f;

	// �v���C���[�T�C�Y
	constexpr int kSize = 15;
	constexpr int kEyeSize = 3;
	constexpr int kDontEyeSize = 5;
}

class Player
{
public:
	// �����Ă������
	enum Dir
	{
		kDirDown,	// ��
		kDirLeft,	// ��
		kDirRight,	// �E
		kDirUp		// ��
	};

	Player();
	~Player();
	void Init(float x, float y);
	void Update();
	void Draw();
	bool DrawPlayer(Vec2 point);

	void WallHit (Rect& wall);
	void DirWallHit(Rect& DirWall, bool& isPass);
	void GoalIn(Rect& goal);


	// �v���C���[�̌��݈ʒu���擾����
	Vec2 GetPos() const { return m_pos; }
	// �v���C���[�̓����蔻����擾����
	Rect GetColRect() const { return m_colRect; }
	// �v���C���[�̃S�[���󋵂��擾
	bool GetGoal() const { return m_isClear; }
	// �ǂƂ̓����蔻��
	bool GetHitFlag() const { return m_wallHit; }
	// �ړ���
	int GetMoveTime() const { return m_moveTime; }
	// �ꏊ���Z�b�g
	void ResetPos() { m_pos = m_firstPos;	m_dir = kDirDown;  m_moveTime = 0; }
	
private:
	// �O���t�B�b�N
	// int m_handle;
	// �ړ������ǂ���
	bool m_isMove;
	// �ʒu
	Vec2 m_pos;
	Vec2 m_firstPos;
	// �ړ���
	Vec2 m_move;
	// �����蔻��p�̋�`
	Rect m_colRect;
	// ����
	Dir m_dir;
	// player�A�j���[�V����
	// int m_animaFrame;

	bool m_wallHit;

	// �e�L�[���������ςȂ��ǂ���
	bool m_isLongUpKey; 
	bool m_isLongDownKey;
	bool m_isLongLeftKey;
	bool m_isLongRightKey;
	// �v���C���[���S�[���ɐG�ꂽ���ǂ���
	bool m_isClear;
	// �ړ���
	Vec2 m_moving;
	int m_moveTime;
};