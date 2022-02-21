#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"

void Player::start()
{
	Actor::start();

	
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/player.png")));

	//Set spawn point 
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	//adds in the direction from player input into a move direction
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//if the velocity is greater than 0, the transform will move according to the move direction
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		getTransform()->setForward(m_moveComponent->getVelocity());

	m_moveComponent->setVelocity(moveDirection * 500);
}
