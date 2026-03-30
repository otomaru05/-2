#include "DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "GameOverScene.h"
#include "GameClear.h"
#include "RuleScene.h"
#include "Input 1.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    const int SCREEN_W = 970;
    const int SCREEN_H = 640;

    ChangeWindowMode(TRUE); //ウィンドウモード
    SetGraphMode(SCREEN_W, SCREEN_H, 32);

    if (DxLib_Init() == -1)
    {
        return -1;
    }
    SetDrawScreen(DX_SCREEN_BACK);

    GameObject* scene = new TitleScene();
   

    while (ProcessMessage() == 0)
    {
        Input::KeyStateUpdate();

        ClearDrawScreen();

        scene->Update();
        scene->Draw();

        //タイトル->ルール
        if (auto* title = dynamic_cast<TitleScene*>(scene))
        {
            if (title->IsStart())
            {
                delete scene;
                scene = new RuleScene();
            }
        }
        else if (auto* rule = dynamic_cast<RuleScene*>(scene))
        {
            if (rule->IsRule())
            {
                delete scene;
                scene = new PlayScene(1280);
            }
        }
        else if (auto* play = dynamic_cast<PlayScene*>(scene)) //プレイ->ゲームオーバー
        {
            if (play->IsGameOver())
            {
                delete scene;
                scene = new GameOverScene();
            }
            else if (play->IsClear())
            {
                delete scene;
                scene = new GameClear();
            }
        }
        else if (auto over = dynamic_cast<GameOverScene*>(scene)) //ゲームオーバー->タイトル
        {
            if (over->IsRetry())
            {
                delete scene;
                scene = new TitleScene();
            }
        }
        else if (auto clear = dynamic_cast<GameClear*>(scene)) //クリア
        {
            if (clear->IsEnd())
            {
                delete scene;
                scene = new GameClear();
            }
        }
        ScreenFlip();
    }
    delete scene;
    DxLib_End();
    return 0;
}
