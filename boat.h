#pragma once

#include "GameObject.h"

class Boat : public GameObject_phy
{
public:
	Boat();
	~Boat();

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

	enum state
	{
		null
	};

	enum source
	{
		sou_boat_R = 0,
		sou_boat_R_mask
	};

	void load_frame(source s, IMAGE img, IMAGE mask);
	void set_state(state s);

private:
	state now_state, last_state;
	source now_source;
	int frame_i;


	std::vector<std::vector<IMAGE>> img_source;	//存放所有图片资源

	std::vector<IMAGE> boat_R_frame;
	std::vector<IMAGE> boat_R_mask_frame;

};