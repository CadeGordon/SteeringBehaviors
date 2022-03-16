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
#include "Enemy.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");

	player->getTransform()->setScale({ 50,50 });
	addActor(player);

	Enemy* enemy = new Enemy(200, 300, "Enemy", 100, 100, player);

	Agent* agent = new Agent(50, 50, "Agent", 100, 50);
	

	addActor(player);
	addActor(enemy);
}
