#pragma once
#include "DxLib.h"


//ゲーム全体で使う定数を定義
namespace Game
{
	constexpr int kSceneNum = 4;

	constexpr int kMapWidth = 640;      //画面の横幅
	constexpr int kMapHeight = 480;     //画面の縦幅

	constexpr int kScreenWidth = 1600;      //画面の横幅
	constexpr int kScreenHeight = 900;     //画面の縦幅

	// ゲーム内で使う画像等の基本サイズ
	constexpr int kGraphWidth = 48;
	constexpr int kGraphHeight = 48;

	// 半分のサイズ
	constexpr float kGraphHalfWidth = kGraphWidth * 0.5f;
	constexpr float kGraphHalfHeight = kGraphHeight * 0.5f;

	constexpr int kColorDepth = 32;        //16 or 32

	// ステージ数(サンプルステージ含む)
	constexpr int kStageNum = 13;

	// BGMの数
	constexpr int kBGMNum = 4;
	constexpr int kSENum = 10;

	// チップのマス数
	constexpr int kChipNumX = 20;
	constexpr int kChipNumY = 14;

	// チップを置く場所の開始点
	constexpr int kMapStartPosX = (kScreenWidth - (kChipNumX * kGraphWidth)) / 2;
	constexpr int kMapStartPosY = (kScreenHeight - (kChipNumY * kGraphHeight)) / 2;
}

