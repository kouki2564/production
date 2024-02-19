#pragma once
#include "DxLib.h"


//�Q�[���S�̂Ŏg���萔���`
namespace Game
{
	constexpr int kSceneNum = 4;

	constexpr int kMapWidth = 640;      //��ʂ̉���
	constexpr int kMapHeight = 480;     //��ʂ̏c��

	constexpr int kScreenWidth = 1600;      //��ʂ̉���
	constexpr int kScreenHeight = 900;     //��ʂ̏c��

	// �Q�[�����Ŏg���摜���̊�{�T�C�Y
	constexpr int kGraphWidth = 48;
	constexpr int kGraphHeight = 48;

	// �����̃T�C�Y
	constexpr float kGraphHalfWidth = kGraphWidth * 0.5f;
	constexpr float kGraphHalfHeight = kGraphHeight * 0.5f;

	constexpr int kColorDepth = 32;        //16 or 32

	// �X�e�[�W��(�T���v���X�e�[�W�܂�)
	constexpr int kStageNum = 13;

	// BGM�̐�
	constexpr int kBGMNum = 4;
	constexpr int kSENum = 10;

	// �`�b�v�̃}�X��
	constexpr int kChipNumX = 20;
	constexpr int kChipNumY = 14;

	// �`�b�v��u���ꏊ�̊J�n�_
	constexpr int kMapStartPosX = (kScreenWidth - (kChipNumX * kGraphWidth)) / 2;
	constexpr int kMapStartPosY = (kScreenHeight - (kChipNumY * kGraphHeight)) / 2;
}

