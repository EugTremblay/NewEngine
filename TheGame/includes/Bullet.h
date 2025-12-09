#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "Sprite.h"
/// <summary>
/// Bullet component to add on proto
/// </summary>
class Bullet : public Component, public IUpdatable {
public:
    virtual ~Bullet() = default;
    Bullet(Entity* ent);
    Bullet(const Bullet& other, Entity* newParent);
    virtual void Update(float dt);
    /// <summary>
    /// Sets the direction of the bullet 1 == up and -1 == down
    /// </summary>
    /// <param name="direction"></param>
    virtual void SetDirection(int direction);

    Component* Clone(Entity* newParent) const override;
private:
    int m_Direction;

};