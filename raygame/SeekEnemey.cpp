#include "SeekEnemey.h"
#include "SpriteComponenet.h"
#include "SeekComponent.h"
#include "MoveComponent.h"

void SeekEnemey::start()
{
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/enemy.png")));
	m_seekComponent = dynamic_cast<SeekComponent*> (addComponent(new SeekComponent(m_target)));
	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
}

void SeekEnemey::update(float deltaTime)
{
	Actor::update(deltaTime);
}
