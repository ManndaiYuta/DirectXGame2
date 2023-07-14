#include "Player.h"
#include"TextureManager.h"
#include"MathUtilityForText.h"
Player::Player() {}

Player::~Player() 
{ 
	
	delete modelPlayer_;

}

void Player::Initialize(ViewProjection view) 
{ 
	textureHandolePlayer_ = TextureManager::Load("player.png");
	modelPlayer_ = Model::Create();
	worldTransformPlayer_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformPlayer_.Initialize();
	
	viewProjection_ = view;
	input_ = Input::GetInstance();
	

}

void Player::Update() 
{
	//変換行列を更新
	worldTransformPlayer_.matWorld_ = MakeAffineMatrix(
	    worldTransformPlayer_.scale_, worldTransformPlayer_.rotation_,
	    worldTransformPlayer_.translation_);
	//変換行列を定数バッファに転送
	worldTransformPlayer_.TransferMatrix();
	//移動処理
	if (input_->PushKey(DIK_RIGHT)) 
	{
		worldTransformPlayer_.translation_.x += 0.1f;
	}
	if (input_->PushKey(DIK_LEFT)) 
	{
		worldTransformPlayer_.translation_.x -= 0.1f;
	}
	if (worldTransformPlayer_.translation_.x < -4) {
		worldTransformPlayer_.translation_.x = -4;
	}
	if (worldTransformPlayer_.translation_.x > 4) {
		worldTransformPlayer_.translation_.x = 4;
	}

}

void Player::Draw3D() 
{
	modelPlayer_->Draw(worldTransformPlayer_, viewProjection_, textureHandolePlayer_);

}
