#pragma once
#include "DxLib.h"
#include "GameObject.h"


class Player : public GameObject
{
public:
	Player();
	~Player() override;
	void Update() override; //入力と移動
	void Draw() override; //描画
	int GetX() const { return x_; }
	int GetY() const { return y_; }
	void SetViewX(int vx) { setViewX_ = vx; }

private:
	int x_;
	int y_;
	int setViewX_;
	int speed_;

	int jump_; //縦速度
	int gravity_; //重力
	int groundY_; //地面
	bool ground_; //接地判定

};

