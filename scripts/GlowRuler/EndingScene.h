#pragma once
#include "Vec2.h"
#include <vector>

struct Rank
{
	int time_1;
	int time_2;
	int time_3;
	int time_4;
	int time_5;

};

class Sound;

class Handle;

class EndingScene
{
public:
	EndingScene();
	~EndingScene();

	void Init(int time, int gameMode,int BGM,int SE, const Rank& timeRank, const Handle& handle);
	void Update();
	void Draw(const Handle& handle);

	bool GetTransFlag() const { return m_isTransScene; }

private:
	// int m_handle;
	// �^�C�g���ʒu
	Vec2 m_pos;
	// �^�C�g���T�C�Y(Width)
	int m_clearWidth;
	int m_startWidth;
	int m_timeWidth;
	// ���ߓx�A���t�@
	int m_alpha;
	bool m_isAlpha;
	// press�̓_�Ŏ���
	int m_appStartTimer;
	// �V�[���J�ڃt���O
	bool m_isKey;
	bool m_isTransScene;

	int m_gameMode;
	int m_resultTime;
	Rank m_RankResult;

	// �T�E���h
	std::vector<Sound*> m_pSound;

	// �G�t�F�N�g
	int m_efectDir;
	int m_FadeAlpha;

	// �����L���O
	int m_rankPosMove[5];
	int m_flashTimer;
	bool m_isUpdateSound;
};

