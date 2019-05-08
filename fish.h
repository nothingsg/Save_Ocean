#pragma once
#include "GameObject.h"

class Fish : public GameObject_phy
{
public:
	Fish();
	~Fish();
	
	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;
	
	enum fish_type
	{
		one = 0,
		two,
		three,
		four,
		total_fish_type
	};

	enum state
	{
		null
	};

	enum source
	{
		sou_swim = 0,			//250*100
		sou_swim_mask
	};

	void load_frame(source s, IMAGE img, IMAGE mask);
	void set_state(state s);

private:
	state now_state, last_state;
	source now_source;
	int frame_i;


	std::vector<std::vector<IMAGE>> img_source;	//存放所有图片资源


	std::vector<IMAGE> swim;
	std::vector<IMAGE> swim_mask;
};