#include "GameOverScene.h"
#include "Input 1.h"


GameOverScene::GameOverScene() : isRetry_(false)
{
	font_ = CreateFontToHandle(NULL, 80, 3);

}

GameOverScene::~GameOverScene()
{
	DeleteFontToHandle(font_);
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_RETURN))
	{
		isRetry_ = true; //ƒ^ƒCƒgƒ‹‚É–ß‚é
	}
}

void GameOverScene::Draw()
{
	DrawStringToHandle(300, 200, "GAME OVER", GetColor(255, 0, 0), font_);
	DrawString(400, 320, "Push ENTER", GetColor(255, 255, 255));
}
