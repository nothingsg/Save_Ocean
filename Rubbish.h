#pragma once

#include "GameObject.h"


class Rubbish : public GameObject_phy
{
public:
	Rubbish();
	~Rubbish();

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

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


	std::vector<std::vector<IMAGE>> img_source;	//�������ͼƬ��Դ


	std::vector<IMAGE> swim;
	std::vector<IMAGE> swim_mask;
};