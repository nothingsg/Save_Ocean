#pragma once
#include <iostream>
#include <graphics.h>
#include "tool.h"
#include "control.h"


class Button:public control//��ť
{ 
	std::vector<Button> a;
public:
	int lt_x;
	int lt_y;
	int rb_x;
	int rb_y;
	int deep;
	Button(int x1, int y1, int weight, int height);//��ȡ��ťλ�úʹ�С
	void draw();//������ť

	void drawchange();//�л�����һ����/����
};
