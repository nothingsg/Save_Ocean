#include <iostream>
#include <graphics.h>
#include "tool.h"
#include"Game.h"



class Button//按钮
{
	//按钮左上角的坐标,右下角坐标,高度（深度）
	int lt_x;
	int lt_y;
	int rb_x;
	int rb_y;
	int deep;
	HWND oc_hWnd;
	public:
	Button(int,int,int,int,int);//获取按钮位置和大小
	void draw(int,int,int,int,int);//画出按钮
	bool leftmouse();

};
void Button::draw(int lt_x, int lt_y, int rb_x, int rb_y, int height)
{
	bar3d(lt_x,lt_y,rb_x,rb_y,height,true);
}
Button::Button(int x1, int y1, int x2, int y2, int height)
{
	lt_x = x1;
	lt_y = y2;
	rb_x = x2;
	rb_y = y2;
	deep = height;
}
bool Button::leftmouse()
{
	bool f=0;//f=true表示鼠标左键点击并在按钮范围内后
	void FlushMouseMsgBuffer();//清空鼠标消息缓冲区
	static bool last = 0;
	bool now = is_key_down(VK_LBUTTON);
	if (!last&&now)//判断是鼠标左键是否按下
	{
		Vect2 moup = GetMousePos(oc_hWnd);
		if (moup.x > lt_x && moup.x < rb_x && moup.y>lt_y && moup.y < rb_y)//鼠标左键点击在按钮范围内
			f = 1;
	}
	return f;
}