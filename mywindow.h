#pragma once
#include"button.h"


class window
{
public:
	int new_x;//�´��ڳ���
	int new_y;//�´��ڿ��
	IMAGE img_i;//����
	window(int x, int y);
	void outbutton();//�˳�
	void upbutton();
	void downbutton();
	void show();//��ʾ����
	HWND w_hWnd;//���ھ��
	void hide();//�رմ���

};
