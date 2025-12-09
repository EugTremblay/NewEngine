#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Sprite.h"
/// <summary>
/// Ennemy Component, simple move logic
/// </summary>
class Ennemy : public Component, public IUpdatable {
public:
	virtual ~Ennemy() = default;
	Ennemy(Entity* ent);
	Ennemy(const Ennemy& other, Entity* newParent);

	virtual void Update(float dt) override;
	//virtual void Draw() override;
	Component* Clone(Entity* newParent) const  override;

private:
	bool m_IsGoingRight;
	bool m_IsGoingLeft;
};