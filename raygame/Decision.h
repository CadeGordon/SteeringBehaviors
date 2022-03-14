#pragma once

class Agent;

/// <summary>
/// abstact class for all decisions
/// </summary>
class Decision
{
public:
	virtual void makeDecision(Agent* actor, float deltaTime) = 0;
};

