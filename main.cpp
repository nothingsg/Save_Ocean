
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
		loadimage(&ready, L".\\��Դ�ļ�\\��ʼ����.png", 1300, 900, false);
		//bar(568, 397, 854, 475);//��ʼ��ťλ��
		GetCursorPos(&pt);//��ȡ����λ�ã�����Ļ�����ʾ
		ScreenToClient(oc_hWnd, &pt);//�ú�������Ļ��ָ�������Ļ����ת�����û�����
		if (pt.x > 568 && pt.x < 854 && pt.y>397 && pt.y < 475)
		{
			loadimage(&an, L".\\��Դ�ļ�\\��ʼ����2.png", 286, 78, false);
		}
		putimage(50, 0, &ready);
		putimage(568, 397, &an);
		static bool last = 0;
		bool now = is_key_down(VK_LBUTTON);
		if (!last&&now)//�ж����������Ƿ���
		{
			Vect2 mou = GetMousePos(oc_hWnd);
			if (mou.x > 568 && mou.x < 854 && mou.y>397 && mou.y < 474)
			{
				break;
			}
		}
	}

	Save_Ocean.oc_GameLoop(); //��ѭ��
	return 0;
}
