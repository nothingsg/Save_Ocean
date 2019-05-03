#pragma once

#include "GameObject.h"
#define OC_LEFT 0
#define OC_RIGHT 1
class Hand : public GameObject_phy
{
public:
	Hand();
	~Hand();

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

	Vect2 start_pos;
	float arm_len;
	IMAGE hand, hand_mask;
	IMAGE arm, arm_mask;
};

class People : public GameObject_phy
{
public:
	People();
	~People();
	
	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

	enum state
	{
		sta_stand = 0,
		sta_standR,
		sta_standL,
		sta_walkR,
		sta_walkL,
		sta_runR,
		sta_runL,
		sta_jump,
		sta_jumpR,
		sta_jumpL,
		sta_catchR,
		sta_catchL,
		sta_boatingR,
		sta_boatingL
	};

	enum source
	{
		sou_stand_R = 0,
		sou_stand_R_mask,
		sou_stand_L,
		sou_stand_L_mask,
		sou_walk_R,
		sou_walk_R_mask,
		sou_walk_L,
		sou_walk_L_mask,
		sou_run_R,
		sou_run_R_mask,
		sou_run_L,
		sou_run_L_mask,
		sou_jump_R,
		sou_jump_R_mask,
		sou_jump_L,
		sou_jump_L_mask,
		sou_catch_R,
		sou_catch_R_mask,
		sou_catch_L,
		sou_catch_L_mask
	};

	void Catch();
	void Pull();

	void load_frame(source s, IMAGE img, IMAGE mask);
	void load_hand_img(IMAGE img, IMAGE mask);
	void load_arm_img(IMAGE img, IMAGE mask);
	void set_state(state s);
	state get_state();

	Vect2 get_hand_pos();
	float get_hand_len();
	
	//IMAGE hand, hand_mask;
private:
	state now_state, last_state;
	source now_source;
	int frame_i;


	Hand hand;

	std::vector<std::vector<IMAGE>> img_source;	//存放所有图片资源


	std::vector<IMAGE> stand_R_frame;			//站立向右帧动画
	std::vector<IMAGE> stand_R_frame_mask;		//站立向右帧动画掩码图
	std::vector<IMAGE> stand_L_frame;			//站立向左帧动画
	std::vector<IMAGE> stand_L_frame_mask;		//站立向左帧动画掩码图
	std::vector<IMAGE> walk_R_frame;			//行走向右帧动画
	std::vector<IMAGE> walk_R_frame_mask;		//行走向右帧动画掩码图
	std::vector<IMAGE> walk_L_frame;			//行走向左帧动画
	std::vector<IMAGE> walk_L_frame_mask;		//行走向左帧动画掩码图
	std::vector<IMAGE> run_R_frame;				//跑动向右帧动画
	std::vector<IMAGE> run_R_frame_mask;		//跑动向右帧动画掩码图
	std::vector<IMAGE> run_L_frame;				//跑动向左帧动画
	std::vector<IMAGE> run_L_frame_mask;		//跑动向左帧动画掩码图
	std::vector<IMAGE> jump_R_frame;			//跳跃向右帧动画
	std::vector<IMAGE> jump_R_frame_mask;		//跳跃向右帧动画掩码图
	std::vector<IMAGE> jump_L_frame;			//跳跃向左帧动画
	std::vector<IMAGE> jump_L_frame_mask;		//跳跃向左帧动画掩码图
	std::vector<IMAGE> catch_R_frame;			//抓取向右帧动画
	std::vector<IMAGE> catch_R_frame_mask;		//抓取向右帧动画掩码图
	std::vector<IMAGE> catch_L_frame;			//抓取向左帧动画
	std::vector<IMAGE> catch_L_frame_mask;		//抓取向左帧动画掩码图
	
	
};




