#include "RuleScene.h"
#include "Input 1.h"

RuleScene::RuleScene() : isNext_(false)
{
	rule_ = CreateFontToHandle(NULL, 40, 3);
}

RuleScene::~RuleScene()
{
	DeleteFontToHandle(rule_);
}

void RuleScene::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_RETURN))
	{
		isNext_ = true; //プレイに行く
	}
}

void RuleScene::Draw()
{
	DrawStringToHandle(200, 100, "ルール説明", GetColor(255, 255, 0), rule_);
	DrawString(200, 150, "クマがプレイヤーに向かってくる\n", GetColor(255, 255, 255));
	DrawString(200, 170, "クマに食われるまでに上から踏み潰そう！\n", GetColor(255, 255, 255));
	DrawString(200, 190, "クマは二匹出現するぞ\n", GetColor(255, 0, 0));

	DrawString(400, 320, "Enterキーでスタート", GetColor(255, 255, 255));
}
