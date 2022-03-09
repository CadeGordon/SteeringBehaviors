#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class MoveComponent;
class Agent;

class SeekComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

