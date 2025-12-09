#pragma once
#include "Component.h"
#include "IUpdatable.h"
/// <summary>
/// Component that trigger a scene change on Spacebar 
/// </summary>
class SceneChanger : public Component, public IUpdatable {
public:
	virtual ~SceneChanger() = default;
	SceneChanger(Entity* ent);
	SceneChanger(const SceneChanger& other, Entity* newParent);

	/// <summary>
	/// Sets the scene name 
	/// </summary>
	/// <param name="name"></param>
	virtual void NextScene(std::string name);
	virtual void Update(float dt);
	Component* Clone(Entity* newParent) const override;
private:
	std::string m_SceneName;
};