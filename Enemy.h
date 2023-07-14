#pragma once
#pragma once
#include "Sprite.h"
#include "ViewProjection.h"

#include "Model.h"
#include "WorldTransform.h"

class Enemy 
{
public:
	//コンストラクタ
	Enemy();
	
	//デストラクタ
	~Enemy();
	 
	// 初期化
	void Initialize(ViewProjection view);

	// 更新
	void Update();

	// 3D背景描画
	void Draw3D();
	
	//移動処理
	void Move();

	//発生
	void Born();

	//衝突判定
	void Hit() { aliveFlag_ = 0; }
	//
	int GetFlag() { return aliveFlag_; }
	float GetX() { return worldTransformEnemy_.translation_.x; }
	float GetZ() { return worldTransformEnemy_.translation_.z; }

	bool GetIsAlive() { return aliveFlag_; }
	


private:
	ViewProjection viewProjection_;

	uint32_t textureHandoleEnemy_ = 0;
	Model* modelEnemy_ = nullptr;
	WorldTransform worldTransformEnemy_;
	bool aliveFlag_ = false;
};
