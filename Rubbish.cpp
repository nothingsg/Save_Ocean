#include "Rubbish.h"


Rubbish::Rubbish()
{
	img_source.push_back(rfloat);
	img_source.push_back(rfloat_mask);
	now_state = null;
	last_state = null;
	frame_i = 0;
	now_source = sou_float;
}

Rubbish::~Rubbish()
{

}

void Rubbish::Update(float dt)
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
	frame_i = (frame_i + frame_timer / 200) % img_source[now_source].size();
	frame_timer = frame_timer % 200;

	physical_Move(dt);
}

void Rubbish::Draw()
{

}

void Rubbish::DrawInCamera(const Camera &cam)
{

	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source + 1][frame_i], SRCAND);

	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source][frame_i], SRCPAINT);
}

void Rubbish::load_frame(source s, IMAGE img, IMAGE mask)
{
	img_source[s].push_back(img);
	img_source[s + 1].push_back(mask);
}

void Rubbish::set_state(state s)
{
	now_state = s;
}

void Rubbish::set_score(float s)
{
	score = s;
}
int Rubbish::get_score()
{
	return score;
}