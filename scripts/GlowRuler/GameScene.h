#pragma once
#include "Vec2.h"


// class GameBg;
class Map;
class GameUI;
class Window;
class Handle;

class File;

class GameScene
{
public:
	GameScene();
	~GameScene();


	void Init(int stageNum, int gameMode, int light, int BGM, int SE, const Handle& handle);
	void StageUpdate(const Handle& handle);
	void Update();
	void Draw(const Handle& handle);

	bool GetTransFlag() const { return m_isTransScene; }
	int GetTime() const { return m_time; }
	int GetSumTime() const { return m_sumTime; }
	bool GetBackFlag() const { return m_isBackScene; }

	int GetBGM() const;
	int GetSE() const;
	int GetLight() const;
	void SetUti(int BGM, int SE, int light);

private:
	// �Q�[���{��
	Map* m_pMap;
	int m_stageNum;
	// UI
	GameUI* m_pUI;
	bool m_isPause;
	bool m_isSetting;
	// �|�[�Y
	Window* m_pWindow;
	bool m_isBackScene;
	// �V�[���S��
	// �V�[���J�ڃt���O
	bool m_isTransScene;
	// �J�n�ƃN���A���̖���
	int m_alpha;

	Vec2 m_timePos;
	int m_time;
	int m_timeWidth;
	int m_sumTime;

	int m_isTimeAttack;

	bool m_isRastHit;

	int m_keyTimer;

	// �L�^�X�V���̓_�ŗp
	int m_UpdateTimer;
};

