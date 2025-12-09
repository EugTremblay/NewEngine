#pragma once
#include "WorldService.h"

Entity* WorldService::Find(std::string name)
{
    if (m_EntityMap.count(name) > 0) {
        return m_EntityMap[name];
    }

    return nullptr;

}

WorldService::~WorldService()
{
    for (auto c : m_Scenes)
    {
        delete c.second;
    }
    m_Scenes.clear();
}

void WorldService::Add(Entity* ent)
{
    m_EntityWaitList.emplace_back(ent);
    //m_EntityInWorld.emplace_back(ent);
    m_EntityMap.emplace(ent->GetName(), ent);
}

Entity* WorldService::Create(std::string name)
{
    Entity* ent = new Entity(name);
    Add(ent);
    return ent;
}

void WorldService::Remove(Entity* ent){

    m_EntityRemoveList.emplace_back(ent);

   
}

void WorldService::Update(float dt)
{
    for (auto entity : m_EntityWaitList) {
        m_EntityInWorld.emplace_back(entity);
     
    }

    m_EntityWaitList.clear();

    for (auto entity : m_EntityInWorld) {
        if(entity->m_IsActive){
            entity->Update(dt);
        }
    }

    //faire update physics

    for (auto it : m_EntityRemoveList) {

        m_EntityInWorld.erase(std::remove(m_EntityInWorld.begin(), m_EntityInWorld.end(), it), m_EntityInWorld.end());
   
    }
    m_EntityRemoveList.clear();
}


void WorldService::Draw()
{
    for (auto entity : m_EntityInWorld) {
        if (entity->m_IsActive) {
            entity->Draw();
        }
    }
}

void WorldService::UnLoad()
{
    if (m_CurrentScene != nullptr) {
        for (auto entity : m_EntityInWorld) {
            entity->Destroy();
            delete entity;
        }
        m_EntityInWorld.clear();
        m_EntityMap.clear();
    }

}

void WorldService::Load(std::string scene)
{
    if (m_Scenes.count(scene) > 0) {
        UnLoad();
        m_CurrentScene = m_Scenes[scene];
        //cause probleme a cause du wait list, list empty donc no start
        m_CurrentScene->Load();
        for (auto entity : m_EntityInWorld)
        {
            if (entity->m_IsActive)
            {
                entity->Start();
            }
        }
        
    }

}



void WorldService::Register(std::string name, IScene* scene)
{
    if (m_Scenes.count(name) == 0) {
        m_Scenes[name] = scene;
    }

}
