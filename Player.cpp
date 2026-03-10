#include "Player.h"

Player::Player():x_(100), y_(440), speed_(5), setViewX_(0), jump_(0), gravity_(1), groundY_(440), ground_(true)
{
}

Player::~Player()
{
}

void Player::Update()
{
	//横移動
	if (CheckHitKey(KEY_INPUT_RIGHT)) 
	{
		x_ += speed_;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		x_ -= speed_;
	}

	//ジャンプ
	if (CheckHitKey(KEY_INPUT_SPACE) && ground_)
	{
		jump_ = -30;
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
	DrawBox(x_ - setViewX_, y_, x_ - setViewX_ + 32, y_ + 32, GetColor(255, 255, 255), TRUE);
}
