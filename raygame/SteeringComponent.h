#pragma once
#include "Component.h"
#include <Vector2.h>

class SteeringComponent :
	public Component
{
public:
	SteeringComponent() { m_target = nullptr; m_steeringForce = 0; }
	SteeringComponent(Actor* actor, float steeringForce) { m_target = actor; m_steeringForce = steeringForce; }
	virtual MathLibrary::Vector2 calculateForce() = 0;
	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }
	float getSteeringForce() { return m_steeringForce; }

private:
	float m_steeringForce;
	Actor* m_target = nullptr;
};
