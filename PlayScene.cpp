#include "PlayScene.h"

PlayScene::PlayScene(int screenW) : player_(), camera_(screenW)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	player_.Update(); //プレイヤー更新

	camera_.SetTargetX(player_.GetX()); //カメラ追従
	camera_.Update();

	player_.SetViewX(camera_.GetViewX()); //描画基準を渡す
}

void PlayScene::Draw()
{
	player_.Draw();
	DrawString(10, 10, "PLAY", GetColor(255, 255, 255));
	DrawFormatString(10, 40, GetColor(255, 255, 255),"PlayerX=%d Camera=%d",player_.GetX(),camera_.GetViewX());
}
