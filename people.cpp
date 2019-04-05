#include "people.h"

People::People()
{
	walk_i = 0;
}

People::~People()
{

}
//stand_frame

void People::Update(float dt)
{
	static int frame_timer = 0;
	frame_timer += dt;
	if (frame_timer >= 100)
	{
		walk_i = (walk_i + 1) % walk_R_frame.size();
		frame_timer = 0;
	}
	
}


void People::Draw()
{
	
}

void People::DrawInCamera(const Camera &cam)
{

	putimage(position.x - cam.position.x + cam.xClient / 2 - 30,
		-(position.y - cam.position.y) + cam.yClient / 2 - 40,
		&walk_R_frame_mask[walk_i], SRCAND);

	putimage(position.x - cam.position.x + cam.xClient / 2 - 30,
		-(position.y - cam.position.y) + cam.yClient / 2 - 40,
		&walk_R_frame[walk_i], SRCPAINT);
}

void People::load_frame()
{
	IMAGE img_t;
	loadimage(&img_t, L".\\资源文件\\测试用\\runL-1.bmp", 60, 80, false);
	walk_R_frame.push_back(img_t);
	loadimage(&img_t, L".\\资源文件\\测试用\\runL-2.bmp", 60, 80, false);
	walk_R_frame.push_back(img_t);
	loadimage(&img_t, L".\\资源文件\\测试用\\runL-3.bmp", 60, 80, false);
	walk_R_frame.push_back(img_t);
	loadimage(&img_t, L".\\资源文件\\测试用\\runL-4.bmp", 60, 80, false);
	walk_R_frame.push_back(img_t);

	loadimage(&img_t, L".\\资源文件\\测试用\\runL-1X.bmp", 60, 80, false);
	walk_R_frame_mask.push_back(img_t);
	loadimage(&img_t, L".\\资源文件\\测试用\\runL-2X.bmp", 60, 80, false);
	walk_R_frame_mask.push_back(img_t);
	loadimage(&img_t, L".\\资源文件\\测试用\\runL-3X.bmp", 60, 80, false);
	walk_R_frame_mask.push_back(img_t);
	loadimage(&img_t, L".\\资源文件\\测试用\\runL-4X.bmp", 60, 80, false);
	walk_R_frame_mask.push_back(img_t);

}

void People::stand()
{

}

void People::walk_R()
{

}

void People::walk_L()
{

}

void People::run_R()
{

}

void People::run_L()
{

}

void People::jump()
{

}

