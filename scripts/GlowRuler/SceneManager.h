#pragma once

class TitleScene;
class GameScene;
class EndingScene;
class File;
class Uti;
class StageMakerScene;

class Sound;

class Handle;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void SceneMove();
	void Update();
	void Draw();

	bool End() const { return m_isEnd; }
private:
	// �n���h���f�[�^
	Handle* m_handleData;
	// �Z�[�u�f�[�^
	File* m_dataFile;

	// �^�C�g��
	TitleScene* m_pTitle;
	int m_gameMode;
	// �Q�[������
	GameScene* m_pGame;
	int m_stageNum;
	bool m_isTransScene;
	// �G���f�B���O
	EndingScene* m_pEnding;

	// ���[�J�[
	StageMakerScene* m_pMaker;

	// �S�̋��ʂ̐ݒ蕔��
	Uti* m_pSet;
	int m_lightPow;
	int m_BGMPow;
	int m_SEPow;

	// ���ʃ^�C��
	int m_time;
	// �Q�[���I���t���O
	bool m_isEnd;

	bool m_isMaker;

	int m_handleNum;
	int m_handleTimer;
};

