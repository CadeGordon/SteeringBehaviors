#include "Agent.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"

void Agent::start()
{
	m_moveComponent = addComponent<MoveComponent>();
}

void Agent::update(float deltaTime)
{
	//Get all force being applied from steering behaviors
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}

	//Clamp froce if it exceeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}

	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() = m_force * deltaTime);
}

void Agent::onAddComponent(Component* component)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(component);
	if (steeringComponent)
		m_steeringComponents.addItem(steeringComponent);
}


