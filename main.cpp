
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
		//bar(462, 353, 870, 455);//��ʼ��ťλ��
		GetCursorPos(&pt);//��ȡ����λ�ã�����Ļ�����ʾ
		ScreenToClient(oc_hWnd, &pt);//�ú�������Ļ��ָ�������Ļ����ת�����û�����
		if (pt.x > 462 && pt.x < 870 && pt.y>353 && pt.y < 455)
		{
			loadimage(&an, L".\\��Դ�ļ�\\��ʼ����2.png", 408, 102, false);
		}
		putimage(50, 0, &ready);
		putimage(462, 353, &an);
		static bool last = 0;
		bool now = is_key_down(VK_LBUTTON);
		if (!last&&now)//�ж����������Ƿ���
		{
			Vect2 mou = GetMousePos(oc_hWnd);
			if (mou.x > 462 && mou.x < 870 && mou.y>353 && mou.y < 455)
			{
				break;
			}
		}
	}

	Save_Ocean.oc_GameLoop(); //��ѭ��
	return 0;
}
