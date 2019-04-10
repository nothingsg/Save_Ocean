#pragma once

#include <math.h>
#include <vector>
#include <iostream>
#include <graphics.h>
#pragma once
#include "tool.h"
#include "GameObject.h"
#include "Camera.h"
#include "people.h"
#include "fish.h"
#include "terrain.h"
#include"button.h"
#include"mywindow.h"



class Game
{
public:
	Game(int posx, int posy, int width, int height);
	~Game();
	
	void oc_GameInit();			//��Ϸ��ʼ��
	void oc_GameLoad();			//��Ϸ����
	void oc_GameLoop();			//��Ϸ��ѭ��

	void oc_Update(float dt);	//����
	void oc_Draw(const Camera &cam);	//��Ⱦ
	void oc_UI_Upedate();		//UI������·���
	void oc_UI_Draw();			//UI������Ⱦ����
	void oc_KeyPrco();			//������Ϣ������
	void oc_MouseProc();		//�����Ϣ������

	void Frame_Begin();			//��ʼһ֡
	void Frame_End();			//����һ֡
	void Lock_FPS(int fps);		//����֡��,0��ʾ������


	//�������
	void Debug_text_output();
	
private:
	HWND oc_hWnd;		//��Ϸ���ھ��
	int oc_FPS;			//֡��
	float dt;			//ÿ֡��ʱ��
	int oc_cxGame;		//��Ϸ���ڿ�
	int oc_cyGame;		//��Ϸ���ڸ�
	int oc_posxGmae;	//��Ϸ����λ��x
	int oc_posyGame;	//��Ϸ����λ��y
	bool oc_bPause;		//ָʾ��Ϸ�Ƿ���ͣ

	/*��Ϸ��������*/
	clock_t oc_timer;	//��ʱ��
	Vect2 gravity;

	/*������Ϸ����*/
	IMAGE test_img;		//����ͼƬ
	IMAGE oc_window;
	People player;
	Fish afish;
	Camera main_cam;
	
};


class GameEngine
{
	//�Ժ��ٿ�
};



