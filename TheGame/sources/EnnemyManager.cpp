#include "EnnemyManager.h"
#include "Entity.h"
#include "Spawner.h"
EnnemyManager::EnnemyManager(Entity* ent) : Component(ent),m_Spawner(nullptr)
{
	m_Spawner = m_Entity->GetComponent<Spawner>();
}

EnnemyManager::EnnemyManager(const EnnemyManager& other, Entity* newParent): Component(newParent), m_Spawner(other.m_Spawner)
{
}

void EnnemyManager::Start()
{
}
float elapsed = 0.0f;
float interval = 100.0f;

void EnnemyManager::Update(float dt)
{
	elapsed += dt;
	if (elapsed >= interval)
	{
		Entity* ennemy = m_Spawner->Spawn("baseEnnemy");
		ennemy->SetX(this->m_Entity->GetX());
		ennemy->SetY(this->m_Entity->GetY());
		elapsed = 0.0f;
		interval -= 5.0f;
	}
	if (interval <= 50.0f)
	{
		interval = 100.0f;
	}
}

Component* EnnemyManager::Clone(Entity* newParent) const
{
	return new EnnemyManager (*this,newParent);
}
