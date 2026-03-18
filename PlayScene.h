#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "GameObject.h"


class PlayScene : public GameObject
{
public:
	PlayScene(int screenW);
	~PlayScene() override;
	void Update() override;
	void Draw() override;

private:
	Player player_;
	Camera camera_;

	int bgHandle_; //îwåi
	int ground_; //ínñ 
};

