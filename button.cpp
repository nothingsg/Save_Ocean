#include "button.h"
//#include "control.h"



Button::Button(int left, int top, int weight, int height)
{
	lt_x = left;
	lt_y = top;
	rb_x = left+weight;
	rb_y = top+height;
}


void Button::draw()
{
	bar(lt_x,lt_y,rb_x,rb_y);
}


void Button::drawchange()
{
	
}


