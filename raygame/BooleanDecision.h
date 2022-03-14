#pragma once
#include "Decision.h"

/// <summary>
/// A decision that has two children attached
/// </summary>
class BooleanDecision :
	public Decision
{
public:
	/// <summary>
	/// Checks the condition and transition to a different decision based on the return value
	/// </summary>
	/// <param name="agent">The agent that this decision tree is attached to</param>
	/// <param name="deltaTime">The ammount of time between frames</param>
	virtual void makeDecision(Agent* agent, float deltaTime) override;

	/// <summary>
	/// Checks if a certain conditon has been met and returns the result
	/// </summary>
	/// <param name="agent">The agent that this tree and returns is attached to </param>
	/// <param name="deltaTime">The amount of time between frames</param>
	/// <returns></returns>
	virtual bool checkCondition(Agent* agent, float deltaTime) { return false; }

	
	/// <param name="leftChild">left chidl of this node</param>
	/// <param name="rightChild">right child of this node</param>
	BooleanDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);

private:
	Decision* m_no;
	Decision* m_yes;
};

