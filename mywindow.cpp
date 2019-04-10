#include"mywindow.h"


window::window(int x, int y)
{
	new_x = x;
	new_y = y;
}




void window::show()
{
	putimage(300, 100, &img_i);
}
void window::hide()
{

}


bool window::outbutton()
{
	bool y = 0;
	Button out(new_x + 280, 100, new_x + 300, 120, 3);
	out.draw(new_x + 280, 100, new_x + 300, 120, 3);

	return y;
}

