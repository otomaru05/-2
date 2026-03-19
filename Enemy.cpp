#include "Enemy.h"

Enemy::Enemy() : x_(1200), y_(440), speed_(3), viewX_(0)
{
	x_ = 1200 + rand() % 600;
	timer_ = rand() % 120; 
	//speed_ = 2 + rand() % 3;

	dup_ = 0;
	
	if (dup_ == 0)
	{
		y_ = 450;
	}
	else
	{
		y_ = 485;
	}

	isActive_ = true;
	timer_ = 0;

	grizzlyEnemy_= LoadGraph("image\\bea.png");
	dogEnemy_ = LoadGraph("image\\bog.png");

}

Enemy::~Enemy()
{
	DeleteGraph(grizzlyEnemy_);
	DeleteGraph(dogEnemy_);
}

void Enemy::Update()
{
	if (isActive_)
	{
		x_ -= speed_; //左に移動

		if (x_ < -100)
		{
			isActive_ = false;
			timer_ = 180 + rand() % 180;
		}
	}
	else
	{
		timer_--;

		if (timer_ <= 0) //画面外に行ったら右に復活
		{
			isActive_ = true;
			x_ = 1200 + rand() % 300;
			speed_ = 2 + rand() % 3; //速さ
			dup_ = rand()% 2; //ランダムに

			if (dup_ == 0)
			{
				y_ = 450;
			}
			else
			{
				y_ = 485;
			}
		}
	}
	

	
}

void Enemy::Draw()
{
	if (!isActive_) return;

	if (dup_ == 0)
	{
		int size = 105;
		int drawY = 450;

		DrawExtendGraph(x_ - viewX_, drawY, x_ - viewX_ + size, drawY + size, grizzlyEnemy_, TRUE);
	}
	else
	{
		int size = 70;
		int drawY = 485;

		DrawExtendGraph(x_ - viewX_, drawY, x_ - viewX_ + size, drawY + size, dogEnemy_, TRUE);
	}
	
}

int Enemy::GetWidth() const
{
	if (dup_ == 0)
	{
		return 105; //クマ
	}
	else
	{
		return 70; //犬
	}
}

int Enemy::GetHeight() const
{
	if (dup_ == 0)
	{
		return 105; //クマ
	}
	else
	{
		return 70; //犬
	}
}
//当たり判定の追加(プレイヤーも)
// プレイヤーの攻撃方法
// 敵に当たったらゲームオーバー
// 敵を６体やっつけたらクリア
// エフェクト追加
//ゲームオーバー画面とクリア画面の追加