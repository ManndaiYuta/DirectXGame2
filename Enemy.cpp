#include "Enemy.h"
#include"TextureManager.h"
#include"MathUtilityForText.h"


Enemy::Enemy() {}

Enemy::~Enemy() 
{
	delete modelEnemy_; 
}

void Enemy::Initialize(ViewProjection view) 

{
	textureHandoleEnemy_ = TextureManager::Load("enemy.png");
	modelEnemy_ = Model::Create();
	worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformEnemy_.Initialize();

	viewProjection_ = view;
}

void Enemy::Update() 
{
	Move();
	Born();
	// 変換行列を更新
	worldTransformEnemy_.matWorld_ = MakeAffineMatrix(
	    worldTransformEnemy_.scale_, worldTransformEnemy_.rotation_,
	    worldTransformEnemy_.translation_);
	// 変換行列を定数バッファに転送
	worldTransformEnemy_.TransferMatrix();
}

void Enemy::Draw3D() 
{
	if (aliveFlag_ == true) 
	{
		modelEnemy_->Draw(worldTransformEnemy_, viewProjection_, textureHandoleEnemy_);
	}
	
}

void Enemy::Move() 
{
	if (aliveFlag_==true) 
	{
		worldTransformEnemy_.translation_.z -= 0.2f;
		worldTransformEnemy_.rotation_.z += 0.2f;
		if (worldTransformEnemy_.translation_.z <=-5) 
		{
			aliveFlag_ = false;
		}
		
    }
}

void Enemy::Born() 
{
	if (aliveFlag_ == false) 
	{
		int x = rand() % 80;
		float x2 = (float)x / 10 - 4;
		aliveFlag_ = true;
		worldTransformEnemy_.translation_.x = x2;
		worldTransformEnemy_.translation_.z = 40.f;
		
	}

}
