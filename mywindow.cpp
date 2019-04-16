#include"mywindow.h"


window::window(int x, int y)
{
	new_x = x;
	new_y = y;
}




void window::show()
{
	putimage(300, 100, &img_i);//绘制新窗口的起始位置
}
void window::hide()
{

}


void window::outbutton()
{
	Button out(new_x + 280, 100, new_x + 300, 120);
	out.draw();
}


void window::upbutton()
{
	bool y = 0;
	Button up(310, 335, 350, 365);
	up.draw();

}



void window::downbutton()
{
	bool y = 0;
	Button down(new_x + 250, 335, new_x + 290, 365);
	down.draw();

}