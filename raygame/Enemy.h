#pragma once
#include "Agent.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "SpriteComponenet.h"


class Enemy :
	public Agent
{
public:
	Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target);
	void start() override;

	bool getTargetInRange();

	bool getTargetInSite();


	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

	bool getIsAggressive() { return m_isAggressive; }
	void setIsAggressive(bool value) { m_isAggressive = value; }

	bool getViewDistance() { return m_viewDistance; }
	void setViewDistance(bool value) { m_viewDistance = value; }

private:
	Actor* m_target;
	bool m_isAggressive;
	bool m_viewDistance;
};

