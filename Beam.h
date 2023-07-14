#pragma once
#include"Sprite.h"
#include"ViewProjection.h"

#include"Model.h"
#include"WorldTransform.h"
#include"Input.h"
#include"Player.h"
class Beam 
{
public:
	//コンストラクタ
	Beam();
	//デストラクタ
	~Beam();
	// 初期化
	void Initialize(ViewProjection view,Player* player);

	// 更新
	void Update();

	// 3D背景描画
	void Draw3D();

	//移動処理
	void Move();

	//発生（発射）
	void Born();
	//
	Player* player_ = nullptr;
	//
	float GetX() { return worldTransformBeam_.translation_.x; }
	float GetZ() { return worldTransformBeam_.translation_.z; }
	//
	bool GetIsAlive() { return aliveFlag_; }
	
	void Hit() { aliveFlag_ = 0; }

private:
	ViewProjection viewProjection_;

	uint32_t textureHandoleBeam_ = 0;
	Model* modelBeam_ = nullptr;
	WorldTransform worldTransformBeam_;
	// インプットクラス
	Input* input_ = nullptr;
	//存在フラグ
	bool aliveFlag_=false;
};
