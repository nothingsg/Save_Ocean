#pragma once

#include "GameObject.h"
#define OC_LEFT 0
#define OC_RIGHT 1

class People : public GameObject_phy
{
public:
	People();
	~People();
	
	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

	enum people_state
	{
		stand_R = 0,
		stand_L,
		walk_R,
		walk_L,
		run_R,
		run_L,
		jump_R,
		jump_L
	};

	void load_frame(people_state s, IMAGE img, IMAGE mask);
	void set_state(people_state s);

	

private:
	people_state state, last_state;
	int frame_i;

	std::vector<std::vector<IMAGE>> img_source;	//存放所有图片资源


	std::vector<IMAGE> stand_R_frame;
	std::vector<IMAGE> stand_R_frame_mask;
	std::vector<IMAGE> stand_L_frame;
	std::vector<IMAGE> stand_L_frame_mask;
	std::vector<IMAGE> walk_R_frame;			//行走帧动画
	std::vector<IMAGE> walk_R_frame_mask;		//行走帧动画掩码图
	std::vector<IMAGE> walk_L_frame;			//行走帧动画
	std::vector<IMAGE> walk_L_frame_mask;		//行走帧动画掩码图
	std::vector<IMAGE> run_R_frame;				//行走帧动画
	std::vector<IMAGE> run_R_frame_mask;		//行走帧动画掩码图
	std::vector<IMAGE> run_L_frame;				//行走帧动画
	std::vector<IMAGE> run_L_frame_mask;		//行走帧动画掩码图
	std::vector<IMAGE> jump_R_frame;				//行走帧动画
	std::vector<IMAGE> jump_R_frame_mask;			//行走帧动画掩码图
	std::vector<IMAGE> jump_L_frame;				//行走帧动画
	std::vector<IMAGE> jump_L_frame_mask;			//行走帧动画掩码图
	
};