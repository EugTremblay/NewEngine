#pragma once
#include "Component.h"
#include "IUpdatable.h"
class Sprite;
class Spawner;
/// <summary>
/// is used to spawn ennemys
/// </summary>
class EnnemyManager : public Component, public IUpdatable {
public:
	virtual ~EnnemyManager() = default;
	EnnemyManager(Entity* ent);
	EnnemyManager(const EnnemyManager& other, Entity* newParent);

	virtual void Start() override;
	virtual void Update(float dt);
	Component* Clone(Entity* newParent) const override;

private:
	Spawner* m_Spawner;
};