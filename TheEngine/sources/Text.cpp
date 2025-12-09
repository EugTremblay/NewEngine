#include "Text.h"
Text::Text(Entity* ent) :Component(ent),m_Id(0),m_Text(""), m_X(0), m_Y(0), m_Color(Color::White)
{

}
Text::Text(const Text& other, Entity* newParent) : Component(newParent), m_Color(other.m_Color)
{
	m_Id = other.m_Id;
	m_Text = other.m_Text;
	m_X = other.m_X;
	m_Y = other.m_Y;
	m_Color = other.m_Color;

}
void Text::LoadFontt(std::string fileName, int fontSize )
{
	m_Id = Engine::Get().Graphics()->LoadFont(fileName, fontSize);
}

void Text::SetText(std::string text, int x, int y, Color color)
{
	m_Text = text;
	m_X = x;
	m_Y = y;
	m_Color = color;
}

Component* Text::Clone(Entity* newParent) const
{
	return new Text(*this,newParent);
}


void Text::Draw()
{
	if (m_Id != NULL)
	{
		Engine::Get().Graphics()->DrawString(m_Text, m_Id, m_X, m_Y, m_Color);
	}
}

