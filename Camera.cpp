#include "Camera.h"

Camera::Camera(int xC, int yC, float s_scale)
{
	xClient = xC;
	yClient = yC;
	scale = s_scale;
}
Camera::~Camera()
{

}

void Camera::set_scale(float new_scale)
{
	scale = new_scale;
}


int Camera::Left()
{
	return position.x - xClient / 2;
}

int Camera::Right()
{
	return position.x + xClient / 2;
}

int Camera::Top()
{
	return position.y + xClient / 2;
}

int Camera::Buttom()
{
	return position.y - xClient / 2;
}