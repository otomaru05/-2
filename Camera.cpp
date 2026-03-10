#include "Camera.h"

Camera::Camera(int screenW):viewX_(0), targetX_(0), screenW_(screenW)
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	viewX_ = targetX_ - screenW_ / 2;
	if (viewX_ < 0)
	{
		viewX_ = 0;
	}
}

void Camera::Draw()
{
}
