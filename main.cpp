
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
		//bar(568, 397, 854, 475);//开始按钮位置
		GetCursorPos(&pt);//检取光标的位置，以屏幕坐标表示
		ScreenToClient(oc_hWnd, &pt);//该函数把屏幕上指定点的屏幕坐标转换成用户坐标
		if (pt.x > 568 && pt.x < 854 && pt.y>397 && pt.y < 475)
		{
			loadimage(&an, L".\\资源文件\\开始界面2.png", 286, 78, false);
		}
		putimage(50, 0, &ready);
		putimage(568, 397, &an);
		static bool last = 0;
		bool now = is_key_down(VK_LBUTTON);
		if (!last&&now)//判断是鼠标左键是否按下
		{
			Vect2 mou = GetMousePos(oc_hWnd);
			if (mou.x > 568 && mou.x < 854 && mou.y>397 && mou.y < 474)
			{
				break;
			}
		}
	}

	Save_Ocean.oc_GameLoop(); //主循环
	return 0;
}
