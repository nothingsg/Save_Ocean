
#include "Game.h"

int main()
{
	Game Save_Ocean(50, 50, 1440, 720);
	Save_Ocean.oc_GameInit();
	while (1)
	{
		IMAGE ready;
		HWND oc_hWnd = GetHWnd();
		loadimage(&ready, L".\\��Դ�ļ�\\��ʼ����.png", 1300, 900, false);
		putimage(50, 0, &ready);
		//bar(400, 350, 940, 500);//��ʼ��ťλ��
		void FlushMouseMsgBuffer();//��������Ϣ������
		static bool last = 0;
		bool now = is_key_down(VK_LBUTTON);
		if (!last&&now)//�ж����������Ƿ���
		{
			Vect2 mou = GetMousePos(oc_hWnd);
			if (mou.x > 400 && mou.x < 940 && mou.y>350 && mou.y < 500)
			{
				break;
			}
		}
	}

	Save_Ocean.oc_GameLoop(); //��ѭ��
	return 0;
}
