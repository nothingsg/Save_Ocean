#pragma once
#include"button.h"


class window
{
public:
	int new_x;//�´��ڳ���
	int new_y;//�´��ڿ��
	int red_x;//������ʼλ��
	int red_y;
	IMAGE img_i;//����
	IMAGE img_mask;//����
	window(int x0,int y0,int x, int y);
	//void outbutton();//�˳�
	//void upbutton();
	//void downbutton();
	void show();//��ʾ����
	HWND w_hWnd;//���ھ��

};
