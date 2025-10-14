#pragma once
#include "IWorld.h"
#include <vector>
#include<map>
class WorldService : public IWorld {
public:
    virtual Entity* Find(std::string name) override;
    virtual void Add(Entity* ent) override;
    virtual void Remove(Entity* ent) override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    virtual void Load(std::string scene) override;
    virtual void UnLoad() override;
    virtual void Register(std::string name, IScene* scene) override;

private:
    std::vector<Entity*> m_EntityInWorld;
    std::map<std::string, Entity*> m_EntityMap;
    std::map<std::string, IScene*> m_Scenes;
    IScene* m_CurrentScene;
};