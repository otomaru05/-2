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

	int GetWidth() const { return 52; } //当たり判定用
	int GetHeight() const { return 52; }

	int GetJump() const { return jump_; } //ジャンプ

private:
	int x_;
	int y_;
	int setViewX_;
	int speed_;

	int jump_; //縦速度
	int gravity_; //重力
	int groundY_; //地面
	bool ground_; //接地判定
	
	int graphHandle_; //画像
	bool isRight_; //向き

	bool isHit_;
	int hitVx_; //横の吹っ飛び
	int hitVy_; //縦の吹っ飛び

};

