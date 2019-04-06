#pragma once

#include "GameObject.h"
#define OC_LEFT 0
#define OC_RIGHT 1

class People : public GameObject_phy
{
public:
	People();
	~People();
	//stand_frame
	
	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

	void load_frame();
	void stand();
	void walk_R();
	void walk_L();
	void run_R();
	void run_L();
	void jump();

private:
	
	std::vector<IMAGE> walk_R_frame;			//行走帧动画
	std::vector<IMAGE> walk_R_frame_mask;		//行走帧动画掩码图
	int walk_i;
};