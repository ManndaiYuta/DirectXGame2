#include "Title.h"

Title::Title() {}

Title::~Title() 
{ 
	delete spriteTitle_;


}

void Title::Initialize() 
{ 
	input_ = Input::GetInstance();
	textureHandleTitle_ = TextureManager::Load("title.png");
	spriteTitle_ = Sprite::Create(textureHandleTitle_, {0, 0});
	//
	textureHandleEnter_ = TextureManager::Load("enter.png");
	spriteEnter_ = Sprite::Create(textureHandleEnter_, {400, 400});

	;

}

void Title::Update(Change &scene)
{ 
	timer_++;
	if (input_->TriggerKey(DIK_RETURN)) 
	{
		scene = GAMEPLAY;
	}
	else
	{
		scene = TITLE;
	}
	
}


void Title::Draw2DFar(){}

void Title::Draw2DNear() 
{

	spriteTitle_->Draw();
	if (timer_ % 40 >= 20) 
	{
		spriteEnter_->Draw();
	}
	
}

