#include "TitleScene.h"


TitleScene::TitleScene() : start_(false)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		start_ = true;
	}
}

void TitleScene::Draw()
{
	DrawString(320, 220, "TITLE", GetColor(255, 255, 255));
	DrawString(260, 300, "Push SPACE KEY", GetColor(255, 255, 255));
}
