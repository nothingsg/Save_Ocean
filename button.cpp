#include"button.h"


Button::Button(int x1, int y1, int x2, int y2, int height)
{
	lt_x = x1;
	lt_y = y2;
	rb_x = x2;
	rb_y = y2;
	deep = height;
}


void Button::draw(int lt_x, int lt_y, int rb_x, int rb_y, int deep)
{
	bar3d(lt_x,lt_y,rb_x,rb_y,deep,true);

}


void Button::drawchange()
{
	
}


