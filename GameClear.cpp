#include "GameClear.h"
#include "Input 1.h"


GameClear::GameClear()
{
	font2_ = CreateFontToHandle(NULL, 80, 3);
}

GameClear::~GameClear()
{
	DeleteFontToHandle(font2_);
}

void GameClear::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_RETURN))
	{
		isEnd_ = true; //ƒ^ƒCƒgƒ‹‚É–ß‚é
	}
}

void GameClear::Draw()
{
	DrawStringToHandle(300, 200, "CLEAR!", GetColor(0, 255, 0), font2_);
}
