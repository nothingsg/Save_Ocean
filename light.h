#pragma once

#include "GameObject.h"



class Light : public GameObject_phy
{
public:
	Light();
	~Light();

	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;


	enum light_type
	{
		one = 0,
		/*two,
		three,
		four,*/
		total_rubbish_type
	};

	enum state
	{
		sta_follow = 0,
		sta_fly,
		sta_stop
	};

	enum source
	{
		sou_fly = 0,			//250*100
		sou_fly_mask
	};

	void load_frame(source s, IMAGE img, IMAGE mask);
	void set_state(state s);
	void set_score(int s);
	void fly_to(Vect2 O_pos, float v);
	int get_score();
	state get_state();
	int fish_id;

private:
	state now_state, last_state;
	source now_source;
	int frame_i;
	int score;
	Vect2 obj_pos;

	std::vector<std::vector<IMAGE>> img_source;	//存放所有图片资源


	std::vector<IMAGE> fly;
	std::vector<IMAGE> fly_mask;
};