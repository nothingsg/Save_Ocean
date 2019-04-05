﻿#include "Game.h"
#include"graphics.h"
#pragma comment(lib,"Winmm.lib")

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
	oc_GameLoad();
}

void Game::oc_GameLoad()
{
	loadimage(&test_img, L".\\资源文件\\测试图片.png", oc_cxGame, oc_cyGame, false);
	setbkmode(TRANSPARENT);	//设置文字输出是背景颜色为透明
}

void Game::oc_GameLoop()
{
	//主循环
	mciSendString(L"open D:\\工程\\VS\\工作室游戏\\Save_Ocean\\资源文件\\background.wav alias backmusic", NULL, 0, NULL);
	mciSendString(L"play backmusic wait", NULL, 0, NULL);
	while (1)
	{
		Frame_Begin();		//开始当前帧
		

		oc_Update(dt);		//数据更新
		oc_UI_Upedate();
		BeginBatchDraw();	//开始批量绘图
		oc_Draw(main_cam);	//渲染
		oc_UI_Draw();
		FlushBatchDraw();	//显示当前帧
		Lock_FPS(60);		//帧数控制

		Frame_End();		//结束当前帧
	}
	
}	 
	

void Game::oc_Update(float dt)
{
	oc_MouseProc();
}

void Game::oc_Draw(const Camera &cam)
{
	cleardevice();				//清屏
	int x = 0, y = 0, xm = -oc_cxGame / 2, ym = oc_cyGame / 2;
	xm = xm - cam.position.x + oc_cxGame / 2;
	ym = -(ym - cam.position.y) + oc_cyGame / 2;
	putimage(xm, ym, &test_img);
	/*测试 摄像机*/
	
	x = x - cam.position.x + oc_cxGame / 2;
	y = -(y - cam.position.y) + oc_cyGame / 2;

	circle(x, y, 100);


	Debug_text_output();		//输出调试数据
}


/*cy完成*/
int flag = 0;//是否进入图鉴
void Game::oc_UI_Upedate()
{
	void FlushMouseMsgBuffer();//清空鼠标消息缓冲区
	struct MOUSEMSG mou;
	if (MouseHit())
	{
		mou=GetMouseMsg();//获取鼠标消息
		if (flag==0&&mou.x >100&&mou.x<180&&mou.y>30&&mou.y < 60&&mou.mkLButton)//鼠标左键点击在按钮范围内
	    {
			flag = 1;//进入图鉴
			loadimage(&test_img, L".\\资源文件\\图鉴\\0封面.png", oc_cxGame, oc_cyGame, false);
	    }
		else if (flag&&mou.x > 1250 && mou.x < 1330 && mou.y>340 && mou.y < 370 && mou.mkLButton)
		{
			loadimage(&test_img, L".\\资源文件\\图鉴\\1.png", oc_cxGame, oc_cyGame, false);
		}
	}
}

void Game::oc_UI_Draw()
{
	if(flag==0)
		bar3d(100, 30, 180, 60, 3, true);
	else
	{
		bar3d(50, 340, 130, 370, 3, true);//上页
		bar3d(1250, 340, 1330,370, 3, true);//下页
	}
		
}
/*end*/


void Game::oc_KeyPrco()
{

}

void Game::oc_MouseProc()
{
	static Vect2 last_mouse_pos;
	Vect2 mouse_pos = GetMousePos();

	if (is_key_down(VK_LBUTTON))
	{
		Vect2 add = mouse_pos - last_mouse_pos;
		add.y = -add.y;
		main_cam.position = main_cam.position - add;
	}


	last_mouse_pos = mouse_pos;
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
	
	if (fps_i == 10)		//累积10帧再进行计算，否则时间可能很短
	{
		oc_FPS = 10000.0f / fps_t;
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