#include "Enemy.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"
#include "InputComponent.h"
#include <iostream>
#include "Engine.h"
#include "Transform2D.h"


void Enemy::start()
{
	Actor::start();

	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/enemy.png")));
	
	

	//Set spawn point 
	//Set move speed
	//Set position clamps
	//Set health
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	//according to the target's position, the enemy will move towards that position according to the enemy's position
	MathLibrary::Vector2 moveDirection = (m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition());
	m_moveComponent->setVelocity(moveDirection.getNormalized() * 200);

	for (int i = 0; i < getTransform()->getChildCount(); i++)
	{
		getTransform()->getChildren()[i]->rotate((PI * 1) * deltaTime);
	}



	////Add the new velocity to the old position to get the new position
	//MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;
}

void Enemy::onCollision(Actor* other)
{
	//when the enemy collides with bullet the enemy is removed 

	if (other->getName() == "Bullet")
	{
		Engine::destroy(other);
	}

}