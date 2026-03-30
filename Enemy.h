#pragma once
#include "DxLib.h"
#include "GameObject.h"


class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy() override;
	void Update() override;
	void Draw() override;

	void SetViewX(int vx) { viewX_ = vx; }

	void EnemyY(int y) { y_ = y; }

	int GetX() const { return x_; } //“–‚½‚è”»’è—p
	int GetY() const { return y_; }

	void SetX(int x) { x_ = x; }

	int GetWidth() const;
	int GetHeight() const;
	bool IsActive() const { return isActive_; }

	

private:
	
	int x_;
	int y_;
	int speed_;
	int viewX_;

	int grizzlyEnemy_; //ƒNƒ}
	
	

	int timer_; //‘Ò‚¿ŽžŠÔ
	bool isActive_;

	

};

