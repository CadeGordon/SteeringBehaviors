//#include "SeekComponent.h"
//#include "MoveComponent.h"
//#include <iostream>
//#include "Engine.h"
//#include "Transform2D.h"
//#include "Actor.h"
//
//void SeekComponent::start()
//{
//	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
//	m_moveComponent->setMaxSpeed(10);
//}
//
//void SeekComponent::update(float deltaTime)
//{
//	//according to the target's position, the enemy will move towards that position according to the enemy's position
//	MathLibrary::Vector2 moveDirection = (m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition());
//	m_moveComponent->setVelocity(moveDirection.getNormalized() * 200); 
//}

