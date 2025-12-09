#include "MainMenu.h"
#include"Entity.h"
#include"Sprite.h"
#include "Text.h"
#include "SceneChanger.h"


void MainMenu :: Load(){
   
    Entity* backGround = homer::Engine::Get().World()->Create("BackGround");
    Sprite* backGroundSprite = backGround->AddComponent<Sprite>();
    backGroundSprite->LoadTexture("BackGround.png");
    backGround->SetX(0);
    backGround->SetY(0);
    backGround->SetW(800);
    backGround->SetH(800);


    Entity* logo = homer::Engine::Get().World()->Create("Logo");
    Sprite* logoSprite = logo->AddComponent<Sprite>();
    logoSprite->LoadTexture("Logo.png");
    logo->SetX(250);
    logo->SetY(0);
    logo->SetW(300);
    logo->SetH(300);



    Entity* sceneChange = homer::Engine::Get().World()->Create("SceneChange");
    Text* startText = sceneChange->AddComponent<Text>();
    startText->LoadFontt("Font.ttf", 50);
    startText->SetText("Press Space To Start !", 210, 350, Color::White);
    SceneChanger* changer = sceneChange->AddComponent<SceneChanger>();
    changer->NextScene("first");

    Entity* gameExit = homer::Engine::Get().World()->Create("SceneChange");
    Text* exitText = gameExit->AddComponent<Text>();
    exitText->LoadFontt("Font.ttf", 50);
    exitText->SetText("Press ESC To exit", 225, 450, Color::White);

    size_t music =  Engine::Get().Audio()->LoadMusic("MenuMusic.mp3");
    Engine::Get().Audio()->PlayMusic(music);

}