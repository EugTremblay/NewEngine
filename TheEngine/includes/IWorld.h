#pragma once
//#include "Entity.h"
#include <string>
#include "IScene.h"

class Entity;

class IWorld {
public:
    /// <summary>
    /// Returns the entity by name
    /// </summary>
    /// <param name="name"></param>
    /// <returns></returns>
    virtual Entity* Find(std::string name) = 0;
    /// <summary>
/// Adds an entity to the world
/// </summary>
/// <param name="ent"></param>
    virtual Entity* Create(std::string name) = 0;
    /// <summary>
    /// Removes an entity from the world
    /// </summary>
    /// <param name="ent"></param>
    virtual void Remove(Entity* ent) = 0;
    virtual void Update(float dt) = 0;
    virtual void Draw() = 0;
    /// <summary>
    /// Loads a specified scene
    /// </summary>
    /// <param name="scene"></param>
    virtual void Load(std::string scene) = 0;
    /// <summary>
    /// Unloads the current scene and all of its entitys
    /// </summary>
    virtual void UnLoad() = 0;
    /// <summary>
    /// Registers the scenes at the begining, before the start of the engine loop
    /// </summary>
    /// <param name="name"></param>
    /// <param name="scene"></param>
    virtual void Register(std::string name, IScene* scene) = 0;

    /// <summary>
    /// Adds an entity to the world
    /// </summary>
    /// <param name="ent"></param>
    virtual void Add(Entity* ent) = 0;
    virtual ~IWorld() = default;
protected:

};