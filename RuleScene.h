#pragma once
#include "DxLib.h"
#include "GameObject.h"

class RuleScene : public GameObject
{
public:
	RuleScene();
	~RuleScene() override;

	void Update();
	void Draw();

	bool IsRule() const { return isNext_; }

private:
	bool isNext_;
	int rule_;

};

