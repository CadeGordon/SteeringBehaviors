#include "MainScene.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "WanderComponent.h"
#include"SeekComponent.h"
#include "StateMachineComponent.h"
#include "Actor.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");

	player->getTransform()->setScale({ 50,50 });
	addActor(player);



	Agent* agent = new Agent();
	agent->getTransform()->setScale({ 50,50 });
	agent->setMaxForce(1000);
	agent->addComponent(new SpriteComponent("images/enemy.png"));

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(100);
	seekComponent->setTarget(player);
	agent->addComponent(seekComponent);
	agent->addComponent<StateMachineComponent>();

	WanderComponent* wanderComponent = new WanderComponent(1000, 500, 300);
	agent->addComponent(wanderComponent);

	addActor(player);
	addActor(agent);
}
