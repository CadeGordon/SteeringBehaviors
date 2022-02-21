#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Transform2D.h"


class MoveComponent : public Component
{
public:
	MoveComponent(const char* name = "MoveComponent") : Component::Component(name) {}

	/// <summary>
	/// Get the current speed and direction of this actor
	/// </summary>
	/// <returns></returns>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	/// <summary>
	/// Set the current speed and directon of this actor
	/// </summary>
	/// <param name="velocity"></param>
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	/// <summary>
	/// gets the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <returns></returns>
	float getMaxSpeed() { return m_maxSpeed; }

	/// <summary>
	/// Set the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <param name="maxSpeed"></param>
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

	//Inherited from component class
	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	float m_maxSpeed;
	
	

};

