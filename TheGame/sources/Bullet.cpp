#include "Bullet.h"
#include "Entity.h"

Bullet::Bullet(Entity* ent): Component(ent),m_Direction(0)
{
}

Bullet::Bullet(const Bullet& other, Entity* newParent) : Component(newParent), m_Direction(other.m_Direction)
{
}

void Bullet::SetDirection(int direction)
{
	m_Direction = direction;
}
void Bullet::Update(float dt)
{
	float y = m_Entity->GetY();
	y += -10.0f * m_Direction * dt;
	m_Entity->SetY(y);
}




Component* Bullet::Clone(Entity* newParent) const
{
	return new Bullet(*this, newParent);
}


