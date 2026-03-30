#pragma once
#include "DxLib.h"
#include "GameObject.h"


class GameClear : public GameObject
{
public:
    GameClear();
    ~GameClear() override;

    void Update() override;
    void Draw() override;

    bool IsEnd() const { return isEnd_; }

private:
    bool isEnd_;
    int font2_;

};


