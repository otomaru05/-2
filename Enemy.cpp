#include "Enemy.h"
#include "PlayScene.h"

Enemy::Enemy() : x_(1200), y_(440), speed_(1), viewX_(0)
{
	x_ = 1200 + rand() % 600;
	timer_ = rand() % 120; 
	//speed_ = 2 + rand() % 3;

	isActive_ = true;
	timer_ = 0;

	grizzlyEnemy_= LoadGraph("image\\bea.png");

}

Enemy::~Enemy()
{
	DeleteGraph(grizzlyEnemy_);
}

void Enemy::Update()
{
	if (isActive_)
	{
		x_ -= speed_; //¶‚ÉˆÚ“®

		if (x_ < -100)
		{
			isActive_ = false;
			timer_ = 180 + rand() % 180;
		}
	}
	else
	{
		timer_--;

		if (timer_ <= 0) //‰æ–ÊŠO‚És‚Á‚½‚ç‰E‚É•œŠˆ
		{
			isActive_ = true;
			x_ = 1200 + rand() % 300;
			speed_ = 1 + rand() % 2; //‘¬‚³
			

		}
	}
	

	
}

void Enemy::Draw()
{
	if (!isActive_) return;

	int size = 105;
	int drawY = 450;

	DrawExtendGraph(x_ - viewX_, drawY, x_ - viewX_ + size, drawY + size, grizzlyEnemy_, TRUE);
	
	
}

int Enemy::GetWidth() const
{
	return 105;
}

int Enemy::GetHeight() const
{
	return 105;
}
