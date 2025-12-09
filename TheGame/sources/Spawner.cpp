#include "Spawner.h"
#include"Sprite.h"
#include "Ennemy.h"

Spawner::Spawner(Entity* ent):Component(ent), m_Prototypes{}
{
}
Spawner::Spawner(const Spawner& other, Entity* newParent) : Component(newParent)
{
}
//void Spawner::Update(float dt) {
//
//	if (Engine::Get().Input()->IsKeyDown(EKEY_RETURN))
//	{
//		Spawn("baseEnnemy");
//	}
//	//if (Engine::Get().Input()->IsKeyDown(EKEY_SPACE))
//	//{
//	//	Spawn("baseBullet");
//	//}
//}
//a changer
Component* Spawner::Clone(Entity* newParent) const
{
	return new Spawner(*this);
}


