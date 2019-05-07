#pragma once
#include <iostream>
#include <graphics.h>
#include "tool.h"
#include "control.h"


class Button:public control//按钮
{ 
	std::vector<Button> a;
public:
	int lt_x;
	int lt_y;
	int rb_x;
	int rb_y;
	int deep;
	Button(int x1, int y1, int weight, int height);//获取按钮位置和大小
	void draw();//画出按钮

	void drawchange();//切换到另一窗口/画面
};
