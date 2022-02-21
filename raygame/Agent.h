#pragma once
#include "Actor.h"
class Agent :
	public Actor
{
public:
	Agent();
	~Agent();

	Actor* getTarget() { return m_target; }

private:
	Actor* m_target;

};

