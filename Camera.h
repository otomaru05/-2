#pragma once
#include "GameObject.h"


class Camera : public GameObject
{
public:
	Camera(int screenW);
	~Camera() override;
	void Update() override;
	void Draw() override;
	
	void SetTargetX(int x) { targetX_ = x; }
	int GetViewX() const { return viewX_; }

private:
	int viewX_;
	int targetX_;
	int screenW_;
};

