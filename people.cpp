#include "people.h"

People::People()
{
	img_source.push_back(stand_R_frame);
	img_source.push_back(stand_R_frame_mask);
	img_source.push_back(stand_L_frame);
	img_source.push_back(stand_L_frame_mask);
	img_source.push_back(walk_R_frame);
	img_source.push_back(walk_R_frame_mask);
	img_source.push_back(walk_L_frame);
	img_source.push_back(walk_L_frame_mask);
	img_source.push_back(run_R_frame);
	img_source.push_back(run_R_frame_mask);
	img_source.push_back(run_L_frame);
	img_source.push_back(run_L_frame_mask);
	img_source.push_back(jump_R_frame);
	img_source.push_back(jump_R_frame_mask);
	img_source.push_back(jump_L_frame);
	img_source.push_back(jump_L_frame_mask);
	img_source.push_back(catch_L_frame);
	img_source.push_back(catch_L_frame_mask);

	frame_i = 0;
	now_state = sta_standR;
	last_state = sta_standR;
	now_source = sou_stand_R;
}

People::~People()
{

}
//stand_frame

void People::Update(float dt)
{
	static int frame_timer = 0;
	if (now_state != last_state)
	{
		frame_timer = 0;
		frame_i = 0;
		switch (now_state)
		{
		case People::sta_standR:now_source = sou_stand_R;
			break;
		case People::sta_standL:now_source = sou_stand_L;
			break;
		case People::sta_walkR:now_source = sou_walk_R;
			break;
		case People::sta_walkL:now_source = sou_walk_L;
			break;
		case People::sta_runR:now_source = sou_run_R;
			break;
		case People::sta_runL:now_source = sou_run_L;
			break;
		case People::sta_jumpR:now_source = sou_jump_R;
			break;
		case People::sta_jumpL:now_source = sou_jump_L;
			break;
		case People::sta_boatingR:now_source = sou_stand_R;
			break;
		case People::sta_boatingL:now_source = sou_stand_L;
			break;
		default:
			break;
		}
	}

	frame_timer += dt;
	frame_i = (frame_i + frame_timer / 100) % img_source[now_source].size();
	frame_timer = frame_timer % 100;

	last_state = now_state;

	physical_Move(dt);
}


void People::Draw()
{
	
}

void People::DrawInCamera(const Camera &cam)
{

	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source + 1][frame_i], SRCAND);

	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source][frame_i], SRCPAINT);
}





void People::load_frame(source s, IMAGE img, IMAGE mask)
{

	img_source[s].push_back(img);		//载入图片和掩码图资源
	img_source[s + 1].push_back(mask);

	

}


void People::set_state(state s)
{
	if (s != sta_stand && s!= sta_jump)
	{
		now_state = s;
	}
	else if(s == sta_stand)
	{
		if (last_state == sta_runL || last_state == sta_jumpL)now_state = sta_standL;
		if (last_state == sta_runR || last_state == sta_jumpR)now_state = sta_standR;
	}
	else if (s == sta_jump) 
	{
		if (last_state == sta_runL || last_state == sta_standL)now_state = sta_jumpL;
		if (last_state == sta_runR || last_state == sta_standR)now_state = sta_jumpR;
	}
	
}

People::state People::get_state()
{
	return now_state;
}



