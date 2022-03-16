#include "Enemy.h"
#include "StateMachineComponent.h"
#include "SpriteComponenet.h"
#include "Transform2D.h"
#include "Player.h"
#include "MoveComponent.h"
#include "IsAggressiveDecision.h"
#include "SeekDecision.h"
#include "IdleDecision.h"
#include "InRangeDecision.h"
#include "WanderDecision.h"
#include "DecisionComponent.h"

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Agent(x, y, name, maxForce, maxSpeed)
{
	m_target = target;
}

void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	IsAggressiveDecision* aggressive = new IsAggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggressive, seek);

	addComponent(new DecisionComponent(inRange));

	getTransform()->setScale({ 50,50 });
		
	setMaxForce(1000);
	addComponent(new SpriteComponent("images/enemy.png"));

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(100);
	seekComponent->setTarget(m_target);
	addComponent(seekComponent);

	
	WanderComponent* wanderComponent = new WanderComponent(1000, 500, 300);
	addComponent(wanderComponent);
}

bool Enemy::getTargetInRange()
{
	float distance = (m_target->getTransform()->getWorldPosition() - 
		getTransform()->getWorldPosition()).getMagnitude();

	return distance <= 100;
}

