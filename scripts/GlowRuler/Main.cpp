#include "DxLib.h"
#include "Game.h"
#include "SceneManager.h"

// �X�N���[���T�C�Y
#define SCREEN_W 1600
#define SCREEN_H 900


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �A�C�R���ύX
	SetWindowIconID(111);

	// �V�X�e���o�[�^�C�g��
	SetWindowTextA("Glow Ruler");

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(SCREEN_W, SCREEN_H, Game::kColorDepth);		// �𑜓x��SCREEN_W*SCREEN_H�Acolor��16bit�ɐݒ�.
	
	// �E�C���h�E���[�h
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// ����ʂɕ`����s��
	SetDrawScreen(DX_SCREEN_BACK);

	// Scene�J�n
	SceneManager* manager = new SceneManager;
	manager->Init();

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// �t���[���J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A�ɂ���
		ClearDrawScreen();

		// �Q�[���̏���
		manager->Update();
		manager->Draw();
		manager->SceneMove();
		// ChangeFontFromHandle(fontHandle_32);

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// end����
		if (manager->End())
		{
			// �������̉��
			delete manager;
			manager = nullptr;
			break;
		}


		// FPS��60�ɌŒ�
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16,66�~���b(16667�}�C�N���b)�o�߂܂ő҂�
		}
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}