#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "GameObject.h"
#include "Enemy.h"


class PlayScene : public GameObject
{
public:
	PlayScene(int screenW);
	~PlayScene() override;
	void Update() override;
	void Draw() override;

	bool IsLoop() const { return isGameOver_ || isClear_; }
	bool endFlag_;
	bool IsFlag() const { return endFlag_; }

private:
	Player player_;
	Camera camera_;
	Enemy enemy_;
	Enemy enemies_[2];

	int bgHandle_; //îwåi
	int ground_; //ínñ 

	bool isHit_;

	int isKill_;
	bool isGameOver_;
	bool isClear_;
};

