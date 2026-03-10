#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "TitleScene.h"
#include "PlayScene.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    const int SCREEN_W = 1000;
    const int SCREEN_H = 600;

    ChangeWindowMode(TRUE); //ウィンドウモード
    SetGraphMode(SCREEN_W, SCREEN_H, 32);

    if (DxLib_Init() == -1)
    {
        return -1;
    }
    SetDrawScreen(DX_SCREEN_BACK);

    GameObject* current = new TitleScene();
    //PlayScene* play = nullptr;


    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        current->Update();
        current->Draw();

        //タイトルー＞プレイ
        if (auto* title = dynamic_cast<TitleScene*>(current))
        {
            if (title->IsStart())
            {
                delete current;
                current = new PlayScene(SCREEN_W);
            }
        }
        ScreenFlip();
    }
    delete current;
    DxLib_End();
    return 0;
}
