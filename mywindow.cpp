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
	bool y = 0;
	Button out(new_x + 280, 100, new_x + 300, 120, 3);
	out.draw(new_x + 280, 100, new_x + 300, 120, 3);

}


void window::upbutton()
{
	bool y = 0;
	Button up(310, 335, 350, 365, 3);
	up.draw(310, 335, 350, 365, 3);

}



void window::downbutton()
{
	bool y = 0;
	Button down(new_x + 250, 335, new_x + 290, 365, 3);
	down.draw(new_x + 250, 335, new_x + 290, 365, 3);

}