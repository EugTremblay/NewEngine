#include "Sprite.h"
#include "Entity.h"
Sprite::Sprite(Entity* ent) :Component(ent), m_Id(0), m_Src{}, m_Dst{}, m_Angle(0.0f), m_Flip{}, m_Color(Color::White)
{
	
}

Sprite::Sprite(const Sprite& other, Entity* newParent) : Component(newParent), m_Color(other.m_Color)
{
	m_Id = other.m_Id;
	m_Src = other.m_Src;
	m_Dst = other.m_Dst;
	m_Angle = other.m_Angle;
	m_Flip = other.m_Flip;
}

void Sprite::SetRect(float x, float y, float w, float h)
{
	m_Dst = { x,y,w,h };
}

void Sprite::SetXY(float x, float y)
{
	m_Dst.x = x;
	m_Dst.y = y;
}

void Sprite::LoadTexture(std::string texture)
{
	m_Id = Engine::Get().Graphics()->LoadTexture(texture);
	if (m_Id != NULL)
	{
		Engine::Get().Graphics()->GetTextureSize(m_Id, &m_Src.w, &m_Src.h);
	}
}
void Sprite::FlipTexture(Flip textureFlip)
{
	m_Flip = textureFlip;
}
void Sprite::Draw()
{
	m_Dst.x = m_Entity->GetX();
	m_Dst.y = m_Entity->GetY();
	m_Dst.w = m_Entity->GetW();
	m_Dst.h = m_Entity->GetH();
	Engine::Get().Graphics()->DrawTexture(m_Id, m_Src, m_Dst, m_Angle, m_Flip, m_Color);
}

Component* Sprite::Clone(Entity* newParent) const
{
	return new Sprite(*this, newParent);
}


