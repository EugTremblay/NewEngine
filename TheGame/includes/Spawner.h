#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Entity.h"
#include <map>
#include <string>

typedef std::map<std::string, Entity*> TProtoMap;
/// <summary>
/// Component creates a super spawner, used to spawn prefabs
/// </summary>
class Spawner final : public Component {
public:
	virtual ~Spawner() = default;
	Spawner(Entity* ent);
    Spawner(const Spawner& other, Entity* newParent);

    Component* Clone(Entity* newParent) const override;
    /// <summary>
    /// Adds an entity to the prototype list. creates a "prefab"
    /// </summary>
    /// <param name="name"></param>
    /// <param name="proto"></param>
    void AddPrototype(const std::string& name, Entity* proto)
    {
        if (proto != nullptr)
        {
            m_Prototypes.insert({ name,proto });    
        }
    }
    /// <summary>
    /// spawns a entity "prefab" 
    /// </summary>
    /// <param name="name"></param>
    /// <returns></returns>
    Entity* Spawn(const std::string& name)
    {
        if (m_Prototypes.count(name) > 0)
        {
            return m_Prototypes[name]->Clone();
        }

        return nullptr;
    }


private:
    TProtoMap m_Prototypes;
};