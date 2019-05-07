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
	img_source.push_back(catch_R_frame);
	img_source.push_back(catch_R_frame_mask);
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
		case People::sta_catchR:now_source = sou_catch_R;
			break;
		case People::sta_catchL:now_source = sou_catch_L;
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

	if (now_state == sta_catchR || now_state == sta_catchL)
	{
		hand.Update(dt);
	}
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

	if (now_state == sta_catchR || now_state == sta_catchL)
	{
		hand.DrawInCamera(cam);
	}
}

void People::Catch()
{
	now_state = sta_catchR;
	hand.position = position - Vect2(0, 18);
	hand.start_pos = hand.position;
	hand.velocity = Vect2(0, -1000);
	hand.acceleration = Vect2(0, 1000);
}

Vect2 People::get_hand_pos()
{
	return hand.position;
}

float People::get_hand_len()
{
	return hand.arm_len;
}


void People::load_frame(source s, IMAGE img, IMAGE mask)
{
	img_source[s].push_back(img);		//载入图片和掩码图资源
	img_source[s + 1].push_back(mask);
}


void People::load_hand_img(IMAGE img, IMAGE mask)
{
	hand.hand = img;
	hand.hand_mask = mask;
}

void People::load_arm_img(IMAGE img, IMAGE mask)
{
	hand.arm = img;
	hand.arm_mask = mask;
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



/*******************************Hand********************/


Hand::Hand()
{

}

Hand::~Hand()
{

}

void Hand::Update(float dt)
{
	physical_Move(dt);
	arm_len = (start_pos - position).vectorLength();
}

void Hand::Draw()
{

}

void Hand::DrawInCamera(const Camera &cam)
{
	/*putimage(position.x - cam.position.x + cam.xClient / 2 - hand_mask.getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - hand_mask.getheight() / 2,
		&hand_mask, SRCAND);

	putimage(position.x - cam.position.x + cam.xClient / 2 - hand.getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - hand.getheight() / 2,
		&hand, SRCPAINT);

	putimage(start_pos.x - cam.position.x + cam.xClient / 2 - hand_mask.getwidth() / 2,
		-(start_pos.y - cam.position.y - 68) + cam.yClient / 2 - hand_mask.getheight() / 2,
		60, (int)arm_len, &arm_mask, 0, 0, SRCAND);

	putimage(start_pos.x - cam.position.x + cam.xClient / 2 - hand.getwidth() / 2,
		-(start_pos.y - cam.position.y - 68) + cam.yClient / 2 - hand.getheight() / 2,
		60, (int)arm_len, &arm, 0, 0, SRCPAINT);*/


	/*************************************************************/
	putimage(start_pos.x - cam.position.x + cam.xClient / 2 - hand_mask.getwidth() / 2,
		-(start_pos.y - cam.position.y - 25) + cam.yClient / 2,
		60, arm_len, &hand_mask, -1, hand_mask.getheight() - arm_len, SRCAND);

	putimage(start_pos.x - cam.position.x + cam.xClient / 2 - hand.getwidth() / 2,
		-(start_pos.y - cam.position.y - 25) + cam.yClient / 2,
		60, arm_len, &hand, -1, hand.getheight() - arm_len, SRCPAINT);
}













