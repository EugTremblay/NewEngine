#pragma once
#include "Component.h"
#include "ICollideable.h"
class Collider : public Component, public ICollideable
{
	virtual void OnCollisionEnter(Entity* other) override;
};