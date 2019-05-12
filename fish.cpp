#include "fish.h"

Fish::Fish()
{
	img_source.push_back(swim);
	img_source.push_back(swim_mask);
	is_shine = false;
	now_state = null;
	last_state = null;
	frame_i = 0;
	now_source = sou_swim;
}

Fish::~Fish()
{

}

void Fish::Update(float dt)
{
	static int frame_timer = 0;

	if (now_state != last_state)
	{
		frame_timer = 0;
		frame_i = 0;
		switch (now_state)
		{

		default:
			break;
		}
	}
	
	frame_timer += dt;
	frame_dt = 300;
	frame_i = (frame_i + frame_timer / frame_dt) % img_source[now_source].size();
	frame_timer = frame_timer % frame_dt;

	physical_Move(dt);

	if (is_shine)
	{
		light.position = position + Vect2(0, 20);
		light.Update(dt);
	}
}

void Fish::Draw()
{

}

void Fish::DrawInCamera(const Camera &cam)
{

	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source + 1][frame_i], SRCAND);

	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source][frame_i], SRCPAINT);

	if (is_shine)
	{
		light.DrawInCamera(cam);
	}
}

void Fish::load_frame(source s, IMAGE img, IMAGE mask)
{
	img_source[s].push_back(img);
	img_source[s + 1].push_back(mask);
}

void Fish::set_state(state s)
{
	now_state = s;
}

void Fish::set_score(int s)
{
	score = s;
}
int Fish::get_score()
{
	return score;
}

void Fish::shine()
{
	is_shine = true;
	wchar_t sourse_file_name[50];
	for (int i = 0; i < 2; i++)
	{
		IMAGE img_t, img_mask;
		swprintf(sourse_file_name, 50, L".\\资源文件\\light\\0\\light_%d.png", i);
		loadimage(&img_t, sourse_file_name, 20, 20, false);
		swprintf(sourse_file_name, 50, L".\\资源文件\\light\\0\\light_%d_mask.png", i);
		loadimage(&img_mask, sourse_file_name, 20, 20, false);
		light.load_frame(Light::sou_fly, img_t, img_mask);
	}
	light.fish_id = type;
	light.position = position + Vect2(0, 20);
}