#include "Camera.h"

Camera::Camera(int xC, int yC)
{
	xClient = xC;
	yClient = yC;
}
Camera::~Camera()
{

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