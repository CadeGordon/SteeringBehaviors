#pragma once
#include "Actor.h"
#include "ActorArray.h"
#include <Vector2.h>
class MoveComponent;
class SteeringComponent;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed);
	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* component) override;
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float maxForce) { m_maxForce = maxForce; }
	MoveComponent* getMoveComponent() { return m_moveComponent; }

private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	float m_maxForce;
	MoveComponent* m_moveComponent;
	MathLibrary::Vector2 m_force;
};

