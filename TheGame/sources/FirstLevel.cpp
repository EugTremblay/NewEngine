#include "FirstLevel.h"
#include"Entity.h"
#include"Sprite.h"
#include "Spawner.h"
#include "SceneChanger.h"
#include "PlayerController.h"
#include "Text.h"
#include "Ennemy.h"
#include "Bullet.h"
#include "EnnemyManager.h"

void FirstLevel::Load() {
  
    //Prefabs

    Entity* ennemy = homer::Engine::Get().World()->Create("ennemy");
    Ennemy* ennemyComp = ennemy->AddComponent<Ennemy>();
    Sprite* ennemySprite = ennemy->AddComponent<Sprite>();
    ennemySprite->FlipTexture(Flip{ true,true });
    ennemySprite->LoadTexture("Ennemy.png");
    ennemy->SetX(0);
    ennemy->SetY(0);
    ennemy->SetW(50);
    ennemy->SetH(50);

    Entity* bullet = homer::Engine::Get().World()->Create("bullet");
    Bullet* bulletComp = bullet->AddComponent<Bullet>();
    Sprite* bulletSprite = bullet->AddComponent<Sprite>();
    bulletComp->SetDirection(1);
    bulletSprite->LoadTexture("Bullet.png");
    bullet->SetX(300);
    bullet->SetY(300);
    bullet->SetW(20);
    bullet->SetH(20);

    //backGround

    Entity* backGround = homer::Engine::Get().World()->Create("BackGround");
    Sprite* backGroundSprite = backGround->AddComponent<Sprite>();
    backGroundSprite->LoadTexture("BackGround.png");
    backGround->SetX(0);
    backGround->SetY(0);
    backGround->SetW(800);
    backGround->SetH(800);

    //PLayer

    Entity* player = homer::Engine::Get().World()->Create("Player");
    Sprite* playerSprite = player->AddComponent<Sprite>();
    Spawner* pSpwan = player->AddComponent<Spawner>();
    playerSprite->LoadTexture("SpaceShip.png");
    player->SetX(300);
    player->SetY(500);
    player->SetW(50);
    player->SetH(50);
    PlayerController* controller = player->AddComponent<PlayerController>();

    //Ennemy Manager

    Entity* ennemyManager = homer::Engine::Get().World()->Create("ennemyManager");
    ennemyManager->SetX(0);
    ennemyManager->SetY(0);
    Spawner* eSpawn = ennemyManager->AddComponent<Spawner>();
    EnnemyManager* manager = ennemyManager->AddComponent<EnnemyManager>();


   

    

    bullet->SetActive(false);
    pSpwan->AddPrototype("baseBullet", bullet);
    ennemy->SetActive(false);
    eSpawn->AddPrototype("baseEnnemy", ennemy);


   




    //Text

    Entity* currentScore = homer::Engine::Get().World()->Create("CurrentScore");
    Text* scoreText = currentScore->AddComponent<Text>();
    scoreText->LoadFontt("Font.ttf", 50);
    scoreText->SetText("Score", 300, 0, Color::Red);

    Entity* currentScoreValue = homer::Engine::Get().World()->Create("SceneChange");
    Text* valueText = currentScoreValue->AddComponent<Text>();
    valueText->LoadFontt("Font.ttf", 50);
    valueText->SetText("0000000", 250, 50, Color::White);

}
