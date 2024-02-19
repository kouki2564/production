#pragma once
#include "Vec2.h"
#include <vector>
class Uti;
class Sound;

class Handle;

class Window
{
public:
	Window();
	~Window();
	void Init(const Handle& handle);
	void Open();
	void Close();
	void WindowDraw(const Handle& handle);

	// �E�C���h�E�̎��
	void Pause(bool flag);
	void Setting();
	void Credit();
	void Maker();

	void CursorUpdate();

	bool GetBackTitle()const { return m_isTitle; }
	bool GetPause()const { return m_isPause; }
	bool GetMakerFlag() const { return m_isMaker; }
	bool GetGoMakeFlag()const { return m_isGoMake; }
	bool GetSettingFlag() const { return m_isSetting; }
	bool GetCreditFlag() const { return m_isCredit; }


	int GetBGM() const { return m_BGMSet; }
	void SetSetting(int BGM, int SE, int light);
	int GetSE() const { return m_SESet; }
	int GetLight() const { return m_lightSet; }

private:
	// �E�C���h�E��ʃT�C�Y
	int m_menuWidth;
	int m_menuHeight;

	// �e�E�C���h�E�̕\����
	bool m_isWindow;
	// �|�[�Y
	bool m_isPause;
	// �ݒ�
	bool m_isSetting;
	// �N���W�b�g
	bool m_isCredit;
	// �X�e�[�W���[�J�[
	bool m_isMaker;
	bool m_isGoMake;
	int m_goTimer;
	bool m_isSelect;
	int m_stageNum;

	// ������̊J�n�_�ix���W�j
	Vec2 m_stringPos;
	float m_BackWidth;
	// ������\���t���O
	bool m_isAppString;

	// �|�[�Y����^�C�g���֖߂�t���O
	bool m_isTitle;
	int m_keyTimer;

	bool m_isRastHit;

	// BGM����( 1 �` 5 )
	bool m_isBGM;
	int m_BGMSet;

	// SE����( 1 �` 5 )
	bool m_isSE;
	int m_SESet;

	// ����( 1 �` 5 )
	bool m_islight;
	int m_lightSet;

	// �J�[�\���ʒu
	Vec2 m_cursorPos;
	// �J�[�\���ӏ�(0:�^�C���A�^�b�N�@1:�I���X�^�[�g�@2:�ݒ�@3:�Q�[���I���@4:�����\�L)
	int m_menuNum;

	// �T�E���h
	std::vector<Sound*> m_pSound;
};

