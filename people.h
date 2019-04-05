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

	void stand();
	void walk(int way);
	void run(int way);
	void jump();

private:
	std::vector<IMAGE> walk_frame;			//ÐÐ×ßÖ¡¶¯»­
};