#pragma once
#include <iostream>
#include <graphics.h>
#include "tool.h"


class Button//��ť
{
	//��ť���Ͻǵ�����,���½�����,�߶ȣ���ȣ�
	int lt_x;
	int lt_y;
	int rb_x;
	int rb_y;
	int deep;
public:
	Button(int x1, int y1, int x2, int y2, int height);//��ȡ��ťλ�úʹ�С
	void draw(int lt_x, int lt_y, int rb_x, int rb_y, int deep);//������ť
	bool leftmouse(HWND oc_hWnd);
	void drawchange();//�л�����һ����/����
};
