#include "Game.h"

Game::Game(int posx, int posy, int width, int height)
{
	oc_cxGame = width;
	oc_cyGame = height;
	oc_posxGmae = posx;
	oc_posyGame = posy;
}

Game::~Game()
{

}

//游戏初始化
void Game::oc_GameInit()
{		
	initgraph(oc_cxGame, oc_cyGame, SHOWCONSOLE);
	oc_hWnd = GetHWnd();
	SetWindowPos(oc_hWnd, HWND_TOP, oc_posxGmae, oc_posyGame, oc_cxGame, oc_cyGame, SWP_SHOWWINDOW);
	oc_FPS = 0;
	oc_timer = 0;
	dt = 0;
	oc_bPause = false;
}		
void Game::oc_GameLoop()
{
	//主循环
	while (1)
	{
		Frame_Begin();		//开始当前帧
		

		oc_Update(dt);		//数据更新
		BeginBatchDraw();	//开始批量绘图
		oc_Draw();			//渲染
		FlushBatchDraw();	//显示当前帧
		Lock_FPS(60);		//帧数控制


		Frame_End();		//结束当前帧
	}
	
}	 
	

void Game::oc_Update(float dt)
{

}

void Game::oc_Draw()
{
	cleardevice();				//清屏
	Debug_text_output();		//输出调试数据

	circle(200, 500, 100);

}


void Game::oc_KeyPrco()
{

}

void Game::oc_MouseProc()
{

}


clock_t timer_temp;	//帧数计算临时计时器

void Game::Frame_Begin()	//开始一帧
{
	timer_temp = clock();
}

void Game::Frame_End()		//结束一帧
{
	static int fps_i = 0;	//两个静态变量用与计算帧数
	static int fps_t = 0;
	
	
	oc_timer += clock() - timer_temp;
	fps_t += clock() - timer_temp;
	fps_i++;
	
	if (fps_i == 100)		//累积10帧再进行计算，否则时间可能很短
	{
		oc_FPS = 100000.0f / fps_t;
		fps_i = 0;
		fps_t = 0;
	}
	dt = clock() - timer_temp;	//计算帧间隔时间dt
}

void Game::Lock_FPS(int fps)
{
	if (fps <= 0)return;
	int t = 1000.0f / fps - clock() + timer_temp;
	if (t < 0)return;
	Sleep(t);
}


void Game::Debug_text_output()		//调试数据输出
{
	wchar_t output_text[50];
	swprintf(output_text, 50, L"FPS:%d Time:%f", oc_FPS, oc_timer/1000.0f);
	outtextxy(5, 5, output_text);
}