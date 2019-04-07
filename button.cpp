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


bool Button::leftmouse(bool last,bool now, HWND oc_hWnd)
{
	bool f=0;//f=true��ʾ������������ڰ�ť��Χ�ں�
	if (!last&&now)//�ж����������Ƿ���
		f = 1;
	if (!last&&now)//�ж����������Ƿ���
	{
		Vect2 moup = GetMousePos(oc_hWnd);
		if (moup.x > lt_x && moup.x < rb_x && moup.y>lt_y && moup.y < rb_y)//����������ڰ�ť��Χ��
			f = 1;
	}
	return f;
}


void Button::mousepos(HWND oc_hWnd)//����Ƿ������Ƿ��л�����
{
	bool y=0;//�����ж��Ƿ�ת������
	void FlushMouseMsgBuffer();//��������Ϣ������
	static bool last = 0;
	bool now = is_key_down(VK_LBUTTON);
	y = leftmouse(last, now,oc_hWnd);
	if (y)
	{
		drawchange();
	}
}