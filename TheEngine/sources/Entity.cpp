#pragma once
#include "Entity.h"

Entity::Entity(std::string name):m_NumberOfClones(0),m_X(0),m_Y(0),m_W(0), m_H(0) {
	m_Name = name;
}
Entity::Entity(const Entity& other): m_NumberOfClones(other.m_NumberOfClones),m_X(other.m_X), m_Y(other.m_Y), m_W(other.m_W), m_H(other.m_H)
{
	m_Name = other.m_Name + std::to_string(other.m_NumberOfClones);
	
	for (auto it  : other.m_Components)
	{
		Component* clone = it.second->Clone(this);
		m_Components.emplace(it.first,clone);

		if (IUpdatable* updates = dynamic_cast<IUpdatable*>(clone))
		{
			m_Updates.push_back(updates);
		}
		if (IDrawable* drawables = dynamic_cast<IDrawable*>(clone))
		{
			m_Draws.push_back(drawables);
		}
		//add collide
	}
}
void Entity::Start() {

}
void Entity::Update(float dt) {
	for (auto c : m_Updates) {
		if (c != nullptr)
		{
			c->Update(dt);
		}
	}
}
void Entity::Draw() {
	for (auto c : m_Draws) {
		if (c != nullptr)
		{
			c->Draw();
		}
	}
}
void Entity::Destroy() {
	
		for (auto c = m_Components.begin(); c != m_Components.end(); ++c) {

			delete c->second;
		}
		m_Updates.clear();
		m_Draws.clear();
		m_Components.clear();
	
	
	
	
	
	//delete(this);
}

 Entity* Entity::Clone()
{
	m_NumberOfClones ++;
	Entity* inst = new Entity(*this);
	Engine::Get().World()->Add(inst);
	return inst;
	
}


