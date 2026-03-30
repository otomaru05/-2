#pragma once
#include "DxLib.h"
#include "GameObject.h"


class GameOverScene : public GameObject
{
public:
    GameOverScene();
    ~GameOverScene() override;

    void Update() override;
    void Draw() override;

    bool IsRetry() const { return isRetry_; }

private:
    bool isRetry_;
    int font_;

};

