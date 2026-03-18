#include "Player.h"

Player::Player():x_(100), y_(440), speed_(5), setViewX_(0), jump_(0), gravity_(1), groundY_(500), ground_(true)
{
	graphHandle_ = LoadGraph("image\\player.png"); //画像
	isRight_ = true; //初期向き
}

Player::~Player()
{
	DeleteGraph(graphHandle_);
}

void Player::Update()
{
	//横移動
	if (CheckHitKey(KEY_INPUT_RIGHT)) 
	{
		x_ += speed_;
		isRight_ = true;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		x_ -= speed_;
		isRight_ = false;
	}

	//ジャンプ
	if (CheckHitKey(KEY_INPUT_SPACE) && ground_)
	{
		jump_ = -20;
		ground_ = false;
	}

	//重力
	jump_ += gravity_;
	y_ += jump_;

	//地面衝突
	if (y_ >= groundY_)
	{
		y_ = groundY_;
		jump_ = 0;
		ground_ = true;
	}
}

void Player::Draw()
{
	float scaleX = isRight_ ? 1.0f : -1.0f; //左なら反転

	//DrawBox(x_ - setViewX_, y_, x_ - setViewX_ + 32, y_ + 32, GetColor(255, 255, 255), TRUE);
	if (isRight_)
	{
		DrawExtendGraph(x_ - setViewX_, y_, x_ - setViewX_ + 52, y_ + 52, graphHandle_, TRUE); //右
	}
	else
	{
		DrawExtendGraph(x_ - setViewX_ + 52, y_, x_ - setViewX_, y_ + 52, graphHandle_, TRUE); //左
	}
	
}
