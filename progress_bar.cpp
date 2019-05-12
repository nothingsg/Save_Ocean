#include "progress_bar.h"


progress_bar::progress_bar()
{
	img_source.push_back(in);
	img_source.push_back(in_mask);
	img_source.push_back(out);
	img_source.push_back(out_mask);
	frame_i = 0;
	progress = 0;
	now_source = sou_in;
}

progress_bar::~progress_bar()
{

}

void progress_bar::Update(float dt)
{

}

void progress_bar::Draw()
{
	now_source = sou_out;
	putimage(position.x - img_source[now_source][frame_i].getwidth() / 2,
		position.y - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source + 1][frame_i], SRCAND);

	putimage(position.x - img_source[now_source][frame_i].getwidth() / 2,
		position.y - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source][frame_i], SRCPAINT);


	now_source = sou_in;
	putimage(position.x - img_source[now_source][frame_i].getwidth() / 2,
		position.y - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source + 1][frame_i], SRCAND);

	putimage(position.x - img_source[now_source][frame_i].getwidth() / 2,
		position.y - img_source[now_source][frame_i].getheight() / 2,
		&img_source[now_source][frame_i], SRCPAINT);
}

void progress_bar::DrawInCamera(const Camera &cam)
{

}


void progress_bar::load_frame(source s, IMAGE img, IMAGE mask)
{
	img_source[s].push_back(img);
	img_source[s + 1].push_back(mask);
}

void progress_bar::set_progress(float p)
{
	if (p < 0)return;
	progress = (p > 100) ? 100 : p;
}