#include "Beam.h"
#include"TextureManager.h"
#include"MathUtilityForText.h"

Beam::Beam() {}

Beam::~Beam() 
{ 
	delete modelBeam_;
}

void Beam::Initialize(ViewProjection view,Player*player) 
{ 
	textureHandoleBeam_ = TextureManager::Load("beam.png"); 
    modelBeam_ = Model::Create();
	worldTransformBeam_.scale_ = {0.3f, 0.3f, 0.3f};
	worldTransformBeam_.Initialize();

	viewProjection_ = view;
	player_ = player;
	input_ = Input::GetInstance();
}

void Beam::Update() 
{
	Move();
	Born();
	// 変換行列を更新
	worldTransformBeam_.matWorld_ = MakeAffineMatrix(
	    worldTransformBeam_.scale_, worldTransformBeam_.rotation_,
	    worldTransformBeam_.translation_);
	// 変換行列を定数バッファに転送
	worldTransformBeam_.TransferMatrix();

}

void Beam::Draw3D() 
{
	if (aliveFlag_ == true) 
	{
		modelBeam_->Draw(worldTransformBeam_, viewProjection_, textureHandoleBeam_); 
	}
	
}


void Beam::Move() 
{ 
	if (aliveFlag_ == true) 
    {
		worldTransformBeam_.translation_.z += 0.5f;
		worldTransformBeam_.rotation_.x += 0.1f;
		if (worldTransformBeam_.translation_.z >= 40.0f) 
		{
			aliveFlag_ = false;
		}
	}
	

}

void Beam::Born() 
{ 
	if (input_->TriggerKey(DIK_SPACE) && !aliveFlag_) 
	{
		
		aliveFlag_ = true;
		worldTransformBeam_.translation_.x = player_->GetX();
	    worldTransformBeam_.translation_.z = player_->GetZ();

	}

}
