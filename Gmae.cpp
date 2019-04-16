#include "Game.h"
#include"graphics.h"
#pragma comment(lib,"Winmm.lib")

Game::Game(int posx, int posy, int width, int height) :main_cam(width, height), gravity(0, -10)
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
//游戏资源加载
void Game::oc_GameLoad()
{
	//资源加载
	wchar_t sourse_file_name[50];
	for (int i = 0; i < 2; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_%d.png", i);
		loadimage(&img_t, sourse_file_name, 59, 95, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_0_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 59, 95, false);
		player.load_frame(People::sou_stand_R, img_t, img_mask);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d.png", i);
		loadimage(&img_t, sourse_file_name, 59, 95, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 59, 95, false);
		player.load_frame(People::sou_stand_L, img_t, img_mask);
	}

	for (int i = 0; i < 6; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d.png", i);
		loadimage(&img_t, sourse_file_name, 59, 95, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 59, 95, false);
		player.load_frame(People::sou_run_R, img_t, img_mask);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d.png", i);
		loadimage(&img_t, sourse_file_name, 59, 95, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 59, 95, false);
		player.load_frame(People::sou_run_L, img_t, img_mask);
	}

	for (int i = 0; i < 8; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\鱼测试\\fish_%d.png", i);
		loadimage(&img_t, sourse_file_name, 60, 24, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\鱼测试\\fish_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 60, 24, false);
		afish.load_frame(Fish::sou_swim, img_t, img_mask);
	}
	


	//载入背景图片
	loadimage(&test_img, L".\\资源文件\\background.jpg");
	setbkmode(TRANSPARENT);	//设置文字输出是背景颜色为透明

	afish.position = Vect2(1000, -1500);
	afish.velocity = Vect2(-100, 0);
	player.position = Vect2(1000, -880);
	main_cam.position = player.position;
}
//游戏主循环
void Game::oc_GameLoop()
{
	//主循环
	/*mciSendString(L"open D:\\工程\\VS\\工作室游戏\\Save_Ocean\\资源文件\\background.wav alias backmusic", NULL, 0, NULL);
	mciSendString(L"play backmusic wait", NULL, 0, NULL);*/
	
	while (1)
	{
		Frame_Begin();		//开始当前帧
		

		oc_Update(dt);		//数据更新
		oc_UI_Upedate();	//UI数据更新
		BeginBatchDraw();	//开始批量绘图
		oc_Draw(main_cam);	//渲染
		oc_UI_Draw();		//UI渲染
		FlushBatchDraw();	//显示当前帧
		Lock_FPS(60);		//帧数控制

		Frame_End();		//结束当前帧
	}
	
}	 
	
//游戏数据更新
void Game::oc_Update(float dt)
{
	oc_MouseProc();
	oc_KeyPrco();
	//player.acceleration = player.acceleration + gravity;
	
	player.Update(dt);
	afish.Update(dt);

	//之后这个要写在碰撞系统里
	/*************************************************************************************************/
	if (player.position.x < 0)
	{
		player.position.x = 0;
	}
	else if (player.position.x > 1100)
	{
		player.position.x = 1100;
	}
	if (player.position.y > 0)
	{
		player.position.y = 0;
	}
	else if (player.position.y < -5000)
	{
		player.position.y = -5000;
	}


	main_cam.position = player.position;
	if (main_cam.position.x - main_cam.xClient / 2 < 0)
	{
		main_cam.position.x = main_cam.xClient / 2;
	}
	else if (main_cam.position.x + main_cam.xClient / 2 > 5000)
	{
		main_cam.position.x = 5000 - main_cam.xClient / 2;
	}

	if (main_cam.position.y - main_cam.yClient / 2 > 0)
	{
		main_cam.position.y = main_cam.yClient / 2;
	}
	else if (main_cam.position.y + main_cam.yClient / 2 < -5000)
	{
		main_cam.position.y = -5000 + main_cam.xClient / 2;
	}
	/************************************************************************************************************/
}
//游戏渲染
void Game::oc_Draw(const Camera &cam)
{
	cleardevice();				//清屏
	int bck_pos_x = 0, bck_pos_y = 0;
	bck_pos_x = bck_pos_x - cam.position.x + oc_cxGame / 2;
	bck_pos_y = -(bck_pos_y - cam.position.y) + oc_cyGame / 2;
	putimage(bck_pos_x, bck_pos_y, &test_img);
	/*测试 摄像机*/
	

	player.DrawInCamera(cam);
	afish.DrawInCamera(cam);
	Debug_text_output();		//输出调试数据
}


/*cy完成*/
int flag = 0;//是否进入图鉴
window win(700, 500);//生成图鉴窗口
void Game::oc_UI_Upedate()
{
	const int N = 3;//图鉴内图片数量
	wchar_t out_text[50];
	static int out_i=0;
	void FlushMouseMsgBuffer();//清空鼠标消息缓冲区
	static bool last = 0;
	bool now = is_key_down(VK_LBUTTON);
	if (!last&&now)//判断是鼠标左键是否按下
	{
		Vect2 mou = GetMousePos(oc_hWnd);
		if (flag == 0 && mou.x > 100 && mou.x < 155 && mou.y>30 && mou.y < 120)//鼠标左键点击在按钮范围内
		{
			flag = 1;//进入图鉴
			loadimage(&win.img_i, L".\\资源文件\\图鉴\\0.png", win.new_x, win.new_y, false);
		}
		else if (flag==1&&mou.x > 970 && mou.x < 1000 && mou.y>100 && mou.y < 130)//退出
		{
			out_i = 0;
			flag = 0;
			loadimage(&oc_window, L".\\资源文件\\测试图片.png", 500, 500, false);
		}
		else if (flag==1&&mou.x > 940 && mou.x < 990 && mou.y>360 && mou.y < 390 && out_i < N)//下页
		{
			out_i++;
			if (out_i <= 0)
				out_i = 1;
			swprintf(out_text, 50, L".\\资源文件\\图鉴\\%d.png", out_i);
			loadimage(&win.img_i, out_text, win.new_x, win.new_y, false);
		}
		else if (flag==1&&mou.x > 310 && mou.x < 360 && mou.y>360 && mou.y < 390 && out_i >= 0)//上页
		{
			out_i--;
			if (out_i >= N)
				out_i = N - 1;
			swprintf(out_text, 50, L".\\资源文件\\图鉴\\%d.png", out_i);
			loadimage(&win.img_i, out_text, win.new_x, win.new_y, false);
		}
	}
	last = now;
}

void Game::oc_UI_Draw()
{
	IMAGE img_0,img_1, img_2, img_3;
	if (flag == 0)
	{
		//bar(100,30,155,120);
		loadimage(&img_0, L".\\资源文件\\按钮\\图鉴.png", 55, 90, false);
		putimage(100, 30, &img_0);
	}
	else
	{
		win.show();
		//bar(970,100,1000,130);//退出
		loadimage(&img_1, L".\\资源文件\\按钮\\退出.png", 30, 30, false);
		putimage(970, 100, &img_1);
		//bar(940, 360, 990, 390);//下页
		loadimage(&img_2, L".\\资源文件\\按钮\\下页.png", 50, 30, false);
		putimage(940, 360, &img_2);
		//bar(310, 360, 360, 390);//上页
		loadimage(&img_3, L".\\资源文件\\按钮\\上页.png", 50, 30, false);
		putimage(310, 360, &img_3);
	}   
}
/*end*/


void Game::oc_KeyPrco()
{
	if (is_key_down('A'))
	{
		player.set_state(People::sta_runL);
		player.velocity.x = -200;
	}
	else if (is_key_down('D'))
	{
		player.set_state(People::sta_runR);
		player.velocity.x = 200;
	}
	else
	{
		player.set_state(People::sta_stand);
		player.velocity.x = 0;
	}
}

void Game::oc_MouseProc()
{
	static Vect2 last_mouse_pos;
	Vect2 mouse_pos = GetMousePos(oc_hWnd);
	
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