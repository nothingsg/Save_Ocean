#pragma once
#include "tool.h"

class Camera
{
public:
	Vect2 position;
	int xClient;
	int yClient;
	float scale;
	Camera(int xC, int yC, float s_scale = 1);
	~Camera();

	void set_scale(float new_scale);

	//返回摄像机边界坐标
	int Left();
	int Right();
	int Top();
	int Buttom();

};