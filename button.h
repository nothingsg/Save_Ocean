#pragma once
#include <iostream>
#include <graphics.h>
#include "tool.h"


class Button//按钮
{
	//按钮左上角的坐标,右下角坐标,高度（深度）
	int lt_x;
	int lt_y;
	int rb_x;
	int rb_y;
	int deep;
public:
	Button(int x1, int y1, int x2, int y2, int height);//获取按钮位置和大小
	void draw(int lt_x, int lt_y, int rb_x, int rb_y, int deep);//画出按钮
	bool leftmouse(bool last, bool now,HWND oc_hWnd);//鼠标是否点击左键
	void mousepos(HWND oc_hWnd);//鼠标点击是否在按钮范围内
	void drawchange();//切换到另一窗口/画面

};
