#pragma once

#include <math.h>
#include <vector>
#include <iostream>
#include <graphics.h>
#pragma once
#include "tool.h"
#include "GameObject.h"
#include "Camera.h"
#include "people.h"
#include "fish.h"
#include "boat.h"
#include "terrain.h"
#include "button.h"
#include "mywindow.h"
#include "control.h"


enum soure_tpye
{
	oc_bkg = 0,
	oc_player,
	oc_boat,
	oc_fish,
	oc_rubbish,
	oc_button
};

enum soure_bkg
{
	game_background
};


class Game
{
public:
	Game(int posx, int posy, int width, int height);
	~Game();
	
	void oc_GameInit();			//游戏初始化
	void oc_GameLoad();			//游戏加载
	void oc_GameLoop();			//游戏主循环

	void oc_Update(float dt);	//更新
	void oc_Draw(const Camera &cam);	//渲染
	void oc_UI_Upedate();		//UI界面更新方法
	void oc_UI_Draw();			//UI界面渲染方法
	void oc_KeyPrco();			//键盘消息处理函数
	void oc_MouseProc();		//鼠标消息处理函数

	void Frame_Begin();			//开始一帧
	void Frame_End();			//结束一帧
	void Lock_FPS(int fps);		//锁定帧数,0表示无限制

	//增加鱼到图鉴,num为鱼的序号(按fish文件夹中),light==true时图鉴会变亮
	void add(int num,bool light=true);

	//生成鱼
	void new_fish(
		Fish::fish_type type,
		int farme_num,
		int width,
		int height,
		Vect2 pos);

	//调试相关
	void Debug_text_output();
	
private:
	HWND oc_hWnd;		//游戏窗口句柄
	int oc_FPS;			//帧数
	float dt;			//每帧的时间
	int oc_cxGame;		//游戏窗口宽
	int oc_cyGame;		//游戏窗口高
	int oc_posxGmae;	//游戏窗口位置x
	int oc_posyGame;	//游戏窗口位置y
	bool oc_bPause;		//指示游戏是否暂停

	/*资源列表 暂时没用*/
	std::vector < std::vector<std::vector<wchar_t*>>> soure_list;


	/*游戏世界数据*/
	clock_t oc_timer;	//计时器
	Vect2 gravity;

	/*所有游戏对象*/
	//IMAGE test_img;		//测试图片
	IMAGE game_background;
	IMAGE oc_window;
	People player;
	Fish afish;
	std::vector<Fish> fishs;
	Boat wood_boat;


	Camera main_cam;	//主摄像机
	
};


class GameEngine
{
	//以后再看
};



