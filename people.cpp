#include "people.h"

People::People()
{
	frame_i = 0;
	state = stand_L;
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
		frame_i = (frame_i + 1) % walk_R_frame.size();
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
		&walk_R_frame_mask[frame_i], SRCAND);

	putimage(position.x - cam.position.x + cam.xClient / 2 - 30,
		-(position.y - cam.position.y) + cam.yClient / 2 - 40,
		&walk_R_frame[frame_i], SRCPAINT);
}





void People::load_frame(people_state s, IMAGE img, IMAGE mask)
{

	switch (s)
	{
	case People::stand_R:
		stand_R_frame.push_back(img);
		stand_R_frame_mask.push_back(mask);
		break;
	case People::stand_L:
		stand_L_frame.push_back(img);
		stand_L_frame_mask.push_back(mask);
		break;
	case People::walk_R:
		walk_R_frame.push_back(img);
		walk_R_frame_mask.push_back(mask);
		break;
	case People::walk_L:
		walk_L_frame.push_back(img);
		walk_L_frame_mask.push_back(mask);
		break;
	case People::run_R:
		run_R_frame.push_back(img);
		run_R_frame_mask.push_back(mask);
		break;
	case People::run_L:
		run_L_frame.push_back(img);
		run_L_frame_mask.push_back(mask);
		break;
	case People::jump_R:
		jump_R_frame.push_back(img);
		jump_R_frame_mask.push_back(mask);
		break;
	case People::jump_L:
		jump_L_frame.push_back(img);
		jump_L_frame_mask.push_back(mask);
		break;
	default:
		break;
	}

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


void People::set_state(people_state s)
{
	last_state = state;
	state = s;
	
}



