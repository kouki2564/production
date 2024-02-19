#pragma once
#include "DxLib.h"

struct handleData
{
	// �O���t�B�b�N�f�[�^
	int hi_inColor;
	int hi_countWindow;
	int hi_dirWall;
	int hi_logoBg;
	int hi_wall;
	int hi_ChipFilter;
	int hif_Filter;

	// BGM�f�[�^
	int hm_B_0;
	int hm_B_1;
	int hm_B_2;

	// SE�f�[�^
	int hm_S_00;
	int hm_S_01;
	int hm_S_02;
	int hm_S_03;
	int hm_S_04;
	int hm_S_05;
	int hm_S_06;
	int hm_S_07;
	int hm_S_08;
	int hm_S_09;
	int hm_S_10;
	int hm_S_11;
	int hm_S_12;

	// �t�H���g�f�[�^
	
	// �^�C�g���t�H���g
	int hf_title;
	int hf_backTitle;
	// �p��t�H���g
	int hf_starry_20;
	int hf_starry_32;
	int hf_starry_40;
	int hf_starry_48;
	int hf_starry_64;
	// ���{��t�H���g
	int hf_util_16;
	int hf_util_20;
	int hf_util_24;
	int hf_util_32;
	int hf_util_48;
	int hf_util_72;
};

class Handle
{
public:
	handleData h_data;

	Handle() 
	{
		// �O���t�B�b�N�f�[�^
		h_data.hi_inColor = LoadGraph("data/image/change.png");
		h_data.hi_countWindow = LoadGraph("data/image/count.png");
		h_data.hi_dirWall = LoadGraph("data/image/dir.png");
		h_data.hi_logoBg = LoadGraph("data/image/logoBg.png");
		h_data.hi_wall = LoadGraph("data/image/wall.png");
		h_data.hi_ChipFilter = LoadGraph("data/image/ChipFilter.png");
		h_data.hif_Filter = MakeScreen(48, 48, true);
		// BGM�f�[�^
		h_data.hm_B_0 = LoadSoundMem("data/Sound/BGM_0_Title.mp3");
		h_data.hm_B_1 = LoadSoundMem("data/Sound/BGM_1_Game.mp3");
		h_data.hm_B_2 = LoadSoundMem("data/Sound/BGM_3_Maker.mp3");

		// SE�f�[�^  
		h_data.hm_S_00 = LoadSoundMem("data/Sound/SE_00_Cursor.mp3");
		h_data.hm_S_01 = LoadSoundMem("data/Sound/SE_01_Dec.mp3");
		h_data.hm_S_02 = LoadSoundMem("data/Sound/SE_02_Not.mp3");
		h_data.hm_S_03 = LoadSoundMem("data/Sound/SE_03_Window.mp3");
		h_data.hm_S_04 = LoadSoundMem("data/Sound/SE_04_Hit.mp3");
		h_data.hm_S_05 = LoadSoundMem("data/Sound/SE_05_GetColor.mp3");
		h_data.hm_S_06 = LoadSoundMem("data/Sound/SE_06_SetColor.mp3");
		h_data.hm_S_07 = LoadSoundMem("data/Sound/SE_07_AllSet.mp3");
		h_data.hm_S_08 = LoadSoundMem("data/Sound/SE_08_Goal.mp3");
		h_data.hm_S_09 = LoadSoundMem("data/Sound/SE_09_Update.mp3");
		h_data.hm_S_10 = LoadSoundMem("data/Sound/SE_10_Reset.mp3");
		h_data.hm_S_11 = LoadSoundMem("data/Sound/SE_11_Rank.mp3");
		h_data.hm_S_12 = LoadSoundMem("data/Sound/BGM_2_Result.mp3");

		// �t�H���g�f�[�^
		// �^�C�g���t�H���g
		h_data.hf_title = CreateFontToHandle("GLT-StarrySky", 90, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_backTitle = CreateFontToHandle("GLT-StarrySky", 90, 5, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		// �p��t�H���g
		h_data.hf_starry_20 = CreateFontToHandle("GLT-StarrySky", 20, 5, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_starry_32 = CreateFontToHandle("GLT-StarrySky", 32, 5, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_starry_40 = CreateFontToHandle("GLT-StarrySky", 40, 5, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_starry_48 = CreateFontToHandle("GLT-StarrySky", 48, 5, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_starry_64 = CreateFontToHandle("GLT-StarrySky", 64, 5, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		// ���{��t�H���g
		h_data.hf_util_16 = CreateFontToHandle("���z�� �l�N�X�g UP B", 16, 6, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_util_20 = CreateFontToHandle("���z�� �l�N�X�g UP B", 20, 6, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_util_24 = CreateFontToHandle("���z�� �l�N�X�g UP B", 24, 6, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_util_32 = CreateFontToHandle("���z�� �l�N�X�g UP B", 32, 6, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_util_48 = CreateFontToHandle("���z�� �l�N�X�g UP B", 48, 6, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
		h_data.hf_util_72 = CreateFontToHandle("���z�� �l�N�X�g UP B", 72, 6, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	}
	~Handle()
	{
		// �O���t�B�b�N�f�[�^
		DeleteGraph(h_data.hi_inColor);
		DeleteGraph(h_data.hi_countWindow);
		DeleteGraph(h_data.hi_dirWall);
		DeleteGraph(h_data.hi_logoBg);
		DeleteGraph(h_data.hi_wall);
		DeleteGraph(h_data.hi_ChipFilter);
		DeleteGraph(h_data.hif_Filter);

		// BGM�f�[�^
		DeleteSoundMem(h_data.hm_B_0);
		DeleteSoundMem(h_data.hm_B_1);
		DeleteSoundMem(h_data.hm_B_2);

		// SE�f�[�^
		DeleteSoundMem(h_data.hm_S_00);
		DeleteSoundMem(h_data.hm_S_01);
		DeleteSoundMem(h_data.hm_S_02);
		DeleteSoundMem(h_data.hm_S_03);
		DeleteSoundMem(h_data.hm_S_04);
		DeleteSoundMem(h_data.hm_S_05);
		DeleteSoundMem(h_data.hm_S_06);
		DeleteSoundMem(h_data.hm_S_07);
		DeleteSoundMem(h_data.hm_S_08);
		DeleteSoundMem(h_data.hm_S_09);
		DeleteSoundMem(h_data.hm_S_10);
		DeleteSoundMem(h_data.hm_S_11);
		DeleteSoundMem(h_data.hm_S_12);

		// �t�H���g�f�[�^

		DeleteFontToHandle(h_data.hf_title);
		DeleteFontToHandle(h_data.hf_backTitle);

		DeleteFontToHandle(h_data.hf_starry_20);
		DeleteFontToHandle(h_data.hf_starry_32);
		DeleteFontToHandle(h_data.hf_starry_40);
		DeleteFontToHandle(h_data.hf_starry_48);
		DeleteFontToHandle(h_data.hf_starry_64);

		DeleteFontToHandle(h_data.hf_util_16);
		DeleteFontToHandle(h_data.hf_util_20);
		DeleteFontToHandle(h_data.hf_util_24);
		DeleteFontToHandle(h_data.hf_util_32);
		DeleteFontToHandle(h_data.hf_util_48);
		DeleteFontToHandle(h_data.hf_util_72);
	}
};

