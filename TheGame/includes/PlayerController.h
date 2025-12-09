#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"
class Sprite;
class Spawner;
/// <summary>
/// Takes the player inputs and move the character
/// </summary>
class PlayerController : public Component, public IUpdatable, public IDrawable {
public:
	virtual ~PlayerController() = default;
	PlayerController(Entity* ent);
	PlayerController(const PlayerController& other, Entity* newParent);

	virtual void Start() override;
	virtual void Update(float dt);
	virtual void Draw();
	Component* Clone(Entity* newParent) const override;

private:
	Spawner* m_Spawner;
	size_t m_BulletSfx;
};