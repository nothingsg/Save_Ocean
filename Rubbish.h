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


	enum rubbish_type
	{
		one = 0,
		two,
		three,
		four,
		total_rubbish_type
	};

	enum state
	{
		null
	};

	enum source
	{
		sou_float = 0,			//250*100
		sou_flaot_mask
	};

	void load_frame(source s, IMAGE img, IMAGE mask);
	void set_state(state s);
	void set_score(int s);
	int get_score();

private:
	state now_state, last_state;
	source now_source;
	int frame_i;
	int score;

	std::vector<std::vector<IMAGE>> img_source;	//存放所有图片资源


	std::vector<IMAGE> rfloat;
	std::vector<IMAGE> rfloat_mask;
};