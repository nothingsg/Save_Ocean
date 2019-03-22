#include <graphics.h>
#include <iostream>

int main()
{
	initgraph(640, 480);   // 创建绘图窗口，大小为 640x480 像素
	circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
	circle(200, 100, 100);
	circle(300, 300, 200);  //21321351443
	circle(0, 0, 100);		//2132
	getchar();
	return 0;
}
