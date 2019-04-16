#include"boat.h"


Boat::Boat()
{
	img_source.push_back(boat_R_frame);
	img_source.push_back(boat_R_mask_frame);
	now_state = null;
	last_state = null;
	frame_i = 0;
	now_source = sou_boat_R;
}

Boat::~Boat()
{

}

void Boat::Update(float dt)
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
	frame_i = (frame_i + frame_timer / 500) % img_source[now_source].size();
	frame_timer = frame_timer % 500;

	last_state = now_state;

	physical_Move(dt);
}

void Boat::Draw()
{

}

void Boat::DrawInCamera(const Camera &cam)
{
	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source + 1][frame_i], SRCAND);

	putimage(position.x - cam.position.x + cam.xClient / 2 - img_source[now_source][frame_i].getwidth() / 2,
		-(position.y - cam.position.y) + cam.yClient / 2 - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source][frame_i], SRCPAINT);
}

void Boat::load_frame(source s, IMAGE img, IMAGE mask)
{
	img_source[s].push_back(img);
	img_source[s + 1].push_back(mask);
}

void Boat::set_state(state s)
{
	now_state = s;
}