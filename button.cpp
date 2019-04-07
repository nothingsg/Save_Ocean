#include"button.h"


Button::Button(int x1, int y1, int x2, int y2, int height)
{
	lt_x = x1;
	lt_y = y2;
	rb_x = x2;
	rb_y = y2;
	deep = height;
}


void Button::draw(int lt_x, int lt_y, int rb_x, int rb_y, int deep)
{
	bar3d(lt_x,lt_y,rb_x,rb_y,deep,true);
}


void Button::drawchange()
{
	
}


bool Button::leftmouse(bool last,bool now, HWND oc_hWnd)
{
	bool f=0;//f=true表示鼠标左键点击并在按钮范围内后
	if (!last&&now)//判断是鼠标左键是否按下
		f = 1;
	if (!last&&now)//判断是鼠标左键是否按下
	{
		Vect2 moup = GetMousePos(oc_hWnd);
		if (moup.x > lt_x && moup.x < rb_x && moup.y>lt_y && moup.y < rb_y)//鼠标左键点击在按钮范围内
			f = 1;
	}
	return f;
}


void Button::mousepos(HWND oc_hWnd)//鼠标是否点击，是否切换画面
{
	bool y=0;//用于判断是否转换画面
	void FlushMouseMsgBuffer();//清空鼠标消息缓冲区
	static bool last = 0;
	bool now = is_key_down(VK_LBUTTON);
	y = leftmouse(last, now,oc_hWnd);
	if (y)
	{
		drawchange();
	}
}