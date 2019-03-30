#pragma once

#include <math.h>
#include <vector>
#include <iostream>
#include <graphics.h>
#include <ctime>

#include "Vect2.h"
#include "Vect3.h"
#include "Matrix2.h"
#include "Matrix2.h"
#include "Random.h"

#define	PI 3.1415926535897932384626433f



class Game
{
public:
	Game(int posx, int posy, int width, int height);
	~Game();
	void oc_GameInit();			//��Ϸ��ʼ��
	void oc_GameLoop();			//��Ϸ��ѭ��

	void oc_Update(float dt);	//����
	void oc_Draw();				//��Ⱦ
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
	clock_t oc_timer;	//��ʱ��
	float dt;			//ÿ֡��ʱ��
	int oc_cxGame;		//��Ϸ���ڿ�
	int oc_cyGame;		//��Ϸ���ڸ�
	int oc_posxGmae;	//��Ϸ����λ��x
	int oc_posyGame;	//��Ϸ����λ��y
	bool oc_bPause;		//ָʾ��Ϸ�Ƿ���ͣ
};


class GameEngine
{
	//�Ժ��ٿ�
};