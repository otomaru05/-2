#pragma once
#include "DxLib.h"
#include "GameObject.h"


class TitleScene : public GameObject
{
public:
	TitleScene();
	~TitleScene() override;
	void Update() override;
	void Draw() override;

	bool IsStart() const { return start_; }

private:
	bool start_;
	int title_;
	int sub_;

};

