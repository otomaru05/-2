#include "PlayScene.h"

bool CheckCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return (x1 < x2 + w2 && x2 < x1 + w1 && y1 < y2 + h2 && y2 < y1 + h1);
}



PlayScene::PlayScene(int screenW) : player_(), camera_(screenW)
{
	bgHandle_ = LoadGraph("image\\back.png"); //‰æ‘œ
	ground_ = LoadGraph("image\\ground.png");

	isKill_ = 0;
	isGameOver_ = false;
	isClear_ = false;
	endFlag_ = false;
}


PlayScene::~PlayScene()
{
	DeleteGraph(bgHandle_);
	DeleteGraph(ground_);
}


void PlayScene::Update()
{
	if (isGameOver_ || isClear_)
	{
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			// ƒGƒ“ƒ^[‚Åƒ^ƒCƒgƒ‹‚Ö–ß‚é
			isGameOver_ = false;
			isClear_ = false;
			isKill_ = 0;

			
			endFlag_ = true; //I—¹‚µ‚½
		}
		return; //UpdateŽ~‚ß‚é
	}

	player_.Update(); //ƒvƒŒƒCƒ„[XV

	camera_.SetTargetX(player_.GetX()); //ƒJƒƒ‰’Ç]
	camera_.Update();

	player_.SetViewX(camera_.GetViewX()); //•`‰æŠî€‚ð“n‚·

	for(int e = 0; e < 2; e++)
	{
		enemies_[e].Update(); //“G
		enemies_[e].SetViewX(camera_.GetViewX());
		//enemy_.EnemyY(player_.GetY());


		if (!enemies_[e].IsActive()) continue;


		if (CheckCollision(player_.GetX(), player_.GetY(), 52, 52,
			enemies_[e].GetX(), enemies_[e].GetY(),
			enemies_[e].GetWidth(), enemies_[e].GetHeight()))
		{
			if (player_.GetJump() > 0 && player_.GetY() + player_.GetHeight() < enemies_[e].GetY() + 20)
			{
				enemies_[e] = Enemy();
				isKill_++;
			}
			else
			{
				isGameOver_ = true;
			}
			
		}

		if (isKill_ >= 2)
		{
			isClear_ = true;
		}
		
	}

	
	
}

void PlayScene::Draw()
{
	int viewX = camera_.GetViewX();

	int backW, backH;
	GetGraphSize(bgHandle_, &backW, &backH);

	int startScreen = 200; 
	int bgViewX = 0;
	if (viewX > startScreen)
	{
		bgViewX = (viewX - startScreen) / 2; //”wŒi‚ä‚Á‚­‚è
	}

	int bax = (-bgViewX % backW + backW) % backW; 
	for (int i = -1; i <= 2; i++)
	{
		DrawGraph(bax + i * backW, 0, bgHandle_, TRUE); //”wŒi
	}

	

	int grx = (-viewX % 64 + 64) % 64; 
	for (int j = 0; j < 20; j++)
	{
		DrawGraph(grx + j * 64, 550, ground_, TRUE); //’n–Ê
	}

	for (int e = 0; e < 2; e++)
	{
		enemies_[e].Draw();
	}

	player_.Draw();
	//enemy_.Draw();

	DrawString(10, 10, "PLAY", GetColor(255, 255, 255));
	DrawFormatString(10, 40, GetColor(255, 255, 255),"PlayerX=%d Camera=%d",player_.GetX(),viewX);

	DrawFormatString(10, 70, GetColor(255, 255, 0),
		"“G‚ð2‘Ì“|‚¹I %d / 2", isKill_);

	if (isGameOver_)
	{
		DrawString(400, 200, "GAME OVER", GetColor(255, 0, 0));
		DrawString(350, 250, "Press ENTER", GetColor(255, 255, 255));
	}

	if (isClear_)
	{
		DrawString(400, 200, "CLEAR!", GetColor(0, 255, 0));
		DrawString(350, 250, "Press ENTER", GetColor(255, 255, 255));
	}
}
