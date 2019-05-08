#include"mywindow.h"


window::window(int x0,int y0,int x, int y)
{
	red_x = x0;
	red_y = y0;
	new_x = x;
	new_y = y;
}




void window::show()
{
	putimage(red_x, red_y, &img_i);//绘制新窗口的起始位置
}

/*
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

}*/