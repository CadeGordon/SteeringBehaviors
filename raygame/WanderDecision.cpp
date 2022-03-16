#include "WanderDecision.h"
#include "WanderComponent.h"
#include "Agent.h"
#include "SeekComponent.h"

void WanderDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderComponent* wander = agent->getComponent<WanderComponent>();
	SeekComponent* seek = agent->getComponent<SeekComponent>();

	if (wander)
		wander->setSteeringForce(300);

	if (seek)
		seek->setSteeringForce(0);
}
