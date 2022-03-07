#include "FleeEnemy.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"
#include "FleeComponent.h"

void FleeEnemy::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));
	m_fleeComponent = dynamic_cast<FleeComponent*>(addComponent(new FleeComponent(m_target)));
}

void FleeEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}
