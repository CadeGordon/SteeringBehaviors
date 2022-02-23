#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponent;
class Agent;

class SeekComponent :
	public Component
{
public:
	SeekComponent(Actor* target, const char* name = "Seek Component");

	void setTarget(Actor* target) { m_target = target; }
	Actor* getTarget() { return m_target; }

	void setForce(float force) { m_seekForce = force; }

	void setSpeed(float speed) { m_maxSpeed = speed; }

	void update(float deltaTime) override;


private:
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_desiredVelocity;


	Actor* m_target;
	float m_seekForce;
	float m_maxSpeed;

};

