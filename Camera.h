#pragma once
#include "tool.h"

class Camera
{
public:
	Vect2 position;
	int xClient;
	int yClient;
	Camera(int xC, int yC);
	~Camera();

	//返回摄像机边界坐标
	int Left();
	int Right();
	int Top();
	int Buttom();

};