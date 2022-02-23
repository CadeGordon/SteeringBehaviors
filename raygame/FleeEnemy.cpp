#include "FleeEnemy.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"

void FleeEnemy::start()
{
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/enemy.png")));
	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
}

void FleeEnemy::update(float deltaTime)
{
}
