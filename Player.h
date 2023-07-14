#pragma once
#include"Sprite.h"
#include"ViewProjection.h"

#include"Model.h"
#include"WorldTransform.h"
#include"Input.h"
class Player 
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//初期化
	void Initialize(ViewProjection view);

	//更新
	void Update();

	//3D背景描画
	void Draw3D();
	// 呼び出し
	float GetX() { return worldTransformPlayer_.translation_.x;}
	float GetZ() { return worldTransformPlayer_.translation_.z;}

private:
	ViewProjection viewProjection_;
	//プレイヤー
	uint32_t textureHandolePlayer_ = 0;
	Model* modelPlayer_ = nullptr;
	WorldTransform worldTransformPlayer_;

	//インプットクラス
	Input* input_ = nullptr;
};
