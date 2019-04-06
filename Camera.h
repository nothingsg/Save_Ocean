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

};