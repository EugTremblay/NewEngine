#pragma once
#include "Entity.h"
#include "IScene.h"

class IWorld {
public:
    virtual Entity* Find(std::string name) = 0;
    virtual void Add(Entity* ent) = 0;
    virtual void Remove(Entity* ent) = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;

    virtual void Load(std::string scene) = 0;
    virtual void UnLoad() = 0;
    virtual void Register(std::string name, IScene* scene) = 0;


};