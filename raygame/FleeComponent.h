#pragma once
#include "Component.h"
#include <Vector2.h>

class FleeComponent :
	public Component
{
public:
	FleeComponent(Actor* target, const char* name = "Flee Component");

	void setTarget(Actor* target) { m_target = target; }
	
	Actor* getTarget() { return m_target; }

	void update(float deltaTime) override;


private:
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_desiredVelocity;


	Actor* m_target;
	float m_maxSpeed;
};

