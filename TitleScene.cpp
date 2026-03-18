#include "TitleScene.h"


TitleScene::TitleScene() : start_(false)
{
	title_ = CreateFontToHandle(NULL, 50, 3);
	sub_ = CreateFontToHandle(NULL, 20, 2);
}

TitleScene::~TitleScene()
{
	DeleteFontToHandle(title_);
	DeleteFontToHandle(sub_);
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		start_ = true;
	}
}

void TitleScene::Draw()
{
	DrawStringToHandle(250, 220, "横スクロールゲーム", GetColor(255, 255, 255), title_);
	DrawStringToHandle(260, 300, "Push ENTER KEY", GetColor(255, 255, 255), sub_);
}

