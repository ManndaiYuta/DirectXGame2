#include "GamePlay.h"


GamePlay::GamePlay() 
{}

GamePlay::~GamePlay() 
{
	delete stage_;
	delete player_;
	delete beam_;
	delete enemy_;
	
}

void GamePlay::Initialize(ViewProjection view) 
{
	
	viewProjection_ = view;
	viewProjection_;
	
	
	// ステージ初期化
	stage_ = new Stage();
	stage_->Initialize(viewProjection_);
	// プレイヤー
	player_ = new Player();
	player_->Initialize(viewProjection_);
	// ビーム
	beam_ = new Beam();
	beam_->Initialize(viewProjection_, player_);

	// 敵
	enemy_ = new Enemy();
	enemy_->Initialize(viewProjection_);

	//
	debugTex_ = DebugText::GetInstance();
	debugTex_->Initialize();
	
}

void GamePlay::Update(Change& scene)
{
	
	stage_->Update();
	player_->Update();
	beam_->Update();
	enemy_->Update();
	CollisonPlayerEnemy();
	CollisonBeamEnemy();

	if (playerLife_ <= 0) 
	{
		scene = GAMEOVER;
	}
}

void GamePlay::Draw2DFar() 
{
	stage_->Draw2DFar(); 

}

void GamePlay::Draw3D() 
{
	stage_->Draw3D();
	player_->Draw3D();
	beam_->Draw3D();
	enemy_->Draw3D();
}

void GamePlay::Draw2DNear() 
{
	char str[100];
	sprintf_s(str, "SCORE %d", gameScore_);

	debugTex_->Print(str, 500, 10, 2);
	debugTex_->DrawAll();
	
	
	sprintf_s(str, "LIFE %d", playerLife_);
	debugTex_->Print(str, 900, 10, 2);
	debugTex_->DrawAll();

	
}

void GamePlay::CollisonPlayerEnemy() 
{
	if (enemy_->GetFlag() == 1) {
		float dx = abs(player_->GetX() - enemy_->GetX());
		float dz = abs(player_->GetZ() - enemy_->GetZ());

		if (dx < 1 && dz < 1) {
			enemy_->Hit();
			playerLife_--;
		}
	}
}

void GamePlay::CollisonBeamEnemy() 
{
	if (enemy_->GetFlag() == 1) {
		float dx = abs(beam_->GetX() - enemy_->GetX());
		float dz = abs(beam_->GetZ() - enemy_->GetZ());

		if (dx < 1 && dz < 1) {
			enemy_->Hit();
			beam_->Hit();
			gameScore_ += 100;
		}
	}
}
