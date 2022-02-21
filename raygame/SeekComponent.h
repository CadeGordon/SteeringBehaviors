#pragma once
#include "Component.h"
class SeekComponent :
	public Component
{
public:
	void update(float deltaTime) override;

	float seekForce = 30;

private:

};

