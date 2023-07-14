#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DebugText.h"

#include"Stage.h"
#include"Player.h"
#include"Beam.h"
#include"Enemy.h"
#include"ChangeSceen.h"


class GamePlay : public ChangeSceen
{
public:
	GamePlay();
	~GamePlay();
	void Initialize(ViewProjection view);
	
	void Update(Change &scene);

	// 2D背景描画
	void Draw2DFar();

	//
	void Draw3D();

	void Draw2DNear();

	void CollisonPlayerEnemy();
	void CollisonBeamEnemy();

private:
	// ステージ
	Stage* stage_ = nullptr;
	// ビュープロジェション
	ViewProjection viewProjection_;
	// プレイヤー
	Player* player_ = nullptr;
	// ビーム
	Beam* beam_ = nullptr;
	// 敵
	Enemy* enemy_ = nullptr;
	//
	//
	DebugText* debugTex_ = nullptr;
	int gameScore_ = 0;
	int playerLife_ = 3;
};
