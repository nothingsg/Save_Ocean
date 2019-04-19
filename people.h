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
		sou_jump_L_mask
	};

	void load_frame(source s, IMAGE img, IMAGE mask);
	void set_state(state s);
	state get_state();
	

private:
	state now_state, last_state;
	source now_source;
	int frame_i;

	std::vector<std::vector<IMAGE>> img_source;	//�������ͼƬ��Դ


	std::vector<IMAGE> stand_R_frame;			//վ������֡����
	std::vector<IMAGE> stand_R_frame_mask;		//վ������֡��������ͼ
	std::vector<IMAGE> stand_L_frame;			//վ������֡����
	std::vector<IMAGE> stand_L_frame_mask;		//վ������֡��������ͼ
	std::vector<IMAGE> walk_R_frame;			//��������֡����
	std::vector<IMAGE> walk_R_frame_mask;		//��������֡��������ͼ
	std::vector<IMAGE> walk_L_frame;			//��������֡����
	std::vector<IMAGE> walk_L_frame_mask;		//��������֡��������ͼ
	std::vector<IMAGE> run_R_frame;				//�ܶ�����֡����
	std::vector<IMAGE> run_R_frame_mask;		//�ܶ�����֡��������ͼ
	std::vector<IMAGE> run_L_frame;				//�ܶ�����֡����
	std::vector<IMAGE> run_L_frame_mask;		//�ܶ�����֡��������ͼ
	std::vector<IMAGE> jump_R_frame;			//��Ծ����֡����
	std::vector<IMAGE> jump_R_frame_mask;		//��Ծ����֡��������ͼ
	std::vector<IMAGE> jump_L_frame;			//��Ծ����֡����
	std::vector<IMAGE> jump_L_frame_mask;		//��Ծ����֡��������ͼ
	std::vector<IMAGE> catch_R_frame;			//ץȡ����֡����
	std::vector<IMAGE> catch_R_frame_mask;		//ץȡ����֡��������ͼ
	std::vector<IMAGE> catch_L_frame;			//ץȡ����֡����
	std::vector<IMAGE> catch_L_frame_mask;		//ץȡ����֡��������ͼ
	IMAGE hand, hand_mask;
	
};