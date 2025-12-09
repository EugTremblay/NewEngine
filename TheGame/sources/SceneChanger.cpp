#include "SceneChanger.h"

SceneChanger::SceneChanger(Entity* ent) :Component(ent)
{

}
SceneChanger::SceneChanger(const SceneChanger& other, Entity* newParent) : Component(newParent)
{
	m_SceneName = other.m_SceneName;

}
void SceneChanger::NextScene(std::string name)
{
	m_SceneName = name;
}
void SceneChanger::Update(float dt)
{
	if (Engine::Get().Input()->IsKeyDown(EKEY_SPACE))
	{
		Engine::Get().World()->Load(m_SceneName);
	}
	if (Engine::Get().Input()->IsKeyDown(EKEY_ESCAPE))
	{
		Engine::Get().Exit();
	}
}

Component* SceneChanger::Clone(Entity* newParent) const
{
	return new SceneChanger(*this,newParent);
}


