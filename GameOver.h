#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include"PrimitiveDrawer.h"
#include<Sprite.h>
#include "Input.h"
#include"ChangeSceen.h"
class GameOver : public ChangeSceen
{
public:
	GameOver();

	~GameOver();
	// 初期化
	void Initialize();

	// 更新
	void Update(Change& scene);

	// 2D背景描画
	void Draw2DFar();
	//
	void Draw2DNear();
	
private:
	Input* input_ = nullptr;
	uint32_t textureHandleEnter_ = 0;
	Sprite* spriteEnter_ = nullptr;    
	int timer_ = 0;

	uint32_t textureHandleGameOver_ = 0;
	Sprite* spriteGameOver_ = nullptr;
};
