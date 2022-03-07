#include "SeekComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"

SeekComponent::SeekComponent(Actor* target)
{
	Component::start();

	m_target = target;
	m_seekForce = 0.5f;
	m_maxSpeed = 5;
	m_currentVelocity = MathLibrary::Vector2{ 0,0 };
}

void SeekComponent::update(float deltaTime)
{
	Component::update(deltaTime);

	m_desiredVelocity = MathLibrary::Vector2(getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).normalize() * m_seekForce;

	m_steeringForce = m_desiredVelocity - m_currentVelocity;

	m_currentVelocity = m_currentVelocity + (m_steeringForce * deltaTime);

	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getWorldPosition();

	newPosition = newPosition + (m_currentVelocity * deltaTime);

	MoveComponent* moveComponent = dynamic_cast<MoveComponent*>(getOwner());

	getOwner()->getTransform()->setWorldPostion(newPosition);

}


