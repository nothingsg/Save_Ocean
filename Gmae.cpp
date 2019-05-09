#include "Game.h"
#include"graphics.h"
#include <mmsystem.h>
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
	initgraph(oc_cxGame, oc_cyGame, SHOWCONSOLE);		//初始化窗口
	Random::randInit();									//初始化随机数
	oc_hWnd = GetHWnd();								//初始化窗口位置
	SetWindowPos(oc_hWnd, HWND_TOP, oc_posxGmae, oc_posyGame, oc_cxGame, oc_cyGame, SWP_SHOWWINDOW);
	
	oc_GameLoad();		//载入资源
	
	//初始化数据
	oc_FPS = 0;
	oc_timer = 0;
	dt = 0;
	oc_bPause = false;

	/*afish.position = Vect2(2000, -1200);
	afish.velocity = Vect2(-100, 0);*/
	//player.position = Vect2(1000, -880);
	player.position = Vect2(ISLAND_SIDE * 0.8f, 0);
	player.set_state(People::sta_jumpR);
	wood_boat.position = Vect2(BOAT_POS_L, SEA_LEVEL);
	main_cam.position = Vect2(ISLAND_SIDE * 0.8f, ISLAND_HEIGHT);
	player.acceleration = gravity;
}
//游戏资源加载
void Game::oc_GameLoad()
{
	wchar_t sourse_file_name[50];
	//资源路径加载
	/*soure_list[oc_bkg][game_background].push_back((wchar_t*)L".\\资源文件\\background\\background.jpg");

	for (int i = 0; i < 2; i++)
	{
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_%d.png", i);
		soure_list[oc_player][People::sou_stand_R].push_back(sourse_file_name);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_0_mask.png", i);
		soure_list[oc_player][People::sou_stand_L_mask].push_back(sourse_file_name);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d.png", i);
		soure_list[oc_player][People::sou_stand_R].push_back(sourse_file_name);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d_mask.png", i);
		soure_list[oc_player][People::sou_stand_L_mask].push_back(sourse_file_name);
	}

	for (int i = 0; i < 6; i++)
	{
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d.png", i);
		soure_list[oc_player][People::sou_run_R].push_back(sourse_file_name);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d_mask.png", i);
		soure_list[oc_player][People::sou_run_R_mask].push_back(sourse_file_name);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d.png", i);
		soure_list[oc_player][People::sou_run_L].push_back(sourse_file_name);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d_mask.png", i);
		soure_list[oc_player][People::sou_run_L_mask].push_back(sourse_file_name);
	}



	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向右_%d.png", 0);
	soure_list[oc_player][People::sou_jump_R].push_back(sourse_file_name);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向右_%d_mask.png", 0);
	soure_list[oc_player][People::sou_jump_R_mask].push_back(sourse_file_name);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向左_%d.png", 0);
	soure_list[oc_player][People::sou_jump_L].push_back(sourse_file_name);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向左_%d_mask.png", 0);
	soure_list[oc_player][People::sou_jump_L_mask].push_back(sourse_file_name);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向右_%d.png", 1);
	soure_list[oc_player][People::sou_catch_R].push_back(sourse_file_name);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向右_%d_mask.png", 1);
	soure_list[oc_player][People::sou_catch_R_mask].push_back(sourse_file_name);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向左_%d.png", 1);
	soure_list[oc_player][People::sou_catch_L].push_back(sourse_file_name);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向左_%d_mask.png", 1);
	soure_list[oc_player][People::sou_catch_L_mask].push_back(sourse_file_name);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\整只手_%d.png", 0);
	soure_list[oc_player][People::sou_hand_L].push_back(sourse_file_name);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\整只手_%d_mask.png", 0);
	soure_list[oc_player][People::sou_hand_L_mask].push_back(sourse_file_name);

	for (int i = 0; i < 8; i++)
	{
		swprintf(sourse_file_name, 50, L".\\资源文件\\鱼测试\\fish_%d.png", i);
		soure_list[oc_fish][Fish::sou_swim].push_back(sourse_file_name);
		swprintf(sourse_file_name, 50, L".\\资源文件\\鱼测试\\fish_%d_mask.png", i);
		soure_list[oc_fish][Fish::sou_swim_mask].push_back(sourse_file_name);
	}

	for (int i = 0; i < 2; i++)
	{
		swprintf(sourse_file_name, 50, L".\\资源文件\\boat\\两头船_%d.png", i);
		soure_list[oc_boat][Boat::sou_boat_R].push_back(sourse_file_name);
		swprintf(sourse_file_name, 50, L".\\资源文件\\boat\\两头船_%d_mask.png", i);
		soure_list[oc_boat][Boat::sou_boat_R_mask].push_back(sourse_file_name);
	}*/



	/**********************************************************************************/

	//资源加载
	
	//人物资源加载
	for (int i = 0; i < 2; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_%d.png", i);
		loadimage(&img_t, sourse_file_name, 54, 85, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向右_0_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 54, 85, false);
		player.load_frame(People::sou_stand_R, img_t, img_mask);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d.png", i);
		loadimage(&img_t, sourse_file_name, 54, 85, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞静止向左_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 54, 85, false);
		player.load_frame(People::sou_stand_L, img_t, img_mask);
	}

	for (int i = 0; i < 6; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d.png", i);
		loadimage(&img_t, sourse_file_name, 54, 85, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向右_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 54, 85, false);
		player.load_frame(People::sou_run_R, img_t, img_mask);

		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d.png", i);
		loadimage(&img_t, sourse_file_name, 54, 85, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞走路向左_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 54, 85, false);
		player.load_frame(People::sou_run_L, img_t, img_mask);
	}



	IMAGE img_t, img_mask;

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向右_%d.png", 0);
	loadimage(&img_t, sourse_file_name, 54, 85, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向右_%d_mask.png", 0);
	loadimage(&img_mask, sourse_file_name, 54, 85, false);
	player.load_frame(People::sou_jump_R, img_t, img_mask);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向左_%d.png", 0);
	loadimage(&img_t, sourse_file_name, 54, 85, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞跳跃向左_%d_mask.png", 0);
	loadimage(&img_mask, sourse_file_name, 54, 85, false);
	player.load_frame(People::sou_jump_L, img_t, img_mask);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向右_%d.png", 1);
	loadimage(&img_t, sourse_file_name, 54, 85, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向右_%d_mask.png", 1);
	loadimage(&img_mask, sourse_file_name, 54, 85, false);
	player.load_frame(People::sou_catch_R, img_t, img_mask);

	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向左_%d.png", 1);
	loadimage(&img_t, sourse_file_name, 54, 85, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\路飞垂直伸手向左_%d_mask.png", 1);
	loadimage(&img_mask, sourse_file_name, 54, 85, false);
	player.load_frame(People::sou_catch_L, img_t, img_mask);



	img_t.Resize(54, 850);
	img_mask.Resize(54, 850);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\整只手_%d.png", 0);
	loadimage(&img_t, sourse_file_name, 54, 850, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\整只手_%d_mask.png", 0);
	loadimage(&img_mask, sourse_file_name, 54, 850, false);
	player.load_hand_img(img_t, img_mask);


	/*
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\手臂_%d.png", 0);
	loadimage(&img_t, sourse_file_name, 54, 850, false);
	swprintf(sourse_file_name, 50, L".\\资源文件\\player\\手臂_%d_mask.png", 0);
	loadimage(&img_mask, sourse_file_name, 54, 850, false);
	player.load_arm_img(img_t, img_mask);*/

	
	//船类资源加载
	for (int i = 0; i < 2; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\boat\\两头船_%d.png", i);
		loadimage(&img_t, sourse_file_name, 322, 58, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\boat\\两头船_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 322, 58, false);
		wood_boat.load_frame(Boat::sou_boat_R, img_t, img_mask);
	}

	//载入背景图片 9600*5400
	loadimage(&game_background, L".\\资源文件\\background.jpg", 4800 * 0.9, 2700 * 0.9, true);

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
	
	//添加新的鱼
	if (fishs.size() < MAX_FISH_NUM)
	{
		static int fish_creat_timer = 0;
		fish_creat_timer += dt;
		int add_num = fish_creat_timer / FISH_CREAT_RACE;
		fish_creat_timer = fish_creat_timer % FISH_CREAT_RACE;

		while (add_num--)
		{
			int p_x;
			while ((p_x = Random::random_in(player.position.x - 2000, player.position.x + 2000)) > player.position.x - oc_cxGame / 2 - 100 && p_x < player.position.x + oc_cxGame / 2 + 100);
			Vect2 f_pos(p_x, Random::random_in(SEA_LEVEL*3.0f, SEA_LEVEL*1.2f));
			Fish::fish_type type = (Fish::fish_type)(int)Random::random_in(0, Fish::total_fish_type);
			int fish_farme_num, fish_width, fish_height;
			switch (type)
			{
			case Fish::one:
			{
				fish_farme_num = 8;
				fish_width = 30;
				fish_height = 12;
			}break;
			case Fish::two:
			{
				fish_farme_num = 5;
				fish_width = 45;
				fish_height = 20;
			}break;
			case Fish::three:
			{
				fish_farme_num = 5;
				fish_width = 30;
				fish_height = 15;
			}break;
			case Fish::four:
			{
				fish_farme_num = 5;
				fish_width = 30;
				fish_height = 23;
			}break;
			default:
			{
				fish_farme_num = 0;
				fish_width = 0;
				fish_height = 0;
			}break;
			}
			new_fish(type, fish_farme_num, fish_width, fish_height, f_pos);
		}
	}

	//添加新的垃圾
	if (rubbishs.size() < MAX_FISH_NUM)
	{
		static int rubbish_creat_timer = 0;
		rubbish_creat_timer += dt;
		int add_num = rubbish_creat_timer / FISH_RUBBISH_RACE;
		rubbish_creat_timer = rubbish_creat_timer % FISH_RUBBISH_RACE;

		while (add_num--)
		{
			Vect2 f_pos(Random::random_in(FECTORY_POS_X*0.9f, FECTORY_POS_X*1.1f), Random::random_in(SEA_LEVEL*3.0f, SEA_LEVEL*1.2f));
			Rubbish::rubbish_type type = (Rubbish::rubbish_type)(int)Random::random_in(0, Rubbish::total_rubbish_type);
			int rubbish_farme_num, rubbish_width, rubbish_height;
			switch (type)
			{
			case Rubbish::one:
			{
				rubbish_farme_num = 2;
				rubbish_width = 50;
				rubbish_height = 50;
			}break;
			/*case Fish::two:
			{
				rubbish_farme_num = 5;
				rubbish_width = 90;
				rubbish_height = 40;
			}break;
			case Fish::three:
			{
				rubbish_farme_num = 5;
				rubbish_width = 40;
				rubbish_height = 20;
			}break;
			case Fish::four:
			{
				rubbish_farme_num = 5;
				rubbish_width = 40;
				rubbish_height = 30;
			}break;*/
			default:
			{
				rubbish_farme_num = 0;
				rubbish_width = 0;
				rubbish_height = 0;
			}break;
			}
			new_rubbish(type, rubbish_farme_num, rubbish_width, rubbish_height, f_pos);
		}
	}
	
	//所有鱼更新
	for (int i = 0; i < fishs.size(); i++)
	{
		if (fishs[i].position.x < player.position.x - 3000 || fishs[i].position.x > player.position.x + 3000)
		{
			fishs.erase(fishs.begin() + i);
			continue;
		}
		fishs[i].Update(dt);
	}
	//所有垃圾更新
	for (int i = 0; i < rubbishs.size(); i++)
	{
		if (rubbishs[i].position.x < player.position.x - 2000)
		{
			rubbishs.erase(rubbishs.begin() + i);
			continue;
		}
		rubbishs[i].Update(dt);
	}

	player.Update(dt);
	wood_boat.Update(dt);
	

	//之后这个要写在碰撞系统里
	/*************************************************************************************************/
	switch (player.get_state())
	{
	case People::sta_boatingR:case People::sta_boatingL:
	{
		if (wood_boat.position.x < BOAT_POS_L)
		{
			wood_boat.position.x = BOAT_POS_L;
			wood_boat.velocity.x = 0;
		}
		else if (wood_boat.position.x > FECTORY_POS_X)
		{
			wood_boat.position.x = FECTORY_POS_X;
			wood_boat.velocity.x = 0;
		}
		player.velocity = Vect2(0, 0);
		player.position = wood_boat.position - Vect2(0, PLAYER_OFFSET_B);
	}break;
	case People::sta_catchR:case People::sta_catchL:
	{
		static int catched_fish = -1;
		player.velocity = Vect2(0, 0);
		player.position = wood_boat.position - Vect2(0, PLAYER_OFFSET_B);

		/*if (catched_fish == -1 && player.get_hand_vel().y < 0)
		{
			for (int i = 0; i < fishs.size(); i++)
			{
				if ((fishs[i].position - player.get_hand_pos()).vectorLengthSquared() < 600)
				{
					fishs[i].acceleration = Vect2(0, 0);
					fishs[i].velocity = Vect2(0, 0);
					player.Pull();
					catched_fish = i;
					break;
				}
			}
		}
		else if(catched_fish != -1)
		{
			fishs[catched_fish].position = player.get_hand_pos();
		}*/

		static int catched_rubbish = -1;
		if (catched_rubbish == -1 && player.get_hand_vel().y < 0)
		{
			for (int i = 0; i < rubbishs.size(); i++)
			{
				if ((rubbishs[i].position - player.get_hand_pos()).vectorLengthSquared() < HAND_COLLIDER_RANGE)
				{
					rubbishs[i].acceleration = Vect2(0, 0);
					rubbishs[i].velocity = Vect2(0, 0);
					player.Pull();
					catched_rubbish = i;
					break;
				}
			}
		}
		else if (catched_rubbish != -1)
		{
			rubbishs[catched_rubbish].position = player.get_hand_pos();
		}

		if (player.get_hand_pos().y >= player.position.y - 20)
		{
			player.set_state(People::sta_boatingR);
			if (catched_rubbish != -1)
			{
				rubbishs.erase(rubbishs.begin() + catched_rubbish);
				catched_rubbish = -1;
			}
			
		}
		
			
	}break;
	case People::sta_jumpR:case People::sta_jumpL:
	{
		if (player.position.x < 0)
		{
			player.position.x = 0;
			player.velocity.x = 0;
		}
		else if (player.position.x > ISLAND_SIDE)
		{
			player.position.x = ISLAND_SIDE;
			player.velocity.x = 0;
		}
		if (player.position.y > 0)
		{
			player.position.y = 0;
		}
		else if (player.position.y < ISLAND_HEIGHT)
		{
			player.position.y = ISLAND_HEIGHT;
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
		else if (player.position.x > ISLAND_SIDE)
		{
			player.position.x = ISLAND_SIDE;
			player.velocity = Vect2(0, 0);
		}
		if (player.position.y > 0)
		{
			player.position.y = 0;
		}
		else if (player.position.y < ISLAND_HEIGHT)
		{
			player.position.y = ISLAND_HEIGHT;
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
	else if (main_cam.position.x + main_cam.xClient / 2 > game_background.getwidth())
	{
		main_cam.position.x = game_background.getwidth() - main_cam.xClient / 2;
	}

	if (main_cam.position.y + main_cam.yClient / 2 > 0)
	{
		main_cam.position.y = -main_cam.yClient / 2;
	}
	else if (main_cam.position.y - main_cam.yClient / 2 < -game_background.getheight())
	{
		main_cam.position.y = -game_background.getheight() + main_cam.xClient / 2;
	}
	/************************************************************************************************************/

	
}
//游戏渲染
void Game::oc_Draw(const Camera &cam)
{
	cleardevice();				//清屏
	//setaspectratio(1 / cam.scale, 1 / cam.scale);//设置缩放系数

	/*int bck_pos_x = 0, bck_pos_y = 0;
	bck_pos_x = bck_pos_x - cam.position.x + oc_cxGame / 2;
	bck_pos_y = -(bck_pos_y - cam.position.y) + oc_cyGame / 2;*/
	putimage(-cam.position.x + oc_cxGame / 2, cam.position.y + oc_cyGame / 2, &game_background);

	

	for (int i = 0; i < fishs.size(); i++)
	{
		fishs[i].DrawInCamera(cam);
	}
	for (int i = 0; i < rubbishs.size(); i++)
	{
		rubbishs[i].DrawInCamera(cam);
	}
	
	wood_boat.DrawInCamera(cam);
	player.DrawInCamera(cam);
	
	
	Debug_text_output();		//输出调试数据
}

/*UI部分*/
/***********************************cy完成*********************************************/
int flag = 0;//是否进入图鉴
window win(300,100,700, 500);//生成图鉴窗口
const int N = 4;//图鉴内图片数量
int book[N+1];//标记鱼
int new_i;//新加的鱼的序号
int flaglight = 0;//表示图鉴不亮

void Game::add(int num, bool light)
{
	book[num+1] = 1;
	new_i = num+1;
	if (light)
	{
		flaglight = 1;
	}
}

void Game::oc_UI_Upedate()
{
	//book[2] = 1;
	//new_i = 2;//测试
	wchar_t out_text[50];
	static int out_i = 0;
	book[0] = 1;//封面一直存在
	void FlushMouseMsgBuffer();//清空鼠标消息缓冲区
	static bool last = 0;
	bool now = is_key_down(VK_LBUTTON);
	if (!last&&now)//判断是鼠标左键是否按下
	{
		Vect2 mou = GetMousePos(oc_hWnd);
		if (flag == 0 && mou.x > 100 && mou.x < 170 && mou.y>30 && mou.y < 90)//鼠标左键点击在按钮范围内
		{
			flag = 1;//进入图鉴
			if (flaglight)
			{
				out_i=new_i;
				swprintf(out_text, 50, L".\\资源文件\\图鉴\\%d.jpg", out_i);
				loadimage(&win.img_i, out_text, win.new_x, win.new_y, false);
			}
			else
				loadimage(&win.img_i, L".\\资源文件\\图鉴\\0.jpg", win.new_x, win.new_y, false);
		}
		else if (flag==1&&mou.x > 970 && mou.x < 1000 && mou.y>100 && mou.y < 130)//退出
		{
			out_i = 0;
			flag = 0;
			loadimage(&oc_window, L".\\资源文件\\测试图片.png", 500, 500, false);
			flaglight = 0;//图鉴变黑
		}
		else if (flag==1&&mou.x > 940 && mou.x < 990 && mou.y>360 && mou.y < 390 && out_i < N)//下页
		{
			out_i++;
			if (out_i >= N)
				out_i = N;
			if(book[out_i])
			{ 
				swprintf(out_text, 50, L".\\资源文件\\图鉴\\%d.jpg", out_i);
				loadimage(&win.img_i, out_text, win.new_x, win.new_y, false);
			}
			else
				loadimage(&win.img_i, L".\\资源文件\\图鉴\\未知.jpg", win.new_x, win.new_y, false);
		}
		else if (flag==1&&mou.x > 310 && mou.x < 360 && mou.y>360 && mou.y < 390 && out_i >= 0)//上页
		{
			out_i--;
			if (out_i <=0)
				out_i = 0;
			if (book[out_i])
			{
				swprintf(out_text, 50, L".\\资源文件\\图鉴\\%d.jpg", out_i);
				loadimage(&win.img_i, out_text, win.new_x, win.new_y, false);
			}
			else
				loadimage(&win.img_i, L".\\资源文件\\图鉴\\未知.jpg", win.new_x, win.new_y, false);
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
		if (flaglight)
		{
			if(pt.x > 100 && pt.x < 170 && pt.y>30 && pt.y < 90)
				loadimage(&img_0, L".\\资源文件\\按钮\\图鉴4.jpg", 70, 60, false);
			else
				loadimage(&img_0, L".\\资源文件\\按钮\\图鉴3.jpg", 70, 60, false);
		}
		else if (pt.x > 100 && pt.x < 170 && pt.y>30 && pt.y < 90)
		{
			loadimage(&img_0, L".\\资源文件\\按钮\\图鉴2.jpg", 70, 60, false);
		}
		else
		{
			loadimage(&img_0, L".\\资源文件\\按钮\\图鉴.jpg", 70, 60, false);
		}
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
			loadimage(&img_2, L".\\资源文件\\按钮\\下页2.jpg", 50, 30, false);
		else
			loadimage(&img_2, L".\\资源文件\\按钮\\下页.jpg", 50, 30, false);
		putimage(940, 360, &img_2);
		//bar(310, 360, 360, 390);//上页
		if (pt.x > 310 && pt.x < 360 && pt.y>360 && pt.y < 390)
			loadimage(&img_3, L".\\资源文件\\按钮\\上页2.jpg", 50, 30, false);
		else
			loadimage(&img_3, L".\\资源文件\\按钮\\上页.jpg", 50, 30, false);
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
			wood_boat.velocity.x = -BOAT_MOVE_VELOCITY;
		}break;

		case People::sta_catchR:case People::sta_catchL:
		{

		}break;

		case People::sta_jumpR:case People::sta_jumpL:
		{
			player.set_state(People::sta_jumpL);
			player.velocity.x = -PLAYER_MOVE_VELOCITY;
		}break;
		default:
		{
			player.set_state(People::sta_runL);
			player.velocity.x = -PLAYER_MOVE_VELOCITY;
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
			wood_boat.velocity.x = BOAT_MOVE_VELOCITY;
		}break;

		case People::sta_catchR:case People::sta_catchL:
		{

		}break;

		case People::sta_jumpR:case People::sta_jumpL:
		{
			player.set_state(People::sta_jumpR);
			player.velocity.x = PLAYER_MOVE_VELOCITY;
		}break;
		default:
		{
			player.set_state(People::sta_runR);
			player.velocity.x = PLAYER_MOVE_VELOCITY;
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
		player.velocity.y = PLAYER_JUMP_VELOCITY;
	}

	static int last_key_E = 0;
	if (is_key_down('E') && !last_key_E && player.get_state() != People::sta_catchR && player.get_state() != People::sta_catchL)
	{
		last_key_E = 1;
		if (player.get_state() != People::sta_boatingR && player.get_state() != People::sta_boatingL && player.position.x > ISLAND_SIDE * 0.8f)
		{
			player.set_state(People::sta_boatingR);
			player.position = wood_boat.position - Vect2(0, PLAYER_OFFSET_B);
			main_cam.position.y = SEA_LEVEL * 1.5f;
		}
		else if((player.get_state() == People::sta_boatingR || player.get_state() == People::sta_boatingL) && player.position.x < BOAT_POS_L * 1.1f)
		{
			player.set_state(People::sta_standL);
			wood_boat.velocity = Vect2(0, 0);
			player.position = Vect2(ISLAND_SIDE, SEA_LEVEL);
			main_cam.position.y = SEA_LEVEL;
		}
	}
	last_key_E = is_key_down('E');

	static int last_key_J = 0;
	if (is_key_down('J') && !last_key_J)
	{
		
		if (player.get_state() == People::sta_catchL || player.get_state() == People::sta_catchR)
		{
			wood_boat.velocity = Vect2(0, 0);
			player.Pull();
		}
		else if (player.get_state() == People::sta_boatingR || player.get_state() == People::sta_boatingL)
		{
			wood_boat.velocity = Vect2(0, 0);
			player.Catch();
		}
			
	}
	last_key_J = is_key_down('J');

}

void Game::oc_MouseProc()
{
	static Vect2 last_mouse_pos;
	Vect2 mouse_pos = GetMousePos(oc_hWnd);
	
	if (is_key_down(VK_RBUTTON))
	{
		/*Vect2 add = mouse_pos - last_mouse_pos;
		add.y = -add.y;
		main_cam.position = main_cam.position - add;*/
		/*add(0);
		add(1);
		add(2);
		add(3);*/
		/*mciSendString(_T("open .\\资源文件\\background.mp3 alias mymusic"), NULL, 0, NULL);

		// 播放音乐
		mciSendString(_T("play mymusic"), NULL, 0, NULL);
		std::cout << "开始播放" << std::endl;*/
		// 停止播放并关闭音乐
	
	}

	if (is_key_down(VK_LBUTTON))
	{
		/*Vect2 add = mouse_pos - last_mouse_pos;
		add.y = -add.y;
		main_cam.position = main_cam.position - add;*/
		/*add(0);
		add(1);
		add(2);
		add(3);*/

		// 停止播放并关闭音乐
		/*mciSendString(_T("stop mymusic"), NULL, 0, NULL);
		mciSendString(_T("close mymusic"), NULL, 0, NULL);
		std::cout << "停止播放" << std::endl;*/
	}
	//last_mouse_pos = mouse_pos;

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

void Game::new_fish(Fish::fish_type type, int farme_num, int width, int height, Vect2 pos)
{
	/*60 24*/
	Fish f;
	wchar_t sourse_file_name[50];
	char faced;
	if (pos.x < player.position.x)
	{
		faced = 'R';
		f.velocity = Vect2(Random::random_in(50, 200), 0);
	}	
	else
	{
		faced = 'L';
		f.velocity = Vect2(Random::random_in(-200, -50), 0);
	}
		
	for (int i = 0; i < farme_num; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\fish\\%d\\fish_%d_%c.png", type, i, faced);
		loadimage(&img_t, sourse_file_name, width, height, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\fish\\%d\\fish_%d_%c_mask.png", type, i, faced);
		loadimage(&img_mask, sourse_file_name, width, height, false);
		f.load_frame(Fish::sou_swim, img_t, img_mask);
	}
	f.position = pos;
	
	fishs.push_back(f);
}


void Game::new_rubbish(Rubbish::rubbish_type type, int farme_num, int width, int height, Vect2 pos)
{
	
	Rubbish r;
	wchar_t sourse_file_name[50];
	
	for (int i = 0; i < farme_num; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\rubbish\\%d\\rubbish_%d.png", type, i);
		loadimage(&img_t, sourse_file_name, width, height, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\rubbish\\%d\\rubbish_%d_mask.png", type, i);
		loadimage(&img_mask, sourse_file_name, width, height, false);
		r.load_frame(Rubbish::sou_float, img_t, img_mask);
	}
	r.position = pos;
	r.velocity = Vect2(Random::random_in(-200, -50), 0);
	rubbishs.push_back(r);
}

void Game::Debug_text_output()		//调试数据输出
{
	wchar_t output_text[300];
	swprintf(output_text, 300, L"FPS:%d Time:%f player: state:%d pos(%f,%f) vel(%f,%f) boat: pos(%f,%f) vel(%f,%f) hand: pos(%f,%f) arm_len: %f",
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
		player.get_hand_pos().y,
		player.get_hand_len());
	outtextxy(5, 5, output_text);
}