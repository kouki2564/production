#pragma once
#include "Vec2.h"
#include <vector>

class Window;
class Sound;
class Handle;

struct bg
{
	// �^�C�g��Bg
	Vec2 m_bgPos = { 0,0 };
	int m_bgColor = 0;

	Vec2 m_wavePos = { 0,0 };
	bool m_isWave = 0;
	int m_waveDir = 0;

	bool m_isLight = 0;
	Vec2 m_bgLightMove = {0,0};
	int m_moveTimer = 0;
	int m_bgCoolTimer = 0;
};

class TitleScene
{
public:
	TitleScene();
	~TitleScene();

	void Init(int light, int BGM, int SE, const Handle& handle);
	void Update();
	void Draw(const Handle& handle);

	bool GetTransFlag() const { return m_isTransScene; }
	int GetStartNum() const { return m_startNum; }
	int GetMode() const { return m_gameMode; }
	bool GetEndFlag() const { return m_isEnd; }

	int GetLight() const;
	int GetBGM() const;
	int GetSE() const;
	void SetUti(int BGM, int SE, int light);

private:
	// int m_handle;
	// �^�C�g���ʒu
	Vec2 m_pos;
	// �^�C�g���T�C�Y(Width)
	int m_titleWidth;
	int m_startWidth;
	int m_selectWidth;
	// ���ߓx�A���t�@
	int m_alpha;
	bool m_isAlpha;
	// press�̓_�Ŏ���
	int m_appStartTimer;
	int m_appSelectTimer;
	// �V�[���J�ڃt���O
	bool m_isKey;
	bool m_isTransScene;
	// �Q�[���̊J�n�_
	int m_startNum;
	// ���O�t���[���ŃL�[��������Ă�����
	bool m_isRastHit;
	// �J�[�\���ʒu
	Vec2 m_cursorPos;
	// �J�[�\���ӏ�(0:�^�C���A�^�b�N�@1:�I���X�^�[�g�@2:�ݒ�@3:�Q�[���I���@4:�����\�L)
	int m_menuNum;
	int m_cursorMove;
	int m_cursorMoveVec;
	// �Q�[�����[�h�̑I���@�O�F�^�C���A�^�b�N�@�P�F�I���X�^�[�g
	int m_gameMode;
	// �Q�[���I���t���O
	bool m_isEnd;

	Window* m_pWindow;
	bool m_isMaker;
	bool m_isSetting;
	bool m_isCredit;

	bool m_isWindow;

	// �T�E���h
	std::vector<Sound*> m_pSound;

	// �^�C�g��Bg
	std::vector<bg> m_bg;
};

