#include <iostream>
#include <graphics.h>
#include "tool.h"
#include"Game.h"



class Button//��ť
{
	//��ť���Ͻǵ�����,���½�����,�߶ȣ���ȣ�
	int lt_x;
	int lt_y;
	int rb_x;
	int rb_y;
	int deep;
	HWND oc_hWnd;
	public:
	Button(int,int,int,int,int);//��ȡ��ťλ�úʹ�С
	void draw(int,int,int,int,int);//������ť
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
	bool f=0;//f=true��ʾ������������ڰ�ť��Χ�ں�
	void FlushMouseMsgBuffer();//��������Ϣ������
	static bool last = 0;
	bool now = is_key_down(VK_LBUTTON);
	if (!last&&now)//�ж����������Ƿ���
	{
		Vect2 moup = GetMousePos(oc_hWnd);
		if (moup.x > lt_x && moup.x < rb_x && moup.y>lt_y && moup.y < rb_y)//����������ڰ�ť��Χ��
			f = 1;
	}
	return f;
}