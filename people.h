#pragma once

#include "GameObject.h"

class People : public GameObject_phy
{
public:
	People();
	~People();


	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DrawInCamera(const Camera &cam) override;

};