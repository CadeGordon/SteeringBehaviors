#include "MainScene.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"
#include "SeekEnemey.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");

	player->getTransform()->setScale({ 50,50 });
	addActor(player);

	Enemy* enemy = new Enemy(100, 100, "Enemy", player);

	enemy->getTransform()->setScale({ 50,50 });
	//addActor(enemy);

	SeekEnemey* seeker = new SeekEnemey(50, 50, "Seeker", player);

	seeker->getTransform()->setScale({ 50,50 });
	addActor(seeker);
}
