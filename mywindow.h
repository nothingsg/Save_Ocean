#pragma once
#include"button.h"


class window
{
public:
	int new_x;//新窗口长度
	int new_y;//新窗口宽度
	IMAGE img_i;//窗口
	HWND w_hWnd;//窗口句柄
	window(int x, int y);
	void outbutton();//退出
	void upbutton();
	void downbutton();
	void show();//显示窗口
	void hide();//关闭窗口

};
