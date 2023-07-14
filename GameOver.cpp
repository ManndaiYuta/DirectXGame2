#include "GameOver.h"

GameOver::GameOver() {}

GameOver::~GameOver() 
{
	delete spriteGameOver_;

}

void GameOver::Initialize() 
{
	textureHandleGameOver_ = TextureManager::Load("gameover.png");
	spriteGameOver_ = Sprite::Create(textureHandleGameOver_, {0,0});

	textureHandleEnter_ = TextureManager::Load("enter.png");
	spriteEnter_ = Sprite::Create(textureHandleEnter_, {400, 400});

	input_ = Input::GetInstance();
}

void GameOver::Update(Change& scene)
{
	timer_++;
	if (input_->TriggerKey(DIK_RETURN))
	{
		scene = TITLE;
	}
	else
	{
		scene = GAMEOVER;
	}
}

void GameOver::Draw2DFar() {}

void GameOver::Draw2DNear() {

	spriteGameOver_->Draw();
	if (timer_ % 40 >= 20)
	{
		spriteEnter_->Draw();
	}

}
