
#include "Game.h"

int main()
{
	Game Save_Ocean(50, 50, 1440, 720);
	Save_Ocean.oc_GameInit();
	while (1)
	{
		IMAGE ready;
		HWND oc_hWnd = GetHWnd();
		IMAGE an;
		POINT pt;
		loadimage(&ready, L".\\资源文件\\开始界面.png", 1300, 900, false);
		//bar(462, 353, 870, 455);//开始按钮位置
		GetCursorPos(&pt);//检取光标的位置，以屏幕坐标表示
		ScreenToClient(oc_hWnd, &pt);//该函数把屏幕上指定点的屏幕坐标转换成用户坐标
		if (pt.x > 462 && pt.x < 870 && pt.y>353 && pt.y < 455)
		{
			loadimage(&an, L".\\资源文件\\开始界面2.png", 408, 102, false);
		}
		putimage(50, 0, &ready);
		putimage(462, 353, &an);
		static bool last = 0;
		bool now = is_key_down(VK_LBUTTON);
		if (!last&&now)//判断是鼠标左键是否按下
		{
			Vect2 mou = GetMousePos(oc_hWnd);
			if (mou.x > 462 && mou.x < 870 && mou.y>353 && mou.y < 455)
			{
				break;
			}
		}
	}

	Save_Ocean.oc_GameLoop(); //主循环
	return 0;
}
