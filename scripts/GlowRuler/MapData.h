#pragma once
#include "Game.h"
#include <iostream>

namespace
{

	// �}�b�v�`�b�v�̏��
	constexpr int kChipWidth = 48;
	constexpr int kChipHeight = 48;

	// �`�b�v�̃}�X��
	constexpr int kChipNumX = 19;
	constexpr int kChipNumY = 14;


	////////////////////////////
	// �}�b�v�`�b�v�̔z�u��� //
	//////////////////////////////////////////////////////
	//  0 : �󔒁@										//
	//  1 : �ǁ@										//
	//  2 : �v���C���[�@								//
	//  3 : �F�ύX�� (30:�� 31:�� 32:�� 33:�� (34:��))�@//
	//  4 : ���F�� (40:�� 41:�� 42:�� 43:�� (44:��))�@	//
	//  5 : ����ʍs�� (50:��, 51:��, 52:��, 53:�E)�@	//
	//  6 : �S�[��										//
	//////////////////////////////////////////////////////
	constexpr int kStage[Game::kStageNum][kChipNumY][kChipNumX] =
	{
		// �X�e�[�W�O(�T���v���X�e�[�W)(�{�҂Ɏ����͂��Ȃ�)��������
		{
			{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
			{1 ,30,0 ,0 ,0 ,51,0 ,0 ,40,1 ,41,0 ,0 ,53,0 ,0 ,0 ,31,1 },
			{1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 },
			{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
			{1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 },
			{1 ,43,0 ,0 ,0 ,50,0 ,0 ,1 ,0 ,1 ,0 ,0 ,50,0 ,0 ,0 ,42,1 },
			{1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 },
			{1 ,41,0 ,0 ,0 ,52,0 ,0 ,1 ,0 ,1 ,0 ,0 ,52,0 ,0 ,0 ,40,1 },
			{1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 },
			{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
			{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,6 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
			{1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 },
			{1 ,32,0 ,0 ,0 ,51,0 ,0 ,42,1 ,43,0 ,0 ,53,0 ,0 ,0 ,33,1 },
			{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		},
		// �X�e�[�W1(�F�ς�)��
		{
			{0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,40,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,32,0 ,0 ,0 ,0 ,40,0 ,0 ,0 ,0 ,42,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,30,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,6 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		}
		,
		// �X�e�[�W2�i�F�̏㏑���j��
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,6 ,32,0 ,0 ,42,0 ,42,0 ,42,0 ,42,0 ,42,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,40,0 ,40,0 ,40,0 ,40,0 ,40,0 ,0 ,0 ,30,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,33,0 ,0 ,0 ,43,0 ,43,0 ,43,0 ,43,0 ,43,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,41,0 ,41,0 ,41,0 ,41,0 ,41,0 ,0 ,0 ,31,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,0 ,0 ,1 ,32,0 ,0 ,0 ,42,0 ,42,0 ,42,0 ,42,1 ,0 ,0 },
			{0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W3�i����ʍs�̓����j��
		{
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,41,0 ,41,0 ,41,0 ,41,0 ,41,0 ,41,53,41,1 ,0 ,0 },
			{0 ,0 ,1 ,50,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,43,0 ,0 ,53,43,1 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,50,1 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,52,1 ,1 ,1 ,1 ,1 ,52,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,43,51,0 ,0 ,43,0 ,53,0 ,0 ,6 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,50,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,31,1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,33,51,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,2 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W4(����ʍs�̎d�g�ݗ���)����
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 },
			{0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,52,0 ,1 ,0 ,0 ,0 ,0 },
			{0 ,1 ,2 ,0 ,0 ,30,53,0 ,0 ,1 ,40,0 ,0 ,51,1 ,0 ,0 ,0 ,0 },
			{0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,40,1 ,1 ,53,51,0 ,1 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,52,0 ,0 ,53,51,0 ,1 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,1 ,40,1 ,0 ,1 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,53,52,40,0 ,0 ,0 ,0 ,0 ,51,1 ,1 ,53,52,1 ,0 ,0 },
			{0 ,0 ,1 ,50,51,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,50,51,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,1 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,6 ,1 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W7(�S����)������
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,1 ,0 ,0 ,30,1 ,0 ,1 ,31,0 ,0 ,1 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,0 ,1 ,52,1 ,0 ,1 ,52,1 ,0 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,6 ,1 ,0 ,1 ,40,1 ,1 ,1 ,41,1 ,0 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,33,0 ,0 ,53,0 ,0 ,1 ,0 ,0 ,51,0 ,0 ,32,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,52,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,52,1 ,0 ,0 },
			{0 ,0 ,1 ,43,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,42,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W8�i����ɋt�炤�j������
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 },
			{0 ,0 ,0 ,0 ,1 ,1 ,1 ,31,0 ,0 ,41,51,0 ,51,0 ,0 ,0 ,1 ,0 },
			{0 ,0 ,1 ,1 ,1 ,33,0 ,0 ,0 ,0 ,0 ,0 ,43,51,0 ,51,0 ,1 ,0 },
			{0 ,1 ,1 ,31,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,41,51,52,1 ,1 },
			{0 ,1 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,51,0 ,6 ,1 },
			{0 ,1 ,1 ,1 ,30,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,40,51,50,1 ,1 },
			{0 ,0 ,0 ,1 ,1 ,1 ,32,0 ,0 ,0 ,0 ,0 ,42,51,0 ,51,0 ,1 ,0 },
			{0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,30,0 ,40,51,0 ,51,0 ,0 ,0 ,1 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W9�i�F�̏㏑���j��������
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,41,0 ,0 ,0 ,0 ,0 ,40,51,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,52,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,40,51,0 ,31,0 ,0 ,40,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,50,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,6 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,41,0 ,0 ,0 ,0 ,0 ,30,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,50,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W10�i�F�����j��������
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,32,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,1 ,0 ,32,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,0 ,30,43,0 ,0 ,0 ,6 ,0 ,0 ,0 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,31,0 ,0 ,0 ,30,0 ,0 ,0 ,30,1 ,0 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,32,0 ,1 ,31,0 ,0 ,0 ,0 ,0 ,0 ,31,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,33,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W11(����py...�^����)����
		{
			{0 ,1 ,30,30,1 ,1 ,31,31,1 ,1 ,1 ,32,32,1 ,1 ,33,33,1 ,0 },
			{1 ,1 ,1 ,1 ,1 ,1 ,1 ,51,1 ,1 ,1 ,51,1 ,1 ,1 ,1 ,1 ,1 ,1 },
			{1 ,0 ,53,0 ,0 ,0 ,0 ,40,0 ,0 ,0 ,40,0 ,0 ,52,0 ,0 ,0 ,1 },
			{1 ,0 ,0 ,0 ,0 ,0 ,0 ,41,0 ,0 ,0 ,41,0 ,0 ,0 ,0 ,0 ,52,1 },
			{1 ,0 ,0 ,53,0 ,0 ,0 ,42,0 ,0 ,0 ,42,0 ,0 ,0 ,0 ,52,0 ,1 },
			{1 ,53,0 ,0 ,0 ,0 ,0 ,43,0 ,0 ,0 ,43,0 ,0 ,0 ,0 ,0 ,0 ,1 },
			{52,41,43,40,42,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,41,40,43,42,50},
			{52,41,43,40,42,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,41,40,43,42,50},
			{1 ,0 ,0 ,0 ,0 ,43,0 ,0 ,53,30,53,0 ,0 ,40,0 ,0 ,51,0 ,1 },
			{1 ,0 ,50,0 ,0 ,40,0 ,0 ,53,31,53,0 ,0 ,41,0 ,51,0 ,0 ,1 },
			{1 ,0 ,0 ,50,0 ,41,0 ,0 ,53,32,53,0 ,0 ,42,0 ,0 ,0 ,0 ,1 },
			{1 ,50,0 ,0 ,0 ,42,0 ,0 ,53,33,53,0 ,0 ,43,0 ,0 ,0 ,51,1 },
			{1 ,1 ,1 ,1 ,1 ,53,1 ,1 ,1 ,2 ,1 ,6 ,1 ,53,1 ,1 ,1 ,1 ,1 },
			{0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 },
		},
		// �X�e�[�W12(�A�}�i�̍Ւd��)������
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 },
			{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,6 ,1 ,1 ,1 },
			{1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,30,0 ,53,52,52,52,53,0 ,51,0 ,1 },
			{1 ,32,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,51,0 ,0 ,40,40,40,51,0 ,1 },
			{1 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,53,43,50,50,50,50,50,0 ,1 },
			{1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,53,43,51,0 ,0 ,1 ,0 ,1 ,1 },
			{1 ,0 ,53,52,52,52,52,52,52,52,52,0 ,51,0 ,0 ,0 ,0 ,0 ,1 },
			{1 ,0 ,51,0 ,0 ,42,42,42,42,42,42,0 ,51,0 ,0 ,0 ,0 ,0 ,1 },
			{1 ,0 ,53,41,51,50,50,50,50,50,50,52,51,0 ,0 ,0 ,0 ,0 ,1 },
			{1 ,0 ,53,41,51,0 ,0 ,31,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 },
			{1 ,1 ,53,41,53,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,33,1 },
			{0 ,1 ,53,50,51,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,1 },
			{0 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 },
			{0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W13(����ʍs ��������)����������
		{
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
			{0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,6 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 },
			{0 ,1 ,52,52,52,50,52,52,53,43,51,52,52,50,52,52,53,1 ,0 },
			{0 ,1 ,53,52,50,50,51,51,52,52,52,50,50,51,53,52,51,1 ,0 },
			{0 ,1 ,51,53,52,53,50,51,52,50,50,50,51,51,51,51,53,1 ,0 },
			{0 ,1 ,53,52,52,53,53,50,50,52,52,50,50,51,50,50,50,1 ,0 },
			{0 ,1 ,53,52,50,50,53,53,51,53,52,51,53,52,50,50,52,1 ,0 },
			{0 ,1 ,50,53,53,53,53,50,51,51,53,52,53,53,50,51,53,1 ,0 },
			{0 ,1 ,50,51,53,52,52,50,51,53,53,50,50,52,50,50,51,1 ,0 },
			{0 ,1 ,53,53,50,51,53,52,50,50,52,50,50,50,50,53,52,1 ,0 },
			{0 ,1 ,50,53,52,50,50,51,53,52,53,53,50,50,53,52,51,1 ,0 },
			{0 ,1 ,53,50,51,51,53,52,51,33,53,53,50,53,51,53,52,1 ,0 },
			{0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 },
			{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
		},
		// �X�e�[�W15�i�F�̏㏑���j����������
		{
			{0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,43,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,0 ,43,1 ,43,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,43,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,42,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,33,0 ,0 ,42,1 ,42,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,0 ,40,0 ,0 ,30,0 ,32,0 ,0 ,42,0 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,40,1 ,40,0 ,0 ,31,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,40,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,41,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,41,1 ,41,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,41,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 },
			{0 ,0 ,1 ,2 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,6 ,1 ,0 ,0 },
			{0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 },
		}
		//// �X�e�[�W6(�ǂ����Ō����z�u...?)  �~
		//{
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//	{1 ,1 ,1 ,41,41,41,31,40,40,40,30,41,41,41,41,41,41,6 ,1 },
		//	{1 ,1 ,1 ,41,1 ,1 ,31,30,1 ,1 ,30,31,1 ,1 ,1 ,1 ,41,1 ,1 },
		//	{1 ,1 ,1 ,41,1 ,1 ,31,30,1 ,1 ,30,31,1 ,1 ,1 ,1 ,41,1 ,1 },
		//	{1 ,1 ,1 ,41,41,41,41,30,40,40,40,31,41,41,1 ,1 ,41,1 ,1 },
		//	{1 ,1 ,1 ,1 ,1 ,33,33,33,33,32,32,32,32,41,1 ,1 ,41,1 ,1 },
		//	{1 ,1 ,1 ,1 ,1 ,33,1 ,1 ,33,32,1 ,1 ,32,41,1 ,1 ,41,1 ,1 },
		//	{1 ,1 ,1 ,1 ,1 ,33,1 ,1 ,33,32,1 ,1 ,32,41,1 ,1 ,41,1 ,1 },
		//	{1 ,1 ,1 ,1 ,1 ,33,33,33,33,32,32,32,32,41,31,31,31,1 ,1 },
		//	{1 ,1 ,1 ,42,42,42,32,41,41,41,31,40,40,30,40,40,40,1 ,1 },
		//	{1 ,1 ,1 ,42,1 ,1 ,32,31,1 ,1 ,31,30,1 ,1 ,1 ,1 ,40,1 ,1 },
		//	{1 ,1 ,1 ,42,1 ,1 ,32,31,1 ,1 ,31,30,1 ,1 ,1 ,1 ,40,1 ,1 },
		//	{1 ,1 ,2 ,42,42,42,42,31,41,41,41,40,40,40,40,40,40,1 ,1 },
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//},
		//,,
		// �X�e�[�W14(�ጴ)������������
		/*
		{
			{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
			{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
			{1 ,34,34,44,44,44,34,44,34,34,1 ,34,34,34,44,34,44,1 ,1 },
			{1 ,34,34,1 ,1 ,34,1 ,44,34,34,34,34,1 ,34,34,34,34,1 ,1 },
			{1 ,1 ,34,1 ,1 ,34,1 ,34,34,44,34,34,34,34,34,1 ,34,44,1 },
			{1 ,44,44,34,34,34,34,34,1 ,44,44,34,34,44,44,34,44,44,1 },
			{1 ,34,34,34,44,34,44,34,1 ,34,34,34,34,34,34,34,1 ,44,1 },
			{1 ,44,44,34,34,1 ,34,44,44,1 ,1 ,1 ,34,34,34,34,1 ,44,1 },
			{1 ,44,1 ,34,34,1 ,34,34,44,44,1 ,34,34,34,1 ,44,34,44,1 },
			{1 ,34,34,34,34,1 ,34,1 ,34,44,44,34,34,34,1 ,34,34,44,1 },
			{1 ,44,34,34,44,44,34,1 ,44,1 ,34,34,34,44,34,34,34,44,1 },
			{1 ,44,34,1 ,34,34,1 ,1 ,44,34,44,44,34,44,34,44,1 ,34,1 },
			{1 ,6 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,2 ,1 },
			{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		}*/
		//// �X�e�[�W5(����������)�@�~
		//{
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//	{1 ,40,0 ,0 ,40,0 ,0 ,0 ,0 ,6 ,0 ,53,0 ,0 ,0 ,40,0 ,40,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,1 ,52,52,52,52,52,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,40,0 ,30,1 },
		//	{1 ,40,0 ,0 ,40,0 ,50,1 ,0 ,0 ,0 ,1 ,50,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,52,52,52,1 ,1 ,1 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,33,0 ,0 ,0 ,0 ,0 ,0 ,0 ,43,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,43,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,50,50,50,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,52,1 ,0 ,0 ,0 ,1 ,52,0 ,42,0 ,0 ,42,1 },
		//	{1 ,42,0 ,42,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,50,50,50,50,50,1 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,42,0 ,42,0 ,0 ,0 ,51,0 ,2 ,0 ,53,0 ,0 ,42,0 ,0 ,32,1 },
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//},
		//// �X�e�[�W16�iyamaguti�j�~
		//{
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//	{1 ,1 ,30,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,31,1 ,6 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,33,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 },
		//	{1 ,0 ,0 ,0 ,0 ,40,40,40,40,40,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 },
		//	{1 ,1 ,1 ,0 ,40,40,40,40,40,40,40,40,40,0 ,0 ,0 ,1 ,0 ,1 },
		//	{1 ,1 ,1 ,1 ,41,41,41,43,43,41,43,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,1 ,0 ,41,43,41,43,43,43,41,43,43,43,0 ,0 ,1 ,0 ,0 ,1 },
		//	{1 ,0 ,0 ,41,43,41,41,43,43,43,41,43,43,43,0 ,0 ,1 ,0 ,1 },
		//	{1 ,0 ,0 ,41,41,43,43,43,43,41,41,41,41,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,2 ,1 ,0 ,0 ,43,43,43,43,43,43,43,0 ,0 ,0 ,0 ,0 ,1 ,1 },
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//},
		//// �X�e�[�W17 (�g���C�t�H�[�X)�@�~
		//{
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//	{1 ,6 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,1 ,52,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,43,43,0 ,0 ,0 ,0 ,0 ,0 ,52,1 },
		//	{1 ,1 ,52,0 ,0 ,0 ,0 ,0 ,43,43,43,43,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,1 ,0 ,0 ,0 ,0 ,0 ,43,43,43,43,43,43,0 ,0 ,0 ,0 ,52,1 },
		//	{1 ,1 ,52,0 ,0 ,0 ,43,43,43,43,43,43,43,43,0 ,0 ,0 ,0 ,1 },
		//	{1 ,1 ,0 ,0 ,0 ,43,43,0 ,0 ,0 ,0 ,0 ,0 ,43,43,0 ,0 ,52,1 },
		//	{1 ,1 ,52,0 ,43,43,43,43,0 ,0 ,0 ,0 ,43,43,43,43,0 ,0 ,1 },
		//	{1 ,1 ,0 ,43,43,43,43,43,43,0 ,0 ,43,43,43,43,43,43,52,1 },
		//	{1 ,1 ,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,1 },
		//	{1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
		//	{1 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,33,1 },
		//	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
		//}

	};
}

class MapData
{
public:
	MapData();
	~MapData();
	// �}�b�v�f�[�^�̈����n��
	static int SetMap(int stageNum, int y, int x);

private:
	
};