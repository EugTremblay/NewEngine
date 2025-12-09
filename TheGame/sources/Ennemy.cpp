#include "Ennemy.h"
#include "Entity.h"


Ennemy::Ennemy(Entity* ent) :Component(ent), m_IsGoingRight(true),m_IsGoingLeft(false)
{
	
}

Ennemy::Ennemy(const Ennemy& other, Entity* newParent) : Component(newParent), m_IsGoingRight(other.m_IsGoingRight), m_IsGoingLeft(other.m_IsGoingLeft)
{
	
}


static bool isGoingLeft = false;
static bool isGoingRight = true;

void Ennemy::Update(float dt) {

	float x = m_Entity->GetX();
	float y = m_Entity->GetY();
	if (x < 750 && m_IsGoingRight) {
		x += 5.0f * dt;
	}
	else if (m_IsGoingRight)
	{
		//part en diagonale car modifie le x et y sans le else if 
		y += 75.0f * dt;
		m_IsGoingRight = false;
		m_IsGoingLeft = true;
	}
	if (x > 0 && m_IsGoingLeft) {
		x -= 5.0f * dt;
	}
	else if (m_IsGoingLeft)
	{
		y += 75.0f * dt;
		m_IsGoingLeft = false;
		m_IsGoingRight = true;
		//y += 100.0f;
	}
	m_Entity->SetX(x);
	m_Entity->SetY(y);
}

//void Ennemy::Draw()
//{
//	Sprite::Draw();
//}

Component* Ennemy::Clone(Entity* newParent) const
{
	return new Ennemy(*this,newParent);
}


