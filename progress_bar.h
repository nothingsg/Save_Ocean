#pragma once

#include "GameObject.h"


class progress_bar : public GameObject
{
public:
	progress_bar();
	~progress_bar();

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

	enum source
	{
		sou_in = 0,			
		sou_in_mask,
		sou_out,
		sou_out_mask
	};

	void load_frame(source s, IMAGE img, IMAGE mask);
	void set_progress(float p);

	float progress;

private:
	source now_source;
	int frame_i;

	std::vector<std::vector<IMAGE>> img_source;	//存放所有图片资源


	std::vector<IMAGE> in;
	std::vector<IMAGE> in_mask;
	std::vector<IMAGE> out;
	std::vector<IMAGE> out_mask;


};