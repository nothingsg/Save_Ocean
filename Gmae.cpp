#include "Game.h"
#include"graphics.h"
#pragma comment(lib,"Winmm.lib")

Game::Game(int posx, int posy, int width, int height) :main_cam(width, height, 2.0f) , gravity(0, -980)
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

	//初始化信息
	afish.position = Vect2(1000, -1500);
	afish.velocity = Vect2(-100, 0);
	//player.position = Vect2(1000, -880);
	player.position = Vect2(800, -500);
	player.set_state(People::sta_jumpR);
	wood_boat.position = Vect2(1250, -980);
	main_cam.position = Vect2(800, -940);


	player.acceleration = gravity;
}
//游戏资源加载
void Game::oc_GameLoad()
{
	//资源加载
	wchar_t sourse_file_name[50];
	//人物资源加载
	for (int i = 0; i < 2; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_%d.png", i);
		loadimage(&img_t, sourse_file_name, 60, 94, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_0_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 60, 94, false);
		player.load_frame(People::sou_stand_R, img_t, img_mask);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d.png", i);
		loadimage(&img_t, sourse_file_name, 60, 94, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 60, 94, false);
		player.load_frame(People::sou_stand_L, img_t, img_mask);
	}

	for (int i = 0; i < 6; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d.png", i);
		loadimage(&img_t, sourse_file_name, 60, 94, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 60, 94, false);
		player.load_frame(People::sou_run_R, img_t, img_mask);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d.png", i);
		loadimage(&img_t, sourse_file_name, 60, 94, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 60, 94, false);
		player.load_frame(People::sou_run_L, img_t, img_mask);
	}

	IMAGE img_t, img_mask;
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向右_%d.png", 0);
	loadimage(&img_t, sourse_file_name, 60, 94, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向右_%d_mask.png", 0);
	loadimage(&img_mask, sourse_file_name, 60, 94, false);
	player.load_frame(People::sou_jump_R, img_t, img_mask);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向左_%d.png", 0);
	loadimage(&img_t, sourse_file_name, 60, 94, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向左_%d_mask.png", 0);
	loadimage(&img_mask, sourse_file_name, 60, 94, false);
	player.load_frame(People::sou_jump_L, img_t, img_mask);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向右_%d.png", 1);
	loadimage(&img_t, sourse_file_name, 60, 94, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向右_%d_mask.png", 1);
	loadimage(&img_mask, sourse_file_name, 60, 94, false);
	player.load_frame(People::sou_catch_R, img_t, img_mask);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向左_%d.png", 1);
	loadimage(&img_t, sourse_file_name, 60, 94, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向左_%d_mask.png", 1);
	loadimage(&img_mask, sourse_file_name, 60, 94, false);
	player.load_frame(People::sou_catch_L, img_t, img_mask);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\手_%d.png", 0);
	loadimage(&img_t, sourse_file_name, 60, 94, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\手_%d_mask.png", 0);
	loadimage(&img_mask, sourse_file_name, 60, 94, false);
	player.load_hand_img(img_t, img_mask);

	//鱼类资源加载
	for (int i = 0; i < 8; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\鱼测试\\fish_%d.png", i);
		loadimage(&img_t, sourse_file_name, 60, 24, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\鱼测试\\fish_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 60, 24, false);
		afish.load_frame(Fish::sou_swim, img_t, img_mask);
	}
	
	//船类资源加载
	for (int i = 0; i < 2; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\boat\\两头船_%d.png", i);
		loadimage(&img_t, sourse_file_name, 419, 75, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\boat\\两头船_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 419, 75, false);
		wood_boat.load_frame(Boat::sou_boat_R, img_t, img_mask);
	}

	//载入背景图片
	loadimage(&test_img, L".\\资源文件\\background.jpg");


	setbkmode(TRANSPARENT);			//设置文字输出是背景颜色为透明
	settextcolor(RGB(255, 0, 0));	//设置文字输出颜色为红色

	
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
	

	player.Update(dt);
	afish.Update(dt);
	wood_boat.Update(dt);

	//之后这个要写在碰撞系统里
	/*************************************************************************************************/
	switch (player.get_state())
	{
	case People::sta_boatingR:case People::sta_boatingL:
	{
		if (wood_boat.position.x < 1250)
		{
			wood_boat.position.x = 1250;
			wood_boat.velocity.x = 0;
		}
		else if (wood_boat.position.x > 8400)
		{
			wood_boat.position.x = 8400;
			wood_boat.velocity.x = 0;
		}
		player.velocity = Vect2(0, 0);
		player.position = wood_boat.position - Vect2(0, -30);
	}break;
	case People::sta_catchR:case People::sta_catchL:
	{
		player.velocity = Vect2(0, 0);
		player.position = wood_boat.position - Vect2(0, -30);
		if (player.get_hand_pos().y >= player.position.y - 20)
		{
			player.set_state(People::sta_boatingR);
		}
	}break;
	case People::sta_jumpR:case People::sta_jumpL:
	{
		if (player.position.x < 0)
		{
			player.position.x = 0;
			player.velocity.x = 0;
		}
		else if (player.position.x > 1100)
		{
			player.position.x = 1100;
			player.velocity.x = 0;
		}
		if (player.position.y > 0)
		{
			player.position.y = 0;
		}
		else if (player.position.y < -900)
		{
			player.position.y = -900;
			player.velocity.y = 0;
			player.set_state(People::sta_stand);
		}
	}
	default:
	{
		if (player.position.x < 0)
		{
			player.position.x = 0;
			player.velocity.x = 0;
		}
		else if (player.position.x > 1100)
		{
			player.position.x = 1100;
			player.velocity = Vect2(0, 0);
		}
		if (player.position.y > 0)
		{
			player.position.y = 0;
		}
		else if (player.position.y < -900)
		{
			player.position.y = -900;
			player.velocity.y = 0;
		}
	}
		break;
	}
	

	main_cam.position.x = player.position.x;
	if (main_cam.position.x - main_cam.xClient / 2 < 0)
	{
		main_cam.position.x = main_cam.xClient / 2;
	}
	else if (main_cam.position.x + main_cam.xClient / 2 > 9600)
	{
		main_cam.position.x = 9600 - main_cam.xClient / 2;
	}

	if (main_cam.position.y - main_cam.yClient / 2 > 0)
	{
		main_cam.position.y = main_cam.yClient / 2;
	}
	else if (main_cam.position.y + main_cam.yClient / 2 < -5400)
	{
		main_cam.position.y = -5400 + main_cam.xClient / 2;
	}
	/************************************************************************************************************/

	
}
//游戏渲染
void Game::oc_Draw(const Camera &cam)
{
	cleardevice();				//清屏
	//setaspectratio(1 / cam.scale, 1 / cam.scale);//设置缩放系数

	int bck_pos_x = 0, bck_pos_y = 0;
	bck_pos_x = bck_pos_x - cam.position.x + oc_cxGame / 2;
	bck_pos_y = -(bck_pos_y - cam.position.y) + oc_cyGame / 2;
	putimage(bck_pos_x, bck_pos_y, &test_img);
	/*测试 摄像机*/
	

	
	wood_boat.DrawInCamera(cam);
	player.DrawInCamera(cam);
	afish.DrawInCamera(cam);
	
	Debug_text_output();		//输出调试数据
}

/*UI部分*/
/***********************************cy完成*********************************************/
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
	POINT pt;
	GetCursorPos(&pt);
	if (flag == 0)
	{
		ScreenToClient(oc_hWnd, &pt);
		//printf("%5i %5i\n", pt.x, pt.y);
		//bar(100,30,155,120);
		if(pt.x > 100 && pt.x < 155 && pt.y>30 && pt.y < 120)
			loadimage(&img_0, L".\\资源文件\\按钮\\图鉴2.png", 55, 90, false);
		else
			loadimage(&img_0, L".\\资源文件\\按钮\\图鉴.png", 55, 90, false);
		putimage(100, 30, &img_0);
	}
	else
	{
		win.show();
		win.w_hWnd = GetHWnd();
		ScreenToClient(win.w_hWnd, &pt);
		//bar(970,100,1000,130);//退出
		if (pt.x > 970 && pt.x < 1000 && pt.y>100 && pt.y < 130)
			loadimage(&img_1, L".\\资源文件\\按钮\\退出2.png", 30, 30, false);
		else
			loadimage(&img_1, L".\\资源文件\\按钮\\退出.png", 30, 30, false);
		putimage(970, 100, &img_1);
		//bar(940, 360, 990, 390);//下页
		if (pt.x > 940 && pt.x < 990 && pt.y>360 && pt.y < 390)
			loadimage(&img_2, L".\\资源文件\\按钮\\下页2.png", 50, 30, false);
		else
			loadimage(&img_2, L".\\资源文件\\按钮\\下页.png", 50, 30, false);
		putimage(940, 360, &img_2);
		//bar(310, 360, 360, 390);//上页
		if (pt.x > 310 && pt.x < 360 && pt.y>360 && pt.y < 390)
			loadimage(&img_3, L".\\资源文件\\按钮\\上页2.png", 50, 30, false);
		else
			loadimage(&img_3, L".\\资源文件\\按钮\\上页.png", 50, 30, false);
		putimage(310, 360, &img_3);
	}   
}
/*************************************end*******************************************/


void Game::oc_KeyPrco()
{
	if (is_key_down('A'))
	{

		switch (player.get_state())
		{

		case People::sta_boatingR:case People::sta_boatingL:
		{
			player.set_state(People::sta_boatingL);
			wood_boat.velocity.x = -300;
		}break;

		case People::sta_catchR:case People::sta_catchL:
		{

		}break;

		case People::sta_jumpR:case People::sta_jumpL:
		{
			player.set_state(People::sta_jumpL);
			player.velocity.x = -200;
		}break;
		default:
		{
			player.set_state(People::sta_runL);
			player.velocity.x = -200;
		}
		break;
		}

		
	}
	else if (is_key_down('D'))
	{

		switch (player.get_state())
		{

		case People::sta_boatingR:case People::sta_boatingL:
		{
			player.set_state(People::sta_boatingR);
			wood_boat.velocity.x = 300;
		}break;

		case People::sta_catchR:case People::sta_catchL:
		{

		}break;

		case People::sta_jumpR:case People::sta_jumpL:
		{
			player.set_state(People::sta_jumpR);
			player.velocity.x = 200;
		}break;
		default:
		{
			player.set_state(People::sta_runR);
			player.velocity.x = 200;
		}
		break;
		}
		
	}
	else
	{
		wood_boat.velocity.x = 0;
		player.velocity.x = 0;
		if (player.get_state() == People::sta_runL || player.get_state() == People::sta_runR)
		{
			player.set_state(People::sta_stand);
		}
		
	}

	if (is_key_down('W') && player.get_state() != People::sta_jumpL && player.get_state() != People::sta_jumpR)
	{
		player.set_state(People::sta_jump);
		player.velocity.y = 400;
	}

	static int last_key_E = 0;
	if (is_key_down('E') && !last_key_E && player.get_state() != People::sta_catchR && player.get_state() != People::sta_catchL)
	{
		last_key_E = 1;
		if (player.get_state() != People::sta_boatingR && player.get_state() != People::sta_boatingL && player.position.x > 1050)
		{
			player.set_state(People::sta_boatingR);
			player.position = wood_boat.position - Vect2(0, -30);
			main_cam.position.y = -1200;
		}
		else if((player.get_state() == People::sta_boatingR || player.get_state() == People::sta_boatingL) && player.position.x < 1300)
		{
			player.set_state(People::sta_standL);
			wood_boat.velocity = Vect2(0, 0);
			player.position = Vect2(1100, -940);
			main_cam.position.y = -940;
		}
	}
	last_key_E = is_key_down('E');

	static int last_key_S = 0;
	if (is_key_down('S') && !last_key_S && (player.get_state() == People::sta_boatingR || player.get_state() == People::sta_boatingL))
	{
		wood_boat.velocity = Vect2(0, 0);
		player.Catch();
	}
	last_key_S = is_key_down('S');

}

void Game::oc_MouseProc()
{
	static Vect2 last_mouse_pos;
	Vect2 mouse_pos = GetMousePos(oc_hWnd);
	
	/*if (is_key_down(VK_LBUTTON))
	{
		Vect2 add = mouse_pos - last_mouse_pos;
		add.y = -add.y;
		main_cam.position = main_cam.position - add;
	}
	last_mouse_pos = mouse_pos;*/

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
	wchar_t output_text[200];
	swprintf(output_text, 200, L"FPS:%d Time:%f player: state:%d pos(%f,%f) vel(%f,%f) boat: pos(%f,%f) vel(%f,%f) hand: pos(%f,%f)",
		oc_FPS,
		oc_timer/1000.0f,
		player.get_state(),
		player.position.x,
		player.position.y,
		player.velocity.x,
		player.velocity.y,
		wood_boat.position.x,
		wood_boat.position.y,
		wood_boat.velocity.x,
		wood_boat.velocity.y,
		player.get_hand_pos().x,
		player.get_hand_pos().y);
	outtextxy(5, 5, output_text);
}