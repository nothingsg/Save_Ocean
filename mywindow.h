#pragma once
#include"button.h"


class window
{
public:
	int new_x;//新窗口长度
	int new_y;//新窗口宽度
	int red_x;//窗口起始位置
	int red_y;
	IMAGE img_i;//窗口
	IMAGE img_mask;//掩码
	window(int x0,int y0,int x, int y);
	//void outbutton();//退出
	//void upbutton();
	//void downbutton();
	void show();//显示窗口
	HWND w_hWnd;//窗口句柄

};
