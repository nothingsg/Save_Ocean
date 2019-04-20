
#include "Game.h"

int main()
{
	Game Save_Ocean(50, 50, 1440, 720);
	Save_Ocean.oc_GameInit();
	while (1)
	{
		IMAGE ready;
		HWND oc_hWnd = GetHWnd();
		loadimage(&ready, L".\\资源文件\\开始界面.png", 1300, 900, false);
		putimage(50, 0, &ready);
		//bar(400, 350, 940, 500);//开始按钮位置
		void FlushMouseMsgBuffer();//清空鼠标消息缓冲区
		static bool last = 0;
		bool now = is_key_down(VK_LBUTTON);
		if (!last&&now)//判断是鼠标左键是否按下
		{
			Vect2 mou = GetMousePos(oc_hWnd);
			if (mou.x > 400 && mou.x < 940 && mou.y>350 && mou.y < 500)
			{
				break;
			}
		}
	}

	Save_Ocean.oc_GameLoop(); //主循环
	return 0;
}
