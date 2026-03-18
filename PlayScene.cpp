#include "PlayScene.h"

PlayScene::PlayScene(int screenW) : player_(), camera_(screenW)
{
	bgHandle_ = LoadGraph("image\\back.png"); //‰æ‘œ
	ground_ = LoadGraph("image\\ground.png");
}

PlayScene::~PlayScene()
{
	DeleteGraph(bgHandle_);
	DeleteGraph(ground_);
}

void PlayScene::Update()
{
	player_.Update(); //ƒvƒŒƒCƒ„[XV

	camera_.SetTargetX(player_.GetX()); //ƒJƒƒ‰’Ç]
	camera_.Update();

	player_.SetViewX(camera_.GetViewX()); //•`‰æŠî€‚ğ“n‚·
}

void PlayScene::Draw()
{
	int viewX = camera_.GetViewX();

	int backW, backH;
	GetGraphSize(bgHandle_, &backW, &backH);

	int bax = (-viewX / 2 % backW, 0, bgHandle_, TRUE); //”wŒi‚ä‚Á‚­‚è
	for (int i = 0; i < 3; i++)
	{
		DrawGraph(bax + i * backW, 0, bgHandle_, TRUE); //”wŒi
	}

	

	int grx = (-viewX % 64 + 64) % 64; 
	for (int j = 0; j < 20; j++)
	{
		DrawGraph(grx + j * 64, 550, ground_, TRUE); //’n–Ê
	}

	player_.Draw();

	DrawString(10, 10, "PLAY", GetColor(255, 255, 255));
	DrawFormatString(10, 40, GetColor(255, 255, 255),"PlayerX=%d Camera=%d",player_.GetX(),viewX);
}
