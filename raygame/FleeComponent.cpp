#include "FleeComponent.h"
#include "Transform2D.h"
#include "Actor.h"

FleeComponent::FleeComponent(Actor* target, const char* name)
{
	m_target = target;
	m_maxSpeed = 300;
	m_currentVelocity = MathLibrary::Vector2{ 0,0 };
}

void FleeComponent::update(float deltaTime)
{
	Component::update(deltaTime);

	m_desiredVelocity = MathLibrary::Vector2(getTarget()->getTransform()->getWorldPosition() + getOwner()->getTransform()->getWorldPosition()).normalize() * m_maxSpeed;

	m_steeringForce = m_desiredVelocity - m_currentVelocity;

	m_currentVelocity = m_currentVelocity + (m_steeringForce * deltaTime);

	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getWorldPosition();

	newPosition = newPosition + (m_currentVelocity * deltaTime);


	getOwner()->getTransform()->setWorldPostion(newPosition);
}
