#pragma once
#include "Actor.h"

class SpriteComponent;
class SeekComponent;
class MoveComponent;

class FleeEnemy :
	public Actor
{
public:
	FleeEnemy(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }

	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_target;
	SpriteComponent* m_spriteComponent;
	SeekComponent* m_seekComponent;
	MoveComponent* m_moveComponent;
};
